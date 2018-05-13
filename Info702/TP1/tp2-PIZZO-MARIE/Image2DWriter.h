//
// Created by Meimei on 14/11/2017.
//

#ifndef TP1_IMAGE2DWRITER_H
#define TP1_IMAGE2DWRITER_H


#include <iostream>
#include <string>
#include "Color.h"
#include "Image2D.h"
template <typename TValue>
class Image2DWriter {
public:
    typedef TValue Value;
    typedef Image2D<Value> Image;
    static bool write( Image & img, std::ostream & output, bool ascii )
    {
        std::cerr << "[Image2DWriter<TValue>::write] NOT IMPLEMENTED." << std::endl;
        return false;
    }
};
/// Specialization for gray-level images.
template <>
class Image2DWriter<unsigned char> {
public:
    typedef unsigned char Value;
    typedef Image2D<Value> Image;
    static bool write( Image & img, std::ostream & output, bool ascii )
    {
        output << (ascii ? "P2\n" : "P5\n") << img.w() << " " << img.h() << "\n255\n";
        for (unsigned char val: img) {
            if (ascii) {
                output << (int) val <<  ' ';
            }
            else
                output << val;
        }
    }
};
/// Specialization for color images.
template <>
class Image2DWriter<Color> {
public:
    typedef Color Value;
    typedef Image2D<Value> Image;
    static bool write( Image & img, std::ostream & output, bool ascii )
    {
        if (ascii)
            output << "P3" << std::endl;
        else
            output << "P6" << std::endl;

        output << img.w() << " " << img.h() << std::endl;
        output << "255\n";

        Color lastcol;

        for ( Image2D<Color>::Iterator it = img.begin(), itE = img.end(); it != itE; ++it ) // (*)
        {
            Color c = *it;
            if (ascii)
                output << (int) c.red << ' ' << (int) c.green << ' ' << (int) c.blue << ' ';
            else
                output << c.red << c.green << c.blue;
        }
    }
};

#endif //TP1_IMAGE2DWRITER_H
