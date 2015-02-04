// Name: Brandan Tyler Lasley
// Date: 4/19/2014 23:36
// Desc: Converts Dedimal to binary (upto UINT64 MAX).

#ifndef DeciToBin
#define DeciToBin
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;
string ToBinary(long long decimal);
bool SystemEdianness();
string Edian_Swap(string bin, bool edianness);
#endif