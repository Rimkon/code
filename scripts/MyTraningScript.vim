"Тестовый файл где проверяю работу различных команд

  " function Something(key, value = 10)
  "    echo a:key .. ": " .. a:value
  " endfunction
  " call Something('empty')	"empty: 10"
  " call Something('key', 20)	"key: 20"


:function Varg2(foo,key,value =10, ...)
    :  echom a:foo
    :  echom a:0
    :  echom a:1
         echo a:foo ": " a:value
    " :  echo a:000
:endfunction

:call Varg2("hello", "b", "c", 45, 33)
