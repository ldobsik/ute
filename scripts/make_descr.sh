# usage: 
# make_descr module1Test.c module2Test.c ...
grep -n -H 'TEST[ \t]*(' $@ | sed -n 's/\([^:]*\):\([^:]*\).*TEST[ \t]*([ \t]*\([^ \t,)]*\)[ \t,]*\([^ \t)]*\).*/\3, \4, \2, "\1",/p'

