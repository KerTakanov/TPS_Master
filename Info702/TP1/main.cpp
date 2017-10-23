#include <iostream>
#include <fstream>
#include "GrayLevelImage2D.h"
#include "MedianFilter.h"

int main() {
    GrayLevelImage2D img( 8, 8, 5 ); // imagette 8x8 remplie de 5
    std::ifstream input("imgs/lena-imp-0_01.pgm", std::ios::binary);

    std::ofstream output("imgs/test-lena.pgm");
    img.importPGM(input);
    MedianFilter mf(img, 1);
    mf.apply().exportPGM(output, false);

    return 0;
}