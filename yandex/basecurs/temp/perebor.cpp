#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
map <char, int> fromStrToCharMap(const string &s1)
{
    map <char, int> temp;
    for (char c : s1) {
       ++temp[c]; 
    }
return temp;
};




bool CheckAnagram(const string& s1, const string& s2) {
    return fromStrToCharMap(s1)==fromStrToCharMap(s2);
};

// напишем небольшую функцию для проверки
void CheckIsTrue(bool value) {
    if (value) {
        cout << "Test passed :)"s << endl;
    } else {
        cout << "Test failed :("s << endl;
    }
}

int main() {
    CheckIsTrue (   CheckAnagram("tea"s,    "eat"s     )  );
    CheckIsTrue (  !CheckAnagram("battle"s, "beatle"s  )  );
    CheckIsTrue (  !CheckAnagram("lift"s,   "elevator"s)  );
    CheckIsTrue (   CheckAnagram("ocean"s,  "canoe"s   )  );
}

