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

    static bool read(Image &img, std::istream &input) {
        std::string magic_number;
        int w, h, max;

        remove_comment(input);
        input >> magic_number;

        std::cout << "magic number: " << magic_number << std::endl;

        // width
        remove_comment(input);
        input >> w;

        // get h
        remove_comment(input);
        input >> h;

        std::cout << "w(" << w << ") h(" << h << ")" << std::endl;

        // get bits
        remove_comment(input);
        input >> max;

        img.w(w);
        img.h(h);

        if (magic_number == "P5")
        {
            Value v;
            //input.get();
            while(input >> std::noskipws >> v) {
                img.get_data().push_back(v);
            }

            //input.read((char*)&img.data[0], img.data.size() * 3);
        }
        else if (magic_number == "P2")
        {
            Value v;

            while(input >> v) {
                img.get_data().push_back(v);
            }
        }

        return true;
    }

private:
    static void remove_comment(std::istream &input)
    {
        char next_char = input.peek();
        while (next_char == '\n' || next_char == '\r') {
            input.get();
            next_char = input.peek();
        }

        if (next_char == '#') {
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};

template<>
class Image2DReader<Color> {
public:
    typedef Color Value;
    typedef Image2D<Value> Image;

    static bool read(Image &img, std::istream &input) {
        std::string magic_number;
        int w, h, max;

        remove_comment(input);
        input >> magic_number;

        // width
        remove_comment(input);
        input >> w;

        // get h
        remove_comment(input);
        input >> h;

        // get bits
        remove_comment(input);
        input >> max;

        std::string s;
        std::getline(input, s);

        img.w(w);
        img.h(h);

        if (magic_number == "P6")
        {
            Color::Byte r, g, b;
            //input.get();
            while(input >> std::noskipws >> r >> g >> b) {
                img.get_data().push_back(Color(r, g, b));
            }

            //input.read((char*)&img.data[0], img.data.size() * 3);
        }
        else if (magic_number == "P3")
        {
            Color::Byte r, g, b;

            while(input >> r >> g >> b) {
                img.get_data().push_back(Color(r, g, b));
            }
        }

        return true;
    }

private:
    static void remove_comment(std::istream &input)
    {
        char next_char = input.peek();
        while (next_char == '\n' || next_char == '\r') {
            input.get();
            next_char = input.peek();
        }

        if (next_char == '#') {
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};

/*
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
*/
#endif //TP1_IMAGE2DREADER_H
