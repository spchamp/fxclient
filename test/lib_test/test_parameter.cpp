
#include <type_traits>

#include <boost/parameter/aux_/tagged_argument.hpp>
#include <boost/parameter/keyword.hpp>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>

#include <catch2/catch_test_macros.hpp>

#include <coapp/lib/param/parameter.hpp>
#include <coapp/lib/param/param_traits.hpp>
#include <coapp/lib/unspecified.hpp>

#include <coapp/lib/metatype/sequence_contains.hpp>
#include <coapp/lib/metatype/vector_simplify.hpp>

namespace mpl = boost::mpl;
namespace mph = boost::mpl::placeholders;

using namespace coapp::lib::param;

struct param_a : parameter<param_a, "param_a"> {};

struct param_b : parameter<param_b, "param_b", bparam::in_reference> {};

struct param_c : parameter<param_c, "param_c"> {};

struct param_d : parameter<param_d, "param_d", bparam::in_reference> {};

BOOST_PARAMETER_NAME((classic_param_a, ns_classic_param_tags) classic_param_a)
BOOST_PARAMETER_NAME((classic_param_b, ns_classic_param_tags) in(classic_param_b))

TEST_CASE("Parameter: Traits; Value access") {

    // using __ [[maybe_unused]] = param_a;  // formatting hack (clangd)

    SECTION("Regression Test: parameter traits") {
        STATIC_CHECK(param_a::tag::keyword_name() == param_a::name);
        STATIC_CHECK(param_b::tag::keyword_name() == param_b::name);
        STATIC_CHECK(param_c::tag::keyword_name() == param_c::name);
        STATIC_CHECK(param_d::tag::keyword_name() == param_d::name);

        STATIC_CHECK(!std::is_same_v<typename param_a::tag, param_b::tag>);
        STATIC_CHECK(!std::is_same_v<typename param_a::tag, param_c::tag>);
        STATIC_CHECK(!std::is_same_v<typename param_a::tag, param_d::tag>);

        STATIC_CHECK(std::is_same_v<typename param_a::tag::parameter, param_a>);
        STATIC_CHECK(
              std::is_same_v<typename param_a::tag::implementation, param_a::tag>);

        STATIC_CHECK(std::is_same_v<typename param_b::tag::parameter, param_b>);
        STATIC_CHECK(
              std::is_same_v<typename param_b::tag::implementation, param_b::tag>);

        STATIC_CHECK(std::is_same_v<typename param_c::tag::parameter, param_c>);
        STATIC_CHECK(
              std::is_same_v<typename param_c::tag::implementation, param_c::tag>);

        STATIC_CHECK(std::is_same_v<typename param_d::tag::parameter, param_d>);
        STATIC_CHECK(
              std::is_same_v<typename param_d::tag::implementation, param_d::tag>);

        // tests: type traits for parameter/tag reflection

        STATIC_CHECK(!std::is_same_v<param_a::tag, param_c::tag>);

        STATIC_CHECK(std::is_same_v<param_a, param_a::tag::parameter>);
        STATIC_CHECK(std::is_same_v<typename tag_param<typename param_a::tag>::type,
                                    param_a>);
        STATIC_CHECK(
              !std::is_same_v<typename tag_param<typename param_a::tag>::type,
                              typename tag_param<typename param_c::tag>::type>);

        // regression test: the parameter type for a "classic" boost parameter tag
        // is unspecified_t
        //
        // Known limitation: The concept of unspecified_t as representing an
        // "unspecified" type is largely paradoxical. In short, it represents a
        // sort of null case for purpose of type comparisons. Thus, the paradoxical
        // nature of this notation may seem to represent a normative part of the
        // type's identity.
        STATIC_CHECK(
              std::is_same_v<typename tag_param<typename ns_classic_param_tags::
                                                      classic_param_a>::type,
                             unspecified_t>);
    }

    SECTION("keyword absent") {
        auto args    = (classic_param_a = "abc");
        using pack_t = std::remove_cvref_t<decltype(args)>;

        // traits
        STATIC_CHECK(param_unspecified_p<pack_t, param_a::tag>::value);
        STATIC_CHECK(!param_a::bound_p<pack_t>::value);

        // value access
        CHECK(std::string_view{args[classic_param_a]} == "abc");
    }

    SECTION("keyword present, default qualifier (forward_reference") {
        SECTION("static check (traits)") {
            // The static type check does not require any access to the parameter
            // binding object or any parameters in the same, other than for
            // determining the type of the compiled binding expression.
            auto args    = (param_a::keyword = 12321,
                            classic_param_a  = std::string_view{"abc"},
                            param_c::keyword = 45654);
            using pack_t = std::remove_cvref_t<decltype(args)>;

            STATIC_CHECK(!param_unspecified_p<pack_t, param_a::tag>::value);
            STATIC_CHECK(param_a::bound_p<pack_t>::value);

            // regression test - traits (param_bound_t)
            STATIC_CHECK(
                  std::is_same_v<param_bound_t<pack_t, param_a::tag>, int const&>);
            STATIC_CHECK(
                  std::is_same_v<param_bound_t<pack_t, ns_classic_param_tags::
                                                             classic_param_a>,
                                 std::string_view&&>);
        }

        // In this case, for purpose of the param value tests, this test should be
        // performed directly onto the compiler's expansion of the parameter binding
        // expression (rather than on a reference to such expansion)
        //
        // With the forward_reference parameter qualifier, in effect the parameter
        // value may go out of scope outside of the immediate args[keyword]
        // accessor.
        //
        // This implementation would allow for an effective forwarding of each bound
        // parameter value, for a parameter tag using this qualifier.

        SECTION("param value checks") {
            CHECK((param_a::keyword = 12321, classic_param_a = "abc",
                   param_c::keyword = 45654)[param_a::keyword]
                  == 12321);
            CHECK(std::string_view{(param_a::keyword = 12321,
                                    classic_param_a  = "abc",
                                    param_c::keyword = 45654)[classic_param_a]}
                  == "abc");
        }
    }

    SECTION("keyword present, in_reference qualifier") {
        // in this case:
        // - the parameter values must denote references
        // - the parameter values will remain in scope ,
        //   outside of the immediate args[keyword] accessor
        // - the parameter value tests can be performed via
        //   a reference to a single binding expression
        int         ivalue_a{12321}, ivalue_d{45654};
        std::string svalue{"abc"};

        auto        args = (param_b::keyword = ivalue_a, classic_param_b = svalue,
                            param_d::keyword = ivalue_d);
        using pack_t     = std::remove_cvref_t<decltype(args)>;

        SECTION("static check (traits)") {
            STATIC_CHECK(!param_unspecified_p<pack_t, param_b::tag>::value);
            STATIC_CHECK(param_b::bound_p<pack_t>::value);

            // regression test - traits (param_bound_t)
            STATIC_CHECK(
                  std::is_same_v<param_bound_t<pack_t, param_b::tag>, int const&>);
            STATIC_CHECK(
                  std::is_same_v<param_bound_t<pack_t, ns_classic_param_tags::
                                                             classic_param_b>,
                                 std::string const&>);
        }

        SECTION("param value checks") {
            CHECK(args[param_b::keyword] == 12321);
            CHECK(&args[param_b::keyword] == &ivalue_a);

            CHECK(std::string_view{args[classic_param_b]} == "abc");
            CHECK(&args[classic_param_b] == &svalue);

            CHECK(args[param_d::keyword] == 45654);
            CHECK(&args[param_d::keyword] == &ivalue_d);
        }
    }
}

TEST_CASE("Parameter iteration") {

    auto tmp_pack = (param_a::keyword = 12321, param_b::keyword = "ABC");

    using pack_t  = std::remove_cvref_t<decltype(tmp_pack)>;

    SECTION("mpl::size for argument pack type") {
        STATIC_CHECK(mpl::size<pack_t>::value == 2u);
    }

    SECTION("vector of parameter tags from argument pack type") {
        using coapp::lib::metatype::vector_simplify;
        using coapp::lib::metatype::sequence_contains;

        using bparam::aux::tagged_argument;

        using param_tags = typename vector_simplify<typename mpl::fold<
              pack_t, mpl::vector0<>,
              mpl::joint_view<mph::_1, mpl::vector1<mph::_2>>
        >::type>::type;

        STATIC_CHECK(mpl::size<param_tags>::value == mpl::size<pack_t>::value);
        STATIC_CHECK(mpl::size<param_tags>::value == 2u);
        STATIC_CHECK(sequence_contains<param_tags, param_a::tag>);
        STATIC_CHECK(sequence_contains<param_tags, param_b::tag>);
        STATIC_CHECK(!sequence_contains<param_tags, param_c::tag>);
    }
}
