//
// Created by Meimei on 23/10/2017.
//

#ifndef TP1_MEDIANFILTER_H
#define TP1_MEDIANFILTER_H


#include "GrayLevelImage2D.h"
#include "Image2D.h"

class MedianFilter {
public:

    MedianFilter();
    MedianFilter(Image2D<unsigned char> img, int mask_size);

    Image2D<unsigned char> apply();
private:
    void build_mask(int x, int y);
    unsigned char get_median();

    Image2D<unsigned char> m_img;
    std::vector<unsigned char> m_mask;
    int m_mask_size;
};


#endif //TP1_MEDIANFILTER_H
