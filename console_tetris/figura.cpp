
// поворот фигур осуществляется по формуле:
// 4 это размер матрицы.
//
//            x0   x1   x2   x3              x0   x1   x2   x3
//       y0    0    1    2    3         y0   12    8    4    0
//       y1    4    5    6    7         y1   13    9    5    1 
//       y2    8    9   10   11         y2   14   10    6    2
//       y3   12   13   14   15         y3   15   11    7    3
//
//       формула 0: 4y+x                формула 90: 12+y-4x 
//
//
//            x0   x1   x2   x3               x0   x1   x2   x3
//       y0   15   14   13   12          y0    3    7   11   15
//       y1   11   10    9    8          y1    2    6   10   14
//       y2    7    6    5    4          y2    1    5    9   13
//       y3    3    2    1    0          y3    0    4    8   12    
//
//       формула 180: 15-4y-x            формула 270: 3-y+4x
//            
// 
// 

#include "figura.hpp"

void 
ini_figuri ( wstring *tetromino ){
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    
    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");
    
    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");
    
    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");
    
    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");
    
    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");
    
    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");
}

int 
Rotate  (  const int x,  const int y,  const int rotate )
{
    const int matirix_size = 4;

    switch ( rotate % matirix_size )
    {
        case 0: return      x + ( y * matirix_size );       // 0 градусов
        case 1: return 12 + y - ( x * matirix_size );       // 90 градусов
        case 2: return 15 -     ( y * matirix_size ) - x;   // 180 градусов
        case 3: return  3 - y + ( x * matirix_size );       // 270 градусов
    };
    return 0;
};




void 
ini_pole ( const int nFieldWidth,  
           const int nFieldHeight,  vector <unsigned char> &pField )
{

    pField.resize(nFieldWidth * nFieldHeight,'*');
    bool field_border;
    bool field_kraya;

    for (int x = 0; x < nFieldWidth ; x++) {
        for (int y = 0; y < nFieldHeight ; y++) {
            field_border  =  ( x == 0  ||  x == nFieldWidth -1  ||  y == nFieldHeight - 1) ;
            field_kraya =   ( y == 0 && x == 0 ) ;

            pField [ y * nFieldWidth + x ] = field_border || field_kraya ? '9' : '0';  
        }
    }
    
}

void show_pole (  const int nFieldWidth,  
                  const int nFieldHeight,  vector <unsigned char> &pField )
{
    for (int x = 0; x < nFieldWidth ; x++) {
        for (int y = 0; y < nFieldHeight ; y++) {

            cout<< pField [ x ];
        }
        cout<<endl;
    }
}
