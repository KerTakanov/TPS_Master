//
// Created by Meimei on 15/11/2017.
//

#ifndef TP1_IMAGE2DREADER_H
#define TP1_IMAGE2DREADER_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <queue>
#include "Image2D.h"
#include "Color.h"

template <typename TValue>
class Image2DReader {
public:
    typedef TValue Value;
    typedef Image2D<Value> Image;
    static bool read( Image & img, std::istream & input )
    {
        std::cerr << "[Image2Reader<TValue>::read] NOT IMPLEMENTED." << std::endl;
        return false;
    }
};

/// Specialization for gray-level images.
template <>
class Image2DReader<unsigned char> {
public:
    typedef unsigned char Value;
    typedef Image2D<Value> Image;
    static bool read( Image & img, std::istream & input )
    {
        if (!input.good()) {
            std::cout << "Erreur lors de la lecture du fichier !\n" << std::strerror(errno);
            return false;
        }

        std::cout << "Extraction de l'entête" << std::endl;

        char magic_number = get_magic_number(input);
        int w, h, max_rgb;

        std::string line;
        input >> line;
        std::cout << "line " << line << std::endl;
        input >> line;
        std::cout << "line " << line << std::endl;

        input >> w;
        input >> h;
        input >> max_rgb;


        std::string s;
        std::getline(input, s);

        std::queue<Color> numbers = extract_numbers(input);

        std::cout << "Extraction de l'entête terminée" << std::endl;

        unsigned char val;
        while (input >> std::noskipws >> val) {
            img.get_data().push_back(val);
        }

        std::cout << "job's done !" << std::endl;

        img.w(w);
        img.h(h);

        std::cout << "Image extraite, w = " << w << ", h = " << h << ", max = " << max_rgb << ", size = " << img.get_data().size() << std::endl;
        return true;
    }

private:
    static std::queue<Color> extract_numbers(std::istream &input) {
        std::queue<Color> numbers;

        return numbers;
    }

    static std::string remove_comment(std::string line) {
        std::string::size_type n = line.find('#');
        if (n != std::string::npos)
            line.erase(n);

        return line;
    }

    static char get_magic_number(std::istream &input) {
        std::string line;
        int magic_number = -1;
        while (input >> line) {
            int find_pos = line.find('P');
            if (find_pos != std::string::npos) {
                return line[find_pos + 1];
            }
        }

        return -1;
    }
};

/// Specialization for color images.
template <>
class Image2DReader<Color> {
public:
    typedef Color Value;
    typedef Image2D<Value> Image;

    static bool read(Image &img, std::istream &input) {
        if (!input.good()) {
            std::cout << "Erreur lors de la lecture du fichier !\n" << std::strerror(errno);
            return false;
        }

        std::cout << "Extraction de l'entête" << std::endl;

        char magic_number = get_magic_number(input);
        int w, h, max_rgb;

        input >> w;
        input >> h;
        input >> max_rgb;

        std::string s;
        std::getline(input, s);

        std::queue<Color> numbers = extract_numbers(input);

        std::cout << "Extraction de l'entête terminée" << std::endl;

        Color::Byte r, g, b;
        while (input >> std::noskipws >> r >> g >> b) {
            img.get_data().push_back(Color(r, g, b));
        }

        std::cout << "job's done !" << std::endl;

        img.w(w);
        img.h(h);

        std::cout << "Image extraite, w = " << w << ", h = " << h << ", max = " << max_rgb << ", size = " << img.get_data().size() << std::endl;
        return true;
    }

private:
    static std::queue<Color> extract_numbers(std::istream &input) {
        std::queue<Color> numbers;

        return numbers;
    }

    static std::string remove_comment(std::string line) {
        std::string::size_type n = line.find('#');
        if (n != std::string::npos)
            line.erase(n);

        return line;
    }

    static char get_magic_number(std::istream &input) {
        std::string line;
        int magic_number = -1;
        while (input >> line) {
            int find_pos = line.find('P');
            if (find_pos != std::string::npos) {
                return line[find_pos + 1];
            }
        }

        return -1;
    }
};

#endif //TP1_IMAGE2DREADER_H
