// Файл cpp
#include <set>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    set <string> a = {"hello", "man", "good"};
    set <string> b = {"hello", "man"};
    set <string> c;
    

    for ( string word : a) {
        if  ( b.count (word))
            continue;
        else
            c.insert (word);
    }

    for (string w: c) {
        cout<<w<<endl;
    }
    return 0;
}



