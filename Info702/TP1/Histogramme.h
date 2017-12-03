//
// Created by MeiMei on 03/12/2017.
//

#ifndef TP1_HISTOGRAMME_H
#define TP1_HISTOGRAMME_H


#include "Image2D.h"

class Histogramme {
public:
    Histogramme(Image2D<unsigned char>& img)
            : m_img(img) { }

    void init();
    void egalise();

private:
    Image2D<unsigned char> m_img;
    std::vector<double> m_h;
    std::vector<double> m_H;
};


#endif //TP1_HISTOGRAMME_H
