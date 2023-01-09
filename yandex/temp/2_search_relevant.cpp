// Version 2.0
// добавлено релевантность поиска
// -------------------
// Version 1.0
// Поиск слов в тексте с учетом стоп слов
//

// На вход подаётся:
// --> строка из стоп слов (слова которые не должны участвовать в поиске)это предлоги с на у до и прочее.
// --> количество строк в документе
// --> сам документ
// --> искомая строка
// выход: номера строк (отсчет с 0) где встречаеться хоть одно совпадение.
//
// пример:
// Вход:
/*
a an on the in is has been are with for from have be was
4
a small curly guinea pig with grey hair has been found
a young 50 year old crocodile wants to make friends
a strange brown creature was seen in the box of oranges
a strange animal with big ears is building a house for its friends
cheburashka with big ears likes oranges 

Выход:
{ document_id = 2 }
{ document_id = 3 }
*/


#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
                                                  
string // --------------------------------------------------------- чтение строки ----
ReadLine() {                                               //  Вход: поток символов
                                                           // Выход: строка
        string s;

        getline(cin, s);
        return s;
}

int 
ReadLineWithNumber() { // ---------------------------------- чтение числа и строки ---
                                                           //    Вход: запрос числа.
        int result = 0;                                    // Зависит: ReadLine()
                                                           //   Выход: запрошенное число.
        cin >> result;
        ReadLine();
        return result;
}

vector<string> // ---------------------------------------- разбить строку на слова ---
SplitIntoWords  ( const string&  text ) {                  //  Вход: строка слов
                                                           // Выход: вектор слов 
        vector<string>  words;
               string   word;

        for  ( const char c : text ) {
            if  ( c  ==  ' ' ) {
                if  ( !word.empty( ) ) {
                    words.push_back( word );
                     word.clear( );
                }
            } else {
                word  +=  c;
            }
        }
        if  ( !word.empty() ) {
            words.push_back( word );
        }

    return  words;
}

set<string> // --------------------------------------------исключить из строки повторяющиеся слова ---
ParseStopWords  ( const string& text ) {                   //  Вход: строка слов
                                                           // Выход: set слов (уникальные слова)
        set<string>  stop_words;

        for  ( const string& word : SplitIntoWords( text )) {
            stop_words.insert( word );
        }
        return  stop_words;
}

vector<string> // ---------------------------------------- иcключить из строки содержимое set ---
SplitIntoWordsNoStop  ( const     string&  text,           //  Вход: строка и set (то что исключаем из строки) 
                        const set<string>& stop_words )    // Выход: вектор слов без слов из set. 
{
        vector<string>  words;

                                                           // проходим по всем словам из текста и проверяем,
                                                           // что их нет в списке стоп-слов
        for  ( const string  &word : SplitIntoWords( text )) {
            if  ( stop_words.count( word )  ==  0) {
                words.push_back( word );
            }
        }
                                                           // вернём результат без стоп-слов
        return words;
}

void // -------------------------------------- добавить в вектор вектор слов исключая слова из set ---
AddDocument  ( vector<vector<string>>  &documents,         // Вход: ЗАМЕНА вектора векторов,set,string
                   const set<string>   &stop_words,        // Зависит: SplitIntoWordsNoStop (string,set)
                   const     string    &document )         // Выход: ЗАМЕНА добавление вектора в вектор

{
        const vector<string>  words  =  SplitIntoWordsNoStop  ( document,  stop_words );
        documents.push_back( words );
}

// DONE
set<string> // --------------------------------- иcключить из строки содержимое set ---
ParseQuery  ( const     string  &text,                     // Вход: строка, слова для исключения в set 
              const set<string> &stop_words)               // Зависит: SplitIntoWordsNoStop(string,set) 
{                                                          // Выход: set слов исключая слова из set
        set<string>  query_words;
                                                           // Напишите код функции
        for (string i : SplitIntoWordsNoStop ( text, stop_words ))
        {
            if  ( query_words.count (i)  ==  0 )
                query_words.insert( i );
        }
        return  query_words;
}

// вроде бы должно быть ОК 
bool // -----------------------------------------------------------------------// поиск в векторе слова из set. Если да то true ---
MatchDocument  ( const vector< pair<int, vector<string>>>  &document_words,    // Вход: вектор слов, набор слов из set 
                 const    set<string>  &query_words)                           // Выход: true есть совпадения, false нет сопадений
{
        for (const auto & [n,vs] : document_words) 
        {
            for (const auto i : vs) {
                if  ( query_words.count ( i ))
                    return true;
            }
        }
        return false;
}
//===============================================================================================
vector<pair<int, int>> // ----------------------------------------------------------------------- номер строки, релевантность
FindDocuments  ( const vector<  pair<int, vector<string> >  >& documents,
                 const set<string>  &stop_words,
                 const     string   &query)
{

        vector<int> matched_documents;
        set<string> string_out_set  =  ParseQuery ( query, stop_words );


НАДО СДЕЛАТЬ!



        for (int i = 0; i < (int)documents.size(); ++i) {
            if  ( MatchDocument (documents[i], string_out_set))
            {
                matched_documents.push_back (i);
            }
        }


        return matched_documents;
}

//===============================================================================================
int 
main() {
                                                           // стоп слова 
        const     string  stop_words_joined  =  ReadLine( );                        
        const set<string> stop_words         =  ParseStopWords( stop_words_joined );
                                                                                       

                                                           // наполнение документа 
        vector<vector<string>>  documents;
        const int  document_count  =  ReadLineWithNumber( );

        for  ( int document_id = 0; document_id < document_count; ++document_id ) {
                AddDocument  ( documents,  stop_words,  ReadLine( ) );
        }

                                                           // искомая строка
        const string query  =  ReadLine( );

                                                           // где найдено совпадение
        for  ( const int document_id : FindDocuments( documents, stop_words, query )) {
                cout<<  "{ document_id = "s  <<  document_id  <<  " }"s  <<endl;
        }
}
