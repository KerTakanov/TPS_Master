// file testColorImage2D.cpp
#include <iostream>
#include <fstream>
#include "Image2D.h"
#include "Color.h"
#include "Image2DWriter.h"
#include "Image2DReader.h"
#include "InvertRedBlueFilter.h"
#include "Accessor.h"
#include "save-channel.h"

int testImage2D()
{
    std::ifstream input("imgs/lena-imp-0_1.pgm", std::ios_base::binary);
    Image2D<unsigned char> img;
    Image2DReader<unsigned char>::read(img, input);
    /*Image2D<Color> img;
    if (!Image2DReader<Color>::read(img, input)) {
        return 0;
    }

    save_channel(img);

    /*typedef Image2D<Color> ColorImage2D;
    typedef ColorImage2D::Iterator Iterator;
    ColorImage2D img;
    std::ifstream input("imgs/lena.ppm", std::ios_base::binary);

    if (!Image2DReader<Color>::read(img, input)) {
        return 0;
    }

    InvertRedBlueFilter redBlueFilter(img);
    redBlueFilter.filter();

    std::ofstream output( "colors.ppm", std::ios_base::binary);
    bool ok2 = Image2DWriter<Color>::write( img, output, false );
    output.close();
    if ( !ok2 ) {
        std::cerr << "Error writing output file." << std::endl;
        return 1;
    }
    output.close();

    return 0;*/
}