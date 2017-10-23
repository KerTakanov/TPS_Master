//
// Created by Meimei on 18/10/2017.
//

#include <sstream>
#include <cstring>
#include "GrayLevelImage2D.h"

GrayLevelImage2D::GrayLevelImage2D() :
    m_width(0), m_height(0), m_data(std::vector<GrayLevel>())
{

}

GrayLevelImage2D::GrayLevelImage2D(int w, int h, GrayLevel g) :
    m_width(w), m_height(h), m_data(std::vector<GrayLevel>((unsigned)(w*h), g))
{

}



//////////////////////// PRIVATE ////////////////////////
int GrayLevelImage2D::index(int x, int y) const {
    return y * w() + x;
}

int GrayLevelImage2D::h() const {
    return m_height;
}

int GrayLevelImage2D::w() const {
    return m_width;
}

GrayLevel GrayLevelImage2D::at(int i, int j) const {
    return m_data[index(i, j)];
}

GrayLevelImage2D::Iterator GrayLevelImage2D::begin() {
    return start(0, 0);
}

GrayLevelImage2D::Iterator GrayLevelImage2D::end() {
    return start(0, h());
}

GrayLevelImage2D::Iterator GrayLevelImage2D::start(int x, int y) {
    return GrayLevelImage2D::Iterator(*this, x, y);
}

GrayLevelImage2D::Iterator::Iterator(GrayLevelImage2D &Image, int x, int y) :
        Container::iterator(Image.m_data.begin() + Image.index(x, y))
{

}

bool GrayLevelImage2D::importPGM(std::istream &input) {
    if (!input.good()) {
        std::cout << "Erreur lors de la lecture du fichier !\n" << std::strerror(errno);
        return false;
    }

    std::string type;

    input >> type;
    std::cout << "type = " << type << std::endl;
    input >> m_width >> m_height;
    int max_size;
    input >> max_size;

    std::cout << m_width << ' ' << m_height << ' ' << max_size << std::endl;
    m_data = std::vector<GrayLevel>();

    bool binary = type == "P5";
    if (binary) {
        input >> std::noskipws;
        unsigned char c;
        while (input >> c)
            m_data.push_back(c);
    }

    std::cout << m_data.size();

    return true;
}

bool GrayLevelImage2D::exportPGM(std::ostream &output, bool ascii_mode) const {
    output << "P5\n" << m_width << ' ' << m_height << '\n' << 255 << '\n';
    for (auto it: m_data) {
        output << it;
    }
}

bool GrayLevelImage2D::is_comment(std::string line) {
    for (char c: line) {
        if (c == ' ')
            continue;
        return c == '#';
    }
    return false;
}

std::string GrayLevelImage2D::next_line(std::istream &input) {
    std::string line;
    while (std::getline(input, line)) {
        std::cout << "next_line = \n" << line << std::endl;
        if (is_comment(line))
            continue;
        return line;
    }

    return "";
}

void GrayLevelImage2D::set(int x, int y, GrayLevel v) {
    m_data[index(x, y)] = v;
}
