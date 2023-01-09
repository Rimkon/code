#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

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

int main(int argc, char *argv[])
{
    vector< pair<int, vector<string>>>  document_words = 
    {
        {12,{"first","some","hello"}},
        {34,{"rashid","the","hero"}},
        {87,{"good","day","tooday"}}
    };

    cout <<  document_words.at(1).first;
    cout <<  document_words.at(1).second.at(0);
    cout<<endl;

    for ( const auto &[i,vs] : document_words) {
       cout<<i<<' ';
       for (const auto g : vs) {
          cout<<g<<'|'; 
       }
       cout<<endl;
    }
    
    return 0;
}
