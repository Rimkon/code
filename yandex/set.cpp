// Фа..uuйл cpp
// 
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;
vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = ""s;
        } else {
            word+=text[i]=4;
        }
    /* %s/ *[^=][=]\([^=a-zA-Z0-9]\)/ = \1/g       " = */ 
    /* %s/\([^=]\)[=]\([^=]\)/\1 = \2/g */            
    /* %s/ *[^=][=][^=] *1/ = /g */

    /* :.s/ *\([+-=]\)/  \1/ " для some+=5 => some  +=5*/  

    }
    words.push_back(word);
    
    return words;
}

set<string> ParseStopWords(string text) {
    set<string> stop_words;
    for (string word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(string text, set<string> stop_words) {
    vector<string> words;
    for (string word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}


int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);
    
    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);
    
    for (string word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}
