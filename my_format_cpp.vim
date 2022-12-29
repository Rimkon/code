" для работы:
" открыть файл с кодом 
" запустить source *.vim
" Моя попытка сделать форматирование кода под меня.
" 
"


try
    %s/\([a-zA-Z0-9]\) *(/\1  (/g               " 2 пробела пред  (
    %s/( */( /g                                 " 1 пробел после (
endtry

try
    %s/\([a-zA-Z0-9[:graph:]]\) *)/\1 )/g       " пробел )
    %s/) */)/g                                  " пробел )
endtry

try
    %s/ *[=][=]/ ==/g                           " ==
    %s/[=][=] */== /g
endtry

try
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
