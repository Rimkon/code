#include <iostream>
using namespace std; 

void a(int w)
{
    for (int i = 0; i < w; ++i) {
       cout<<i<<' '; 
    }
    cout<<endl;
}

void b (int w)
{
    for (int i = 0; i < w; ++i) {
       a(i); 
    }
}


int main ()
{
    int w;
    cin>>w;
    b(w);
    return 0;
}
