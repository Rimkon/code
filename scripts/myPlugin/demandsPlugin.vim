"требование к плагину
" ----------------------------------------------------------------------------
" 1) форматирование комментрия по правому краю. 
" перед комментариями сверху стоит пустая строка
" Длина комментария не более чем пол экрана
"                                  // Ссылка search_query_ref —  ещё одно имя 
"                                  // для доступа к переменной search_query
"   string&  search_query_ref  =  search_query;  
" ----------------------------------------------------------------------------
"  2) двойной пробел 
"  - перед именем и после имени (переменной, класса и т.д)
"  - перед открывающейся скобкой, кавычкой (,"
"  - перед и после =,-,+, >=, += -= <=, ==, !=, и т.д.
"  - после << и пред << зависит от контекста смотри ниже так же и для >>
" ----------------------------------------------------------------------------
"  3) отсутствие пробелов:
"  перед << и после << в зависимости от контекста так же и для >>
"  cout<<  search_query  <<endl;
"  
"  перед <string> так же должен отсутствовать пробел.
"  vector<string>  name  =  { "hello", "some" }
"
"  *,& Перед именем стоят без пробела 
"    string  &search_query_ref  =  search_query;
" ----------------------------------------------------------------------------
"  4)отступ строки до и после объявления переменных 
" форматирование переменных  по примеру ниже
"    vector<string> words;
"           string  word;
"
"    если сразу же переменная используется. пробелы заполнить стрелкой
"    string /*------->*/stop_words_joined;
"    getline   (  cin,  stop_words_joined);
"
"    /*------------------->*/ string /*--->*/stop_words_joined;
"    /*------------------->*/ getline ( cin, stop_words_joined);
"    set<string> stop_words = ParseStopWords(stop_words_joined);
" ----------------------------------------------------------------------------
"  5) при объявлении функции
"  имя находится под типом.
"  тело функции имеет отступ 2 или 3 таба
"
"            vector<string>  
"            SplitIntoWords  ( const string&  text ) 
"            {
"                        vector<string> words;
"                               string  word;
"
" ----------------------------------------------------------------------------
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
