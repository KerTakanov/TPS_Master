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
#include "MedianFilter.h"
#include "Histogramme.h"

void tp2_q3() {
    Image2D<Color> img(8, 8, Color(255, 0, 255));
    std::ofstream output("tp2_q3.ppm", std::ios::binary);

    Image2DWriter<Color>::write(img, output, false);

    output.close();
}

void tp2_q4() {
    typedef Image2D<Color> ColorImage2D;
    typedef ColorImage2D::Iterator Iterator;
    ColorImage2D img( 256, 256, Color( 0, 0, 0 ) );
    Iterator it = img.begin();
    for ( int y = 0; y < 256; ++y )
        for ( int x = 0; x < 256; ++x )
        {
            *it++ = Color( y, x, (2*x+2*y) % 256 );
        }
    std::ofstream output( "tp2_q4.ppm", std::ios::binary ); // ios::binary for Windows system
    output << "P6" << std::endl; // PPM raw
    output << "# Generated by You !" << std::endl;
    output << img.w() << " " << img.h() << std::endl;
    output << "255" << std::endl;
    for ( Iterator it = img.begin(), itE = img.end(); it != itE; ++it ) // (*)
    {
        Color c = *it;
        output << c.red << c.green << c.blue;
    }
    output.close();
}

void tp2_q9() {
    std::ifstream input("imgs/kowloon.ppm", std::ios_base::binary);
    Image2D<Color> img;
    Image2DReader<Color>::read(img, input);

    typedef Image2D<Color>::Iterator ColorIterator;
    typedef Image2D<Color>::GenericIterator< ColorRedAccessor >   ColorRedConstIterator;
    typedef Image2D<Color>::GenericIterator< ColorGreenAccessor > ColorGreenConstIterator;
    typedef Image2D<Color>::GenericIterator< ColorBlueAccessor >  ColorBlueConstIterator;
    ColorRedConstIterator   itRed   = img.begin< ColorRedAccessor >();
    ColorGreenConstIterator itGreen = img.begin< ColorGreenAccessor >();
    ColorBlueConstIterator  itBlue  = img.begin< ColorBlueAccessor >();
// On écrit la composante verte dans l'image en niveaux de gris.
    int x = 0;
    for ( ColorIterator it = img.begin(), itE = img.end();
          it != itE; ++it )
    {
        switch ( x % 3 ) {
            case 0: *itGreen = *itBlue  = 0; break;
            case 1: *itRed   = *itBlue  = 0; break;
            case 2: *itRed   = *itGreen = 0; break;
        }
        ++itRed; ++itGreen; ++itBlue;
        x = ( x+1 ) % img.w();
    }

    std::ofstream output("tp2_q9.ppm", std::ios::binary);
    Image2DWriter<Color>::write(img, output, false);
}

void testImage2D()
{
    tp2_q3();
    tp2_q4();
    tp2_q9();

    /*std::ifstream input("imgs/church.pgm", std::ios_base::binary);
    Image2D<unsigned char> img;
    Image2DReader<unsigned char>::read(img, input);

    input.close();

    Histogramme h(img);
    h.init();
    h.egalise();
/*
    std::ofstream output( "colors.pgm", std::ios_base::binary);
    Image2DWriter<unsigned char>::write(img, output, false);
    /*MedianFilter mf(img, 15);
    img = mf.apply();

    std::ofstream output( "colors.pgm", std::ios_base::binary);
    Image2DWriter<unsigned char>::write(img, output, true);
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