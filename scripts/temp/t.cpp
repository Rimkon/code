#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(vector<vector<string>>& documents, const set<string>& stop_words,
                 const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back(words);
}

set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}

int MatchDocument(const pair<int, vector<string>>& document_words, const set<string>& query_words) {
    int temp =0;
    for (const string& word : document_words) {
        if (query_words.count(word) != 0) {
           temp++; 
        }
    }
    return temp;
}

set<string> parse_to_set (const string &str, const set<string> &stopwords)
{
    set<string> zapros_itog;
    for (const auto i:SplitIntoWordsNoStop (str, stopwords))
    {
        if  ( zapros_itog.count(i)==0)
            zapros_itog.insert(i);
    }
    return zapros_itog;
}
// Для каждого найденного документа возвращает его id
vector<pair<int,int>> FindDocuments  (const vector<pair<int,vector<string>>>& documents,
                                                 const set<string>& stop_words,
                                                      const string& query) {

    set<string>  search_zapros  =  parse_to_set  ( query, stop_words );
    pair<int,int> id_relevance;
    vector <pair<int,int>> vec_id_relevance;
    int id=0;
    for (const auto i: documents)
    {
        id_relevance.first = id;
        id_relevance.second = MatchDocument (i.second, search_zapros);
        
        vec_id_relevance.push_back(id_relevance);
        id++;
    }
return vec_id_relevance;
}

    /* const set<string> query_words = ParseQuery(query, stop_words); */
    /* vector<int> matched_documents; */
    /* int document_id = 0; */
    /* for (const auto& document : documents) { */
    /*     if (MatchDocument(document, query_words)) { */
    /*         matched_documents.push_back(document_id); */
    /*     } */
    /*     ++document_id; */
    /* } */
    /* return matched_documents; */


int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector<vector<string>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, ReadLine());
    }

    const string query = ReadLine();
    for (auto document_id : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << " }"s << endl;
    }
}
