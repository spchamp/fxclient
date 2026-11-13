
#include <fxsupport/serial_class.hpp>
#include <fxsupport/serial_decimal.hpp>
#include <fxsupport/serial_object_parser.hpp>

#include <rfl/json/read.hpp>
#include <rfl/json/write.hpp>

#include <catch2/catch_test_macros.hpp>


using namespace fxsupport;

using boost::decimal::decimal_fast32_t;

SERIAL_CLASS(DecimalTest, (),
             (dec, decimal_t, "dec", field_param::serial_type::bind<std::string>) );

TEST_CASE("serial decimal") {

    // this passes under the wsl build (clang 22, Fedora 44)

    SECTION("Parser test") {
        static auto const expect_dec = decimal_t{12321.02};
        using transform_t            = SerialTransform<decimal_t, std::string>;

        std::string rs               = transform_t::to_serial(expect_dec);
        CHECK(rs == "12321.02");

        auto const dec = transform_t::to_stored(rs);
        CHECK(dec == expect_dec);
    }

    SECTION("Parser test (Invalid decimal string)") {
        using transform_t = SerialTransform<decimal_t, std::string>;

        transform_t::stored_type dec{};
        try {
            dec = transform_t::to_stored("Nop");
            FAIL("Failed to throw");
        } catch (std::system_error const& ex) {
            CHECK(ex.code() == std::errc::invalid_argument);
        }
        CHECK(dec == 0);  // regression test
    }

    SECTION("write/read") {

        static auto const expect_dec = decimal_t{12321.02};

        DecimalTest       ob{.dec = expect_dec};

        REQUIRE(ob.dec.has_value());
        CHECK(ob.dec.value() == expect_dec);

        std::string os;
        // FIXME note that the write() call may throw with an error message
        // from yyjson, in the general case. It should not throw here:
        os = rfl::json::write(ob);
        CAPTURE(os);
        CHECK(os.contains("12321.02"));

        auto const rs = rfl::json::read<DecimalTest>(os);
        REQUIRE(rs.has_value());
        auto const& ro = rs.value();
        REQUIRE(ro.dec.has_value());
        CHECK(ro.dec.value() == ob.dec.value());
    }
}
