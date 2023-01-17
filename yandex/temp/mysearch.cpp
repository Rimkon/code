// Файл cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef pair<int, vector<string>> pair_int_vecorStr_T;

       string   ReadString ();                                                  // прочтить строку
vector<string>  Parsing_String_Vector  ( const string & );                      // 
vector<string>  documents_noStopWord   ( const vector<string>&, const set<string> &);
   set<string>  Parsing_String_Set     ( const vector<string> &v );

void AddDocument  ( vector <pair_int_vecorStr_T> &,const int &,const set<string>&, const string &);
map <int, int> Relevance (const vector<pair_int_vecorStr_T> &, const string&);
int  Match_String  ( const pair_int_vecorStr_T &,  const string &);



set<string>  Parsing_String_Set     ( const vector<string> &v )
{
set<string> pss;
for (const string i: v)
{
    if  ( pss.count(i)==0)
        pss.insert (i);
}
return pss;
}



string   
ReadString ()
{
    string str;
    getline  ( cin, str );
    return str;
}

vector<string>  Parsing_String_Vector  ( const string & str )
{
    vector<string> vec_str;
    string word;
    for (const char c: str)
    {
        if  ( c == ' ' && !word.empty() )
        {
            vec_str.push_back(word);
            word="";
        }
        else if  ( c!=' ')
            word  +=  c;
    }
    if  (!word.empty()) 
        vec_str.push_back(word);
    return vec_str;
}

void 
ShowContayner ( const vector<string> & v )
{
    for (const auto i: v)
        cout<<'['<<i<<']'<<endl;
   cout<<"-="<<v.size()<<"=-"<<endl;
}

void 
ShowContayner ( const set<string> & v )
{
    for (const auto i: v)
        cout<<'['<<i<<']'<<endl;
   cout<<"-="<<v.size()<<"=-"<<endl;
}
vector<string>  documents_noStopWord (const vector<string>& d, const set<string> & s)
{
    vector<string> doc;
    for (const auto i: d)
    {
        if  ( s.count(i)>0)
            doc.push_back (i);
    }
    return doc;
}

void AddDocument  ( vector <pair_int_vecorStr_T>  & documents, 
                                       const int  & id, 
                               const set<string>  & stopWords, 
                                    const string  & s)
{

    pair_int_vecorStr_T doucument;
    doucument.first = id;
    doucument.second = documents_noStopWord( Parsing_String_Vector (s), stopWords);

    documents.push_back(doucument);
}

int  Match_String  ( const pair_int_vecorStr_T &d,  const string &s)
{
    int count = 0;
    set<string> ds (d.second.begin(), d.second.end());
    vector<string> vs = Parsing_String_Vector (s);

    for (const string i: vs)
    {
        if  ( ds.count (i)>0)
            count++;
    }
    return count;
}

map <int, int> Relevance (const vector<pair_int_vecorStr_T> & d, const string &s)
{
    map <int,int> id_relev;
    int id =0;
    int relevance=0;

    for (const auto i: d){
        relevance = Match_String (i,s);

       if  (relevance >0)
        {
            id_relev.insert ({id, relevance});
        }
    }
    return id_relev;
}


int main()
{
   string  str  = "              a               an on the in is has been are with for              from have be was              ";
   cout<<str<<endl;
   const vector<string>  stopWords = Parsing_String_Vector (str);
   const set <string> pss = Parsing_String_Set(stopWords);
   ShowContayner  (pss);


   cout<<"введи количество строк: ";
   int n;
   cin>>n;
   cout<<  "введите строки: "<<endl;

   vector <pair_int_vecorStr_T>  documents;
   string s;


   for (int i=0; i<n; i++)
   {
       s = ReadString(); 
        AddDocument  (documents,i,pss,s);
   }

   cout<<"ВВеди строку поиска"<<endl;
   string searchstring;
   searchstring=ReadString();

   map<int,int> m = Relevance (documents,searchstring);
   for (const auto&[mapid,maprelevance]: m)
   {
       cout<<"id: "<<mapid<<endl;
       cout<<"relevance: "<<maprelevance<<endl;
   }

}
