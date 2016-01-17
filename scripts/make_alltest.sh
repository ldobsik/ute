# usage: 
# make_alltest module1Test.c module2Test.c ...
echo '/* this file was generated */'
echo '#include "ute.h"'

sed -n "/TEST/p" $@ > ute_macros.tmp

# for each test group inside the input files generate a group runner function
for gr in `sed -n 's/TEST_GROUP[ \t]*([ \t]*\([^ \t)]*\).*/\1/p' ute_macros.tmp`
do
  echo
  sed -n "s/TEST[ \t]*([ \t]*$gr[ \t,]*\([^ \t)]*\).*/DECLARE_TEST_CASE($gr, \1);/p" ute_macros.tmp
  echo
  echo "TEST_GROUP_RUNNER($gr)"
  echo "  RUN_TEST_GROUP($gr);" >> test_groups.tmp
  echo {
  sed -n "s/TEST[ \t]*([ \t]*$gr[ \t,]*\([^ \t)]*\).*/  RUN_TEST_CASE($gr, \1);/p" ute_macros.tmp
  echo }
done
# main function initializes the result array and calls the group runners
echo
echo "int main(void)"
echo {
echo "  Ute_InitResultArray();"
cat test_groups.tmp
echo "  Ute_DumpResultArray();"
echo "  return 0;"
echo }
rm test_groups.tmp ute_macros.tmp
