#include <iostream>
#include <fstream>
#include "Color.h"
#include "Image2DWriter.h"
#include "Accessor.h"
#include "Image2DReader.h"
#include "save-channel.h"

int main3(int argc, char* argv[])  {
    if (argc < 1) {
        std::cout << "Vous devez spécifier un fichier en entrée" << std::endl;
        return -1;
    }
    std::string input_path = argv[1];
    std::ifstream input(input_path, std::ios::binary);

    if (!input) {
        std::cerr << "Erreur lors de la lecture du fichier input" << std::endl;
        return -1;
    }

    Image2D<Color> img;
    Image2DReader<Color>::read(img, input);

    typedef Image2D<unsigned char> GrayLevelImage2D;
    typedef Image2DWriter<unsigned char> GrayLevelImage2DWriter;
    typedef GrayLevelImage2D::Iterator GrayLevelIterator;
    typedef Image2D<Color> ColorImage2D;
    typedef Image2DReader<Color> ColorImage2DReader;
    typedef ColorImage2D::Iterator ColorIterator;

    GrayLevelImage2D img_green( img.w(), img.h() );
    GrayLevelImage2D img_red( img.w(), img.h() );
    GrayLevelImage2D img_blue( img.w(), img.h() );

    //-----------------------------------------------------------------------------
    // vvvvvvvvv Toute la transformation couleur -> canal vert est ici vvvvvvvvvvvv
    //
    // Servira à parcourir la composante verte de l'image couleur.
    typedef ColorImage2D::GenericIterator< ColorGreenAccessor > ColorGreenConstIterator;
    typedef ColorImage2D::GenericIterator< ColorRedAccessor > ColorRedConstIterator;
    typedef ColorImage2D::GenericIterator< ColorBlueAccessor > ColorBlueConstIterator;

    // Notez comment on appelle la méthode \b générique `begin` de `Image2D`.
    ColorGreenConstIterator itGreen = img.begin< ColorGreenAccessor >();
    ColorRedConstIterator itRed = img.begin< ColorRedAccessor >();
    ColorBlueConstIterator itBlue = img.begin< ColorBlueAccessor >();

    // On écrit la composante verte dans l'image en niveaux de gris.
    for ( GrayLevelIterator it = img_green.begin(), itE = img_green.end();
          it != itE; ++it )
    {
        *it = *itGreen;
        ++itGreen;
    }

    // On écrit la composante verte dans l'image en niveaux de gris.
    for ( GrayLevelIterator it = img_red.begin(), itE = img_red.end();
          it != itE; ++it )
    {
        *it = *itRed;
        ++itRed;
    }

    // On écrit la composante verte dans l'image en niveaux de gris.
    for ( GrayLevelIterator it = img_blue.begin(), itE = img_blue.end();
          it != itE; ++it )
    {
        *it = *itBlue;
        ++itBlue;
    }

    //-----------------------------------------------------------------------------
    std::ofstream output_green("green.pgm", std::ios_base::binary);
    std::ofstream output_red("red.pgm", std::ios_base::binary);
    std::ofstream output_blue("blue.pgm", std::ios_base::binary);

    GrayLevelImage2DWriter::write(img_green, output_green, false );
    GrayLevelImage2DWriter::write(img_red, output_red, false );
    GrayLevelImage2DWriter::write(img_blue, output_blue, false );

    output_green.close();
    output_red.close();
    output_blue.close();
    return 0;
}