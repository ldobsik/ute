# usage: 
# make_ids module1Test.c module2Test.c ...
echo '/* this file was generated */'
echo
echo "typedef enum {"
sed -n 's/TEST[ \t]*([ \t]*\([^ \t,)]*\)[ \t,]*\([^ \t)]*\).*/  TEST_ID_\1_\2,/p' $@
echo "  TEST_ID_COUNT"
echo "} uteTestId_t;"
