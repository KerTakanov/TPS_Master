//
// Created by Meimei on 18/10/2017.
//

#ifndef TP1_GRAYLEVELIMAGE2D_H
#define TP1_GRAYLEVELIMAGE2D_H


#include <vector>
#include <iostream>
#include <string>

typedef unsigned char GrayLevel;         // le type pour les niveaux de gris.

class GrayLevelImage2D {
public:
    typedef std::vector<GrayLevel> Container;// le type pour stocker les niveaux de gris de l'image.

    struct Iterator : public Container::iterator {
        Iterator( GrayLevelImage2D& Image, int x, int y );
    };

// Constructeur par défaut
    GrayLevelImage2D();

// Constructeur avec taille w x h. Remplit tout avec la valeur g (par défaut 0).
    GrayLevelImage2D(int w, int h, GrayLevel g = 0);

    //Accesseurs
    int w() const;
    int h() const;

    void set(int x, int y, GrayLevel v);

    GrayLevel  at(int i, int j) const;

    Iterator begin();  // pixel (0,0) -> le tout premier
    Iterator end();    // pixel (0,h) -> juste après le dernier (pareil que (w,h-1)).
    Iterator start( int x, int y );

    bool importPGM( std::istream & input );
    bool exportPGM( std::ostream & output, bool ascii_mode = true ) const;

private:
    int index(int x, int y) const;
    std::vector<GrayLevel> m_data; // mes données; évitera de faire les allocations dynamiques
    int m_width; // ma largeur
    int m_height; // ma hauteur

    bool is_comment(std::string line);
    std::string next_line(std::istream &input);
};


#endif //TP1_GRAYLEVELIMAGE2D_H
