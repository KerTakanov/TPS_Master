//
// Created by Meimei on 15/11/2017.
//

#ifndef TP1_FILTER_H
#define TP1_FILTER_H


#include "Image2D.h"

template<typename T>
class Filter {
public:
    Filter() { }

    explicit Filter(Image2D<T> img)
        : m_img(img) {
    }

    virtual void filter() = 0;

protected:
    Image2D<T> m_img;
};


#endif //TP1_FILTER_H
