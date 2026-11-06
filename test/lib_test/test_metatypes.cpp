#include <cstddef>

#include <boost/mpl/at.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/range_c.hpp>

#include <catch2/catch_test_macros.hpp>

#include <coapp/lib/metatype/variant_derive.hpp>
#include <coapp/lib/metatype/sequence_contains.hpp>
#include <coapp/lib/metatype/set_theoretic.hpp>
#include <variant>

using namespace coapp::lib::metatype;

TEST_CASE("variant_derive") {
    using op_t = variant_derive<std::string, int, std::size_t, std::monostate, int,
                                std::monostate, std::string>;
    using types_in_t  = typename op_t::types_in;
    using types_out_t = typename op_t::types_out;

    // ensure every input type exists in the types_out vector
    mpl::for_each<mpl::range_c<std::size_t, 0u, mpl::size<types_in_t>::value>>(
          [](auto const& idx) {
              // some compilers may fail to proceses idx
              // as a constant expression. The type::value of
              // the value would be equivalent to the idx value
              // itself, definitively as a constant expression.
              using t_in = typename mpl::at_c<
                    types_in_t, std::remove_cvref_t<decltype(idx)>::value
              >::type;
              STATIC_CHECK(sequence_contains_op<types_out_t, t_in>::value);
          });

    STATIC_CHECK(std::is_same_v<typename mpl::at_c<types_out_t, 0u>::type,
                                std::monostate>);
    STATIC_CHECK(!sequence_contains<types_out_t, float>);
    STATIC_CHECK(sequence_contains<types_out_t, int>);
    STATIC_CHECK(sequence_contains<types_out_t, std::string>);
    STATIC_CHECK(sequence_contains<types_out_t, std::size_t>);
    STATIC_CHECK(sequence_contains<types_out_t, std::monostate>);
    STATIC_CHECK(mpl::size<types_out_t>::value == 4);

    // ensure every op_t::types_out is present within the constructed
    // variant type
    using variant_t = typename op_t::type;
    mpl::for_each<
          mpl::range_c<std::size_t, 0u, mpl::size<typename op_t::types_out>::value>
    >([](auto const& idx) noexcept {
        static constexpr std::size_t idxv =
              std::remove_cvref_t<decltype(idx)>::value;
        using t_out = typename mpl::at_c<op_t::types_out, idxv>::type;

        STATIC_CHECK(std::is_same_v<decltype(std::get<t_out>(
                                          std::declval<variant_t const&>())),
                                    t_out const&>);

        STATIC_CHECK(
              std::is_same_v<std::variant_alternative_t<idxv, variant_t>, t_out>);
    });
}

TEST_CASE("set theoretic metatypes") {

    using lhs_t = mpl::vector3<std::string, std::byte, bool>;
    using rhs_t = mpl::vector2<std::size_t, std::string>;

    SECTION("union_op") {
        using out_t = typename union_op<lhs_t, rhs_t>::type;
        STATIC_CHECK(mpl::size<out_t>::value == 4u);
        STATIC_CHECK(sequence_contains_op<out_t, std::string>::value);
        STATIC_CHECK(sequence_contains_op<out_t, std::byte>::value);
        STATIC_CHECK(sequence_contains_op<out_t, bool>::value);
        STATIC_CHECK(sequence_contains_op<out_t, std::size_t>::value);
    }

    SECTION("intersection_op") {
        using out_t = typename intersection_op<lhs_t, rhs_t>::type;
        STATIC_CHECK(mpl::size<out_t>::value == 1u);
        STATIC_CHECK(
              std::is_same_v<typename mpl::at_c<out_t, 0u>::type, std::string>);
    }

    SECTION("difference_op") {
        using out_t = typename difference_op<lhs_t, rhs_t>::type;
        STATIC_CHECK(mpl::size<out_t>::value == 2u);
        STATIC_CHECK(sequence_contains_op<out_t, std::byte>::value);
        STATIC_CHECK(sequence_contains_op<out_t, bool>::value);
    }
}
