//
// Created by Meimei on 23/10/2017.
//

#include "MedianFilter.h"
#include <algorithm>

MedianFilter::MedianFilter() {

}

MedianFilter::MedianFilter(Image2D<unsigned char> img, int mask_size) :
    m_img(img),
    m_mask_size(mask_size)
{

}

void MedianFilter::build_mask(int x, int y) {
    m_mask = std::vector<unsigned char>((unsigned)(m_mask_size * 2 + 1));
    for (int i = x - m_mask_size; i <= x + m_mask_size; ++i) {
        for (int j = y - m_mask_size; j <= y + m_mask_size; ++j) {
            if (i >= 0 && j >= 0 && i < m_img.h() && j < m_img.w())
                m_mask.push_back((unsigned char) m_img.at(i, j));
        }
    }
    std::sort(m_mask.begin(), m_mask.end());
}

unsigned char MedianFilter::get_median() {
    return m_mask[(m_mask.size() + 1) / 2];
}

Image2D<unsigned char> MedianFilter::apply() {
    Image2D<unsigned char> w_img(m_img.w(), m_img.h());
    int i = 0;
    for (int x = 0; x < m_img.h(); ++x) {
        for (int y = 0; y < m_img.w(); ++y) {
            build_mask(x, y);
            w_img.at(x, y) = get_median();
            ++i;
        }
    }
    std::cout << std::endl << "i:" << i << std::endl;

    return w_img;
}

