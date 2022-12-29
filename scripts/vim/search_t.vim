
let n = 1
while n <= argc()	    "цикл по всем файлам в списке аргументов 
  exe "argument " . n
  " начните с последнего символа в файле и завершите
  " первый поиск, чтобы найти совпадение в начале файла
  normal G$
  let flags = "w"
  while search("foo", flags) > 0
	 s/foo/bar/g
	 let flags = "W"
  endwhile
  update		    " write the file if modified
  let n = n + 1
endwhile
