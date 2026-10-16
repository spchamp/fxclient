$1 == "#include" && $2 ~ /Types\.hpp/ {
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
   print "ENUM(" TYPEDEF_TYPE ", v_uint32,";
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
    N = 0;
    EEND = ENUM_INDEX - 1;
    for(FN in ENUM_FIELDS) {
        if(FN == EEND) { ENDCHR = "" }
        else { ENDCHR = "," }
        print "  VALUE(" ENUM_FIELDS[FN] ", 1<<" FN ", \"" ENUM_FIELDS[FN] "\"" ")" ENDCHR;
    }
    print ")"; next 
}
$1 == "}" {
  print "#include OATPP_CODEGEN_END(DTO)"
  print ""
}
// { print $0 }

