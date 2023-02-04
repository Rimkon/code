#pragma once
#include <iostream>
#include <vector>
using namespace std;

 int Rotate     ( const int x, const int y, const int rotate );
void ini_pole   ( const int nFieldWidth, const int nFieldHeight,  vector<unsigned char> &pField );
void ini_figuri ( wstring *tetromino );
void show_pole  ( const int nFieldWidth, const int nFieldHeight,  vector<unsigned char> &pField );
