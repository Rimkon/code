#include <iostream>
using namespace std; 

void foo  ( );

void foo  ( ){
    cout << "hello foo" << endl;
}
int main  ( )
{
    int a = 25;
    a++;
    cout << a << endl;
    foo  ( );
}
