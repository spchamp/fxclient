# fxclient tests

add_subdirectory(lib_test)
add_catch_test(test_member_field
    LIBRARIES fxsupport ${FX_LIBS}
)

add_catch_test(test_tparameter
    LIBRARIES fxsupport
)

add_catch_test(test_serial_decimal
    LIBRARIES fxsupport ${FX_LIBS}
)

