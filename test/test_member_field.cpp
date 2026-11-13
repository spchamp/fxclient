
#include <optional>
#include <string>
#include <type_traits>

#include <boost/assert/source_location.hpp>
#include <boost/current_function.hpp>
#include <boost/outcome/result.hpp>

#include <fxsupport/MemberField.hpp>

#include <catch2/catch_test_macros.hpp>

struct SimpleData {
    std::optional<std::string> value_a{std::nullopt};

    std::optional<bool> value_b{std::nullopt};

    std::optional<int> value_c{std::nullopt};
};

using namespace fxsupport;

TEST_CASE("MemberField access") {

    // test direct MeberField construction
    MemberField<SimpleData, std::string> fld_a{&SimpleData::value_a};

    // test field initialization with make_member_field(mb)
    auto fld_b = make_member_field(&SimpleData::value_b);

    // check field get() with non-const instance
    SimpleData that{.value_a = "QQ"};

    // check error construction with default result template
    {
        auto b_rs = fld_b.get(that);
        CHECK(!b_rs);
    }

    REQUIRE(fld_a.has_value(that));
    CHECK(fld_a.get(that).value() == "QQ");
    {
        auto vv = fld_a.get(that);
        REQUIRE(vv);
        CHECK(*vv == "QQ");
        // no effect on vv:
        CHECK(std::move(vv).value() == "QQ");
        CHECK(vv.has_value());
        CHECK(vv.value() == "QQ");
    }
    REQUIRE(fld_a.get(that));
    CHECK(*fld_a.get(that) == "QQ");

    // check with C-style pointer
    REQUIRE(fld_a.has_value(&that));
    CHECK(fld_a.get(&that)->data() == std::string_view{"QQ"});
    // FIXME also test with a smartptr

    // check clear and error construction
    fld_a.clear(that);
    CHECK(!fld_a.get(that));

    // check set
    fld_a.set(that, "RR");
    REQUIRE(fld_a.has_value(that));
    CHECK(fld_a.get(that) == "RR");
    // check emplace
    fld_a.emplace(that, "XY");
    REQUIRE(fld_a.has_value(that));
    CHECK(fld_a.get(that) == "XY");

    // check field get() with const reference
    SimpleData const& cthat = that;
    REQUIRE(fld_a.has_value(cthat));
    CHECK(fld_a.get(cthat) == "XY");
}
