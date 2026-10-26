// tests for LText

#include <coapp/lib/LText.hpp>

#include <catch2/catch_test_macros.hpp>
#include <string_view>
#include <type_traits>

using coapp::lib::LText;

template <LText Name>
struct LText_test_t {

    static constexpr auto name = Name;

    template <LText Prefix>
    static constexpr auto prepend() {
        return Name.prepend(Prefix.data);
    }

    template <LText Prefix>
    static constexpr auto prepend_typed() {
        using nxt_t = LText_test_t<Name.prepend(Prefix.data)>;
        return nxt_t{};
    }

    template <LText Suffix>
    static constexpr auto append() {
        return Name.append(Suffix.data);
    }
};

TEST_CASE("LText") {
    using test_t = LText_test_t<"Name">;

    SECTION("to_view") {
        CHECK(test_t::name.to_view() == std::string_view{"Name"});
    }

    SECTION("contains") {
        CHECK(test_t::name.contains('m'));
        CHECK(!test_t::name.contains('z'));

        using test_u = LText_test_t<"Nullified\0Name">;
        CHECK(decltype(test_u::name)::string_size_type::value
              == std::string_view{"Nullified"}.size()
                       + std::string_view{"Name"}.size() + 1);
        CHECK(test_u::name.contains('i'));
        CHECK(test_u::name.contains('m'));
        CHECK(test_u::name.contains('\0'));
    }

    SECTION("prepend (chars)") {
        auto rs = test_t::name.prepend("Prefix");
        CHECK(rs.to_view() == "PrefixName");
        STATIC_CHECK(std::remove_cvref_t<decltype(rs)>::string_size_type::value
                     == std::string_view{"PrefixName"}.size());
    }
    SECTION("prepend (typed)") {
        auto rs = test_t::prepend_typed<"Prefix">();
        CHECK(rs.name.to_view() == "PrefixName");
        STATIC_CHECK(std::remove_cvref_t<decltype(rs.name)>::string_size_type::value
                     == std::string_view{"PrefixName"}.size());
    }

    SECTION("append") {
        auto rs = test_t::name.append("Suffix");
        CHECK(rs.to_view() == "NameSuffix");
        STATIC_CHECK(std::remove_cvref_t<decltype(rs)>::string_size_type::value
                     == std::string_view{"NameSuffix"}.size());
    }
}
