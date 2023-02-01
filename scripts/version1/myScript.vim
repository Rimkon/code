"(
:%s/(\s*/(/g
%s/\([[:alnum:]]\)\s*(\s*\(\)/\1  ( /g
:%s/\([[:alpha:]]*\.[[:alpha:]]*_*[[:alpha:]]*\)\s*(/\1(/g

")
:%s/\([[:graph:]]\)\s*)\s*/\1 )/g

"=
:%s/\([[:alnum:]]\)\s*=/\1  =/g
:%s/=\s*\([[:alnum:]]\)/=  \1/g

"<<
%s/\s*<<\s*/  <<  /g
:%s/\(cout\)\s*<<\s*/\1<<  /g
:%s/\s*<<\s*\(endl\)/  <<\1/g

">>
:%s/\(cin\)\s*>>\s*/\1>>  /g

" set<vector>
:%s/\([[:alpha:]]*\)\s*<\([[:alpha:]]*\)>\s*/\1<\2> /g
:%s/\(#include\)\s*</\1  </
" %s/>\s*>/>>/g

",
:%s/\s*,\s*/,  /g


:nohlsearch

