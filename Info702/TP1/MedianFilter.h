//
// Created by Meimei on 23/10/2017.
//

#ifndef TP1_MEDIANFILTER_H
#define TP1_MEDIANFILTER_H


#include "GrayLevelImage2D.h"

class MedianFilter {
public:

    MedianFilter();
    MedianFilter(GrayLevelImage2D img, int mask_size);

    GrayLevelImage2D apply();
private:
    void build_mask(int x, int y);
    GrayLevel get_median();

    GrayLevelImage2D m_img;
    std::vector<GrayLevel> m_mask;
    int m_mask_size;
};


#endif //TP1_MEDIANFILTER_H
