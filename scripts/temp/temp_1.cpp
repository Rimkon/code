// Файл cpp
#include "iostream"
using namespace std;
// если не помнит цвет - ? номер дома - (-1)

int main ()
{
    string colorHouse1, colorHouse2, colorHouse3, clolorFind;
    int floorHouse1, floorHouse2, floorHouse3, floorFind;

    cin>>  colorHouse1  >>  floorHouse1  >>
           colorHouse2  >>  floorHouse2  >>
           colorHouse3  >>  floorHouse3  >>
           clolorFind   >>  floorFind;

    int n1,n2,n3;

    if  ( floorHouse1 >= floorHouse2  && floorHouse1 >=floorHouse3) n3 = floorHouse1;
    if  ( floorHouse2 >= floorHouse1  && floorHouse2 >=floorHouse3) n3 = floorHouse2;
    if  ( floorHouse3 >= floorHouse1  && floorHouse3 >=floorHouse2) n3 = floorHouse3;

    if  ( floorHouse1 >= floorHouse2  && floorHouse1 <= floorHouse3 || floorHouse1 <= floorHouse2  && floorHouse1 >= floorHouse3 ) n2 = floorHouse1;
    if  ( floorHouse2 >= floorHouse1  && floorHouse2 <= floorHouse3 || floorHouse2 <= floorHouse1  && floorHouse2 >= floorHouse3 ) n2 = floorHouse1;
    if  ( floorHouse3 >= floorHouse1  && floorHouse3 <= floorHouse2 || floorHouse3 <= floorHouse1  && floorHouse3 >= floorHouse2 ) n2 = floorHouse1;

    if  ( floorHouse1 <= floorHouse2  && floorHouse1 <=floorHouse3) n1 = floorHouse1;
    if  ( floorHouse2 <= floorHouse1  && floorHouse2 <=floorHouse3) n1 = floorHouse2;
    if  ( floorHouse3 <= floorHouse1  && floorHouse3 <=floorHouse2) n1 = floorHouse3;


    /* if  ( clolorFind  ==  colorHouse1 ) */
    /* { */
    /*     if  ( clolorFind  ==  colorHouse2 ) */
    /*     { */
    /*         if  ( clolorFind  == colorHouse3 ) */
    /*         { */
    /*             if  ( floorFind >= n3 ) */
    /*             { */
    /*                 cout << n1 <<endl; */
    /*                 cout << n2 <<endl; */
    /*                 cout << n3 <<endl; */
    /*             } */
    /*             if  ( floorFind < n3 && floorFind > n1) */

    /*         } */
    /*     } */

    /* } */
    
   
    if  ( clolorFind  ==  colorHouse1 && clolorFind  == colorHouse2  && clolorFind == colorHouse3 )
    {
        if  ( floorFind >= n3 )
        {
            cout << n1 <<endl;
            cout << n2 <<endl;
            cout << n3 <<endl;
        }
        else if  ( floorFind >=n1  && floorFind <=
                else
        {
            cout << "-1"s;
        }


   }

























