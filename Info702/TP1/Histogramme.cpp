//
// Created by MeiMei on 03/12/2017.
//

#include <iostream>
#include "Histogramme.h"

void Histogramme::init() {
    int nb_pixels = m_img.w() * m_img.h();
    m_h = std::vector<double>(255, 0);

    for (unsigned char pixel: m_img) {
        m_h[pixel]++;
    }

    double total = 0;
    for (double& val: m_h) {
        val /= nb_pixels;
        total += val;
        m_H.push_back(total);
    }
}

void Histogramme::egalise() {
    int count = 0;
    for (unsigned char& pixel: m_img) {
        count++;
        if (count%1000==0)
            std::cout << count << "/" << m_img.w() * m_img.h() << std::endl;
        pixel = (unsigned char) (m_H[pixel] * 255.0);
    }
}
