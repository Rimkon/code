"
" запуск source *.vim
"
" известные ошибки:
" ошибка some[5]={1,3,4,6,8,9}; левая скобка [ исчезает
" сделать обработку ==# для vim
"


try
    %s/\([a-zA-Z0-9]\) *(/\1  (/g               " пробел пред  (
    %s/( */( /g                                 " пробел после (
endtry

try
    %s/\([a-zA-Z0-9[:graph:]]\) *)/\1 )/g       " пробел после )
    %s/) */)/g                                  " пробел после )
endtry

" сделать обработку ==# 
try
    %s/ *[=][=]/ ==/g                           "==
    %s/[=][=] */== /g
endtry

try
	" ошибка some[5]={1,3,4,6,8,9}; левая скобка исчезает
    %s/ *[^=][=]\([^=a-zA-Z0-9]\)/ = \1/g       " = 
    %s/\([^=]\)[=]\([^=]\)/\1 = \2/g            
    %s/ *[^=][=][^=] */ = /g
endtry

try
    %s/ *[<][<]/ <</g                           "<<
    %s/[<][<] */<< /g
endtry

:noh

" let s:last = 'hello'
" echo s:last

 " function! s:repeat_visual()
 "  let [mode, ldiff, cdiff] = s:last_visual
  " let cmd = 'normal! '.mode
  " if ldiff > 0




" try
"     if (/^Vim\/=)
"         echo "8"
"     endif
" catch 
"     echo "error"
" endtry

    " let l:line = substitude (getline ('.'), '\t', repeat (' ', &tabstop), 'g')
    " strcharpart (l:line, cirtcol('.') -1, 1)

" let    matchs= matchstr(curLine,'[(][0-9]+[,][0-9]+[)]')
"     echo matchs
