// Version 2.0
// добавлено релевантность поиска.
//
// На входе:
// a an on the in is has been are with for from have be was
/* 4 */
/* a small curly guinea pig with grey hair has been found */
/* a young 50 year old crocodile wants to make friends */
/* a strange brown creature was seen in the box of oranges */
/* a strange animal with big ears is building a house for its friends */
/* cheburashka with big ears likes oranges */
// на выходе:
// { document_id = 2, relevance = 1 }
// { document_id = 3, relevance = 2 }

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
AddDocument  ( vector< pair<int, vector<string>>>  &documents,       
                   const set<string>  &stop_words,        
                   const        int   &document_id, 
                   const     string   &document )        
{
        const vector<string>  words  =  SplitIntoWordsNoStop  ( document,  stop_words );
        const pair <int, vector <string>> pair_words = {document_id, words};

        documents.push_back (pair_words);
}


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

int// -----------------------------------------------------------------------// поиск в векторе слова из set. Если да то true ---
MatchDocument  ( const  pair<int, vector<string>>  &documents,   
                 const    set<string>  &query_words)                           // Выход: true есть совпадения, false нет сопадений
{
        /* pair<int, vector<string>>  content = documents; */
        int max = 0;

        for (auto & i : documents.second) 
        {
                if  ( query_words.count ( i ))
                    max++;
        }
        return max;
}

//===============================================================================================
vector<pair<int, int>> // {documenit_id, relevance}----------------------------------------------
FindDocuments  ( const vector<  pair<int, vector<string> >  >& documents,
                 const set<string>  &stop_words,
                 const     string   &query)
{
        vector <int>              matched_documents;
     const set <string>           string_out_set  =  ParseQuery ( query, stop_words );
        vector <pair <int, int>>  v_id_relevance;
          pair <int, int>         id_relevance;

        int id=0;
        for (const auto i: documents) {
            id_relevance.first = id++;
            id_relevance.second = MatchDocument (i, string_out_set); 

            if  ( id_relevance.second >0)
                v_id_relevance.push_back(id_relevance);

        }

return v_id_relevance;
}

//===============================================================================================
int 
main() {
                                                           // стоп слова 
    const     string   stop_words_joined = ReadLine();
    const set<string>  stop_words        = ParseStopWords(stop_words_joined);

                                                           // наполнение документа 
                                                           // Считываем документы
    vector<pair<int, vector<string>>> documents;
    const int document_count = ReadLineWithNumber();

    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, document_id, ReadLine());
    }

                                                           // искомая строка
    const string query = ReadLine();
    
                                                           // Выводим результаты поиска по запросу query
    for (auto [document_id, relevance] : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
             << endl;
    }
}

