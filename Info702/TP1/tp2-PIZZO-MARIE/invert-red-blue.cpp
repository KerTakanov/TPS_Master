#include <string>
#include <iostream>
#include <fstream>
#include "Image2D.h"
#include "Color.h"
#include "Image2DReader.h"
#include "InvertRedBlueFilter.h"
#include "Image2DWriter.h"

int main2(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Vous devez spécifier le chemin d'entrée et le chemin de sortie de l'image." << std::endl;
        return 0;
    }
    std::string input_path = argv[1];
    std::string output_path = argv[2];

    std::ifstream input(input_path, std::ios::binary);
    std::ofstream output(output_path, std::ios::binary);

    if (!input) {
        std::cerr << "Erreur lors de l'ouverture du fichier input" << std::endl;
        return -1;
    }

    if (!output) {
        std::cerr << "Erreur lors de l'ouverture du fichier output" << std::endl;
        return -1;
    }

    Image2D<Color> img;
    Image2DReader<Color>::read(img, input);

    std::cout << img.get_data().size() << std::endl;

    InvertRedBlueFilter irbf(img);
    irbf.filter();

    Image2DWriter<Color>::write(img, output, false);
    std::cout << "Created new image " << output_path << std::endl;
    input.close();
    output.close();
}