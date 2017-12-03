//
// Created by Meimei on 15/11/2017.
//

#ifndef TP1_INVERTREDBLUEFILTER_H
#define TP1_INVERTREDBLUEFILTER_H

#include <utility>

#include "Filter.h"
#include "Color.h"

class InvertRedBlueFilter : public Filter<Color> {
public:
    explicit InvertRedBlueFilter(Image2D<Color>& img)
            : m_img(img) {

    }

    void filter() override {
        for (Color& c: m_img) {
            swap(c.red, c.blue);
        }
    }

private:
    void swap(unsigned char& a, unsigned char& b) {
        unsigned char tmp = a;
        a = b;
        b = tmp;
    }

    Image2D<Color>& m_img;
};

#endif //TP1_INVERTREDBLUEFILTER_H
