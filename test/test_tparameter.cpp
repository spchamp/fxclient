// tests for the "new" tparameter template types

#include <coapp/lib/tparam/tparameter.hpp>

#include <catch2/catch_test_macros.hpp>

using namespace coapp::lib::tparam;

struct alt_test_param_0 : tparameter<alt_test_param_0> {};

struct alt_test_param_1 : tparameter<alt_test_param_1> {};

struct alt_test_param_2 : tparameter<alt_test_param_2> {};

/// non-tparameter type for template parameter packs under tests
struct alt_test_flag {};

template <typename... P> struct alt_test_pack {
  using opt_t0_default = int;
  using opt_t2_default = float;

  using opt_t0 = typename tparameter_optional<alt_test_param_0, opt_t0_default,
                                              P...>::type;

  using req_t1 = typename tparameter_required<alt_test_param_1, P...>::type;

  using opt_t2 = typename tparameter_optional<alt_test_param_2, opt_t2_default,
                                              P...>::type;
};

TEST_CASE("tparameter tests") {

  SECTION("tparameter concepts, type traits") {
    STATIC_CHECK(is_tparameter<alt_test_param_0>);
    STATIC_CHECK(!is_tparameter<alt_test_flag>);

    STATIC_CHECK(is_tparameter_binding<alt_test_param_0::bind<std::string>>);
    STATIC_CHECK(!is_tparameter_binding<std::true_type>);
    STATIC_CHECK(!is_tparameter_binding<alt_test_flag>);

    // FIXME there are more tparameter_bound_p tests, in a subsq. section

    STATIC_CHECK(tparameter_bound_p<alt_test_param_1,
                                    alt_test_param_1::bind<std::string>,
                                    alt_test_flag>::value);

    STATIC_CHECK(!tparameter_bound_p<alt_test_param_1,
                                     alt_test_param_2::bind<std::string>,
                                     alt_test_flag>::value);

    STATIC_CHECK(std::is_same_v<typename tparameter_bound_type<
                                    alt_test_param_1::bind<std::string>>::type,
                                std::string>);
    STATIC_CHECK(
        std::is_same_v<
            typename tparameter_bound_type<alt_test_param_1::bind<int>>::type,
            int>);

    // test not
    STATIC_CHECK(
        !std::is_same_v<
            typename tparameter_bound_type<alt_test_param_1::bind<int>>::type,
            std::string>);
  }

  SECTION("tparameter_resolve regression tests") {
    using test_resolve_op = tdetail::tparameter_resolve<
        alt_test_param_1, int, alt_test_param_1::bind<std::string>,
        alt_test_flag, alt_test_param_0::bind<float>>;

    // test tparameter_resolve<...>::provided_types
    STATIC_CHECK(std::is_same_v<
                 typename test_resolve_op::provided_types,
                 mpl::vector3<alt_test_param_1::bind<std::string>,
                              alt_test_flag, alt_test_param_0::bind<float>>>);

    // test the internal fold_op for individual members of the type set

    STATIC_CHECK(std::is_same_v<
                 typename test_resolve_op::fold_op<
                     std::string, alt_test_param_1::bind<std::string>>::type,
                 std::string>);

    STATIC_CHECK(
        std::is_same_v<typename test_resolve_op::fold_op<
                           std::string, alt_test_param_0::bind<float>>::type,
                       std::string>);

    STATIC_CHECK(
        std::is_same_v<
            typename test_resolve_op::fold_op<std::string, alt_test_flag>::type,
            std::string>);

    // test with an emulation of the mpl::fold op
    STATIC_CHECK(std::is_same_v<
                 mpl::fold<typename test_resolve_op::provided_types, float,
                           test_resolve_op::fold_op<mph::_1, mph::_2>>::type,
                 std::string>);

    // negative test for the mpl fold op
    STATIC_CHECK(!std::is_same_v<
                 mpl::fold<typename test_resolve_op::provided_types, float,
                           test_resolve_op::fold_op<mph::_1, mph::_2>>::type,
                 float>);

    STATIC_CHECK(std::is_same_v<typename test_resolve_op::type, std::string>);
  }

  SECTION("tparameter_bound_p") {

    STATIC_CHECK(
        tparameter_bound_p<alt_test_param_0,
                           alt_test_param_1::bind<std::string>, alt_test_flag,
                           alt_test_param_0::bind<char>>::value);

    // test without flag type in P...
    STATIC_CHECK(tparameter_bound_p<alt_test_param_0,
                                    alt_test_param_1::bind<std::string>,
                                    alt_test_param_0::bind<char>>::value);

    STATIC_CHECK(
        tparameter_bound_p<alt_test_param_1,
                           alt_test_param_1::bind<std::string>, alt_test_flag,
                           alt_test_param_0::bind<char>>::value);

    // test without flag type in P...
    STATIC_CHECK(tparameter_bound_p<alt_test_param_1,
                                    alt_test_param_1::bind<std::string>,
                                    alt_test_param_0::bind<char>>::value);

    STATIC_CHECK(
        !tparameter_bound_p<alt_test_param_2,
                            alt_test_param_1::bind<std::string>, alt_test_flag,
                            alt_test_param_0::bind<char>>::value);
  }

  SECTION("tparameter_present_p, tparameter_present_v") {
    STATIC_CHECK(!tparameter_present_p<alt_test_flag>::value);
    STATIC_CHECK(!tparameter_present_v<alt_test_flag>);

    STATIC_CHECK(
        tparameter_present_p<alt_test_flag, alt_test_param_1::bind<std::string>,
                             alt_test_flag>::value);
    STATIC_CHECK(
        tparameter_present_v<alt_test_flag, alt_test_param_1::bind<std::string>,
                             alt_test_flag>);

    STATIC_CHECK(
        tparameter_present_p<alt_test_param_1,
                             alt_test_param_1::bind<std::string>, alt_test_flag,
                             alt_test_param_0::bind<char>>::value);
    STATIC_CHECK(
        tparameter_present_v<alt_test_param_1,
                             alt_test_param_1::bind<std::string>, alt_test_flag,
                             alt_test_param_0::bind<char>>);
  }

  SECTION("Resolve optional, required template params") {
    using pack_t = alt_test_pack<alt_test_param_1::bind<std::string>,
                                 alt_test_flag, alt_test_param_0::bind<char>>;

    STATIC_CHECK(std::is_same_v<typename pack_t::opt_t0, char>);

    STATIC_CHECK(std::is_same_v<typename pack_t::opt_t2, float>);

    STATIC_CHECK(std::is_same_v<typename pack_t::req_t1, std::string>);
  }
}
