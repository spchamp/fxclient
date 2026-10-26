# fxclient library sources

deftarget(fxclient

    SOURCES
    # dummy file for compiling this library and producing a *.lib file
    # in order to link to this library and its transitive dependencies
    # under a windows build
    fxclient/empty.cpp

    HEADERS
    fxclient/fxmodel/MemberField.hpp
    fxclient/fxmodel/NamedField.hpp

    coapp/lib/LText.hpp

    PUBLIC_INCLUDES ${FXCLIENT_INCLUDES}

    PUBLIC_LIBRARIES
    ${FXCLIENT_LIBS}
)
