## Enum expression patch for C++ sources generated
## using the OpenAPI generator cpp-oatpp-client,
## with OpenAPI generator version 7.26.0.
##
## For each enum type in the OpenAPI definition,
## the generator produced an OAT++ model type
## not using an OAT++ ENUM semantics.
##
## This awk (GNU awk) script will patch the
## generated sources to use an OAT++ ENUM
## semantics.
##
## In the process of producing this patch script,
## it was observed that there is an upper bound
## on the number of elements that can be present
## within an OAT++ ENUM macro expression, in
## OAT++ release 1.3.1.
##
## For the case of an API Enum expression exceeding
## that upper bound, this will manually construct
## the equivalent of an OAT++ ENUM macro expression.
##
## Known limitations:
## - See below
## - This assumes a certain source format, generally
##   consistent with the original clang-format rules
##   as used when formatting the generated sources.
##

BEGIN {
    PREFIX="Fx"
}
$1 == "#include" && $2 ~ /Types\.hpp/ {
  print "#include <cstdint>"
  print $0;
  print "#include \"oatpp/core/macro/codegen.hpp\"";
  next;
}
$1 == "typedef" && $2 == "oatpp::String" {
    gsub(";", "", $3);
    TYPEDEF_TYPE = $3;
    print "#include OATPP_CODEGEN_BEGIN(DTO)"
    print ""
    next
}
$1 == "class" && $2 ~ /Values/ {
   ENUM_TYPE = TYPEDEF_TYPE;
   gsub("^" PREFIX, "", ENUM_TYPE);
   ENUM_INDEX = 0;
   next;
}
$1 == "public:" { next }
$1 == "static" && $2 == TYPEDEF_TYPE {
    FIELD_NAME=$3;
    sub("(void)", "", FIELD_NAME);
    gsub("[()]", "", FIELD_NAME);
    ENUM_FIELDS[ENUM_INDEX++] = FIELD_NAME
    next;
}
$0 == "};" {
    if(ENUM_INDEX > 62) {
        ## The maximum enum value is greater that the maximum number of
        ## elements for an OAT++ ENUM(...) expression
        ##
        ## See also
        ## https://github.com/oatpp/oatpp/issues/478
        ##
        ## Workaround: Produce the approximate equivalent of an OAT++ ENUM
        ## expression.
        ##
        ## To keep the underlying enum type within a range of 64 bits, this
        ## will not use an enum index based on powers of 2.
        ##
        ## This will first declare a C++ enum type, then providing a static
        ## initializer for an OAT++ EnumMeta model type.
        ##
        ## This was based on the output of clang++ "-E" with sources using
        ## an OAT++ ENUM macro expression within the macro bounds, in OAT++
        ## version 1.3.1.
        ##
        ## Like elsewhere here, this assumes a C++-safe name for every enum element
        ## in the type.
        ##
        ## For compatibility with the EnumValueInfo::index type, this assumes that
        ## the total number of values can be cast as std::int32_t without truncation.
        ##
        ## In Sidebar: It was noticed that the v_int32 destination type - as used for
        ## the EnumValueInfo::index member - differs from the v_uint64 type as used in
        ## the EnumMeta byValue map, in OAT++ release 1.3.1.
        ##
        ## The "Z_" ... syntax here was derived after the clang++ -E expansion. This
        ## syntax is retained in the manual expansion, out of the interest of
        ## preprocessor-level consistency beside other sources in the project.
        ##
        ## Fortunately, there is only one enum type in the project that will require
        ## this method of manual construction for the EnumMeta type.
        ##
        CPP_TYPE = "std::uint_fast32_t";
        print "enum class " ENUM_TYPE " : " CPP_TYPE " {";
        N = 0;
        EEND = ENUM_INDEX - 1;
        for(FN in ENUM_FIELDS) {
            if(FN == EEND) { ENDCHR = "" } else { ENDCHR = "," }
            print "  " ENUM_FIELDS[FN] " = " (FN + 1) ENDCHR;
        }
        print "};";
        N = 0;

        print "class Z__OATPP_ENUM_META_" ENUM_TYPE " : public oatpp::data::mapping::type::EnumMeta<" ENUM_TYPE "> {"
        print "private:"
        print "    static bool init() { "
        ## Note: ENUM_TYPE as a C++ name
        print "        auto& info = *EnumMeta<" ENUM_TYPE ">::getInfo();"
        print "        " CPP_TYPE " index = 0;"
        ## Note: \" ENUM_TYPE \" as an API model name
        print "        info.nameQualifier = \"" ENUM_TYPE "\";"
        for(FN in ENUM_FIELDS) {
            FLD = ENUM_FIELDS[FN];
            print "        {"
            print "            oatpp::data::mapping::type::EnumValueInfo<EnumType> entry = { EnumType::" FLD ", static_cast<v_int32>(index++), \"" FLD "\", nullptr};";
            print "            info.byName.insert({\"" FLD "\", entry});"
            print "            info.byValue.insert({static_cast<" CPP_TYPE ">(EnumType::" FLD "), entry});"
            print "            info.byIndex.push_back(entry);"
            print "        }"
        }
        print "        return true;"
        print "    }"
        print "public:"
        print "static bool initializer() { "
        print "    static bool initialized = init(); return initialized; "
        print "}"
        print "};"
        print ""
        print "static const bool Z__OATPP_ENUM_META_INITIALIZER_" ENUM_TYPE " = Z__OATPP_ENUM_META_" ENUM_TYPE "::initializer();"
        print ""
        next;
    }
    else if(ENUM_INDEX >30) {
        CPP_TYPE="std::uint_fast64_t"
    }
    else if(ENUM_INDEX > 14) {
        CPP_TYPE="std::uint_fast32_t"
    }
    else if(ENUM_INDEX > 6) {
        CPP_TYPE="std::uint_fast16_t"
    }
    else {
        CPP_TYPE="std::uint_fast8_t"
    }

    print "ENUM(" ENUM_TYPE ", " CPP_TYPE ",";

    N = 0;
    EEND = ENUM_INDEX - 1;
    for(FN in ENUM_FIELDS) {
        if(FN == EEND) { ENDCHR = "" } else { ENDCHR = "," }
        print "  VALUE(" ENUM_FIELDS[FN] ", (static_cast<" CPP_TYPE ">(1)<<" FN "), \"" ENUM_FIELDS[FN] "\"" ")" ENDCHR;
    }
    print ")"; next
}
$1 == "}" {
  print "#include OATPP_CODEGEN_END(DTO)"
  print ""
  print "using " TYPEDEF_TYPE " = oatpp::Enum<" ENUM_TYPE ">;"
}
// { print $0 }

