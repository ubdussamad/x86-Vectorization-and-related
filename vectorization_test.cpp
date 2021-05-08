#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
#include <limits>
#define u32 unsigned int

void bits(float x);
void bits(u32 x);

// On my CPU (Arrandale (Core i7 4th gen)) unsigned short doesn't works
// but it also dosent works on godbolt x86gcc so i guess i suck.
// u32 works fine.


typedef unsigned short v4si __attribute__ ((vector_size (4))); // u32 is 2bytes on my system
int main () {
    v4si a, b, c;
    u32* i = (u32 *) &a;
    *i = 0x0000eeee;

    u32* j = (u32 *) &b;
    *j = 0x00001111;

    u32* k = (u32 *) &c;
    *k = 0x00000000;
    
    c = a + b;
    char out[50];
    
    sprintf(out, "%.8x", *k);
    std::cout << out << std::endl;
    // std::cout << c[0] << " " << c[1] << " " << std::endl;
}