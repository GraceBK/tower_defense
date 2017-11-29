//
//  Vaisseaux.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

//#include "Vaisseaux.hpp"

#include "../include/Vaisseaux.hpp"

Vaisseaux::Vaisseaux(float x, float y) : posX(x), posY(y), width(0.1), height(0.1), r(0.298), g(0.667), b(0.361), frequence(1), puissance(5), vitesse(0.01) {}

Vaisseaux::~Vaisseaux() {}

void Vaisseaux::draw() {
    GraphicPrimitives::drawFillTriangle2D(posX, posY, posX+0.1, posY+0.05, posX, posY+0.1, r, g, b);
    for (std::vector<float>::iterator missile = missiles.begin(); missile != missiles.end(); missile++) {
        if (type == 1) {
            // missile en T
            GraphicPrimitives::drawFillRect2D(*missile/*posX+0.11*/, posY+0.045, 0.05, 0.010, 0.69, 0.098, 0.11);
            GraphicPrimitives::drawFillRect2D(*missile/*posX+0.15*/, posY+0.025, 0.01, 0.05, 0.69, 0.098, 0.11);
        } else if (type == 2) {
            // missile en +
            GraphicPrimitives::drawFillRect2D(*missile/*posX+0.11*/, posY+0.045, 0.05, 0.010, 0.573, 0.173, 0.573);
            GraphicPrimitives::drawFillRect2D(*missile+0.02/*posX+0.13*/, posY+0.025, 0.01, 0.05, 0.573, 0.173, 0.573);
        } else {
            GraphicPrimitives::drawFillRect2D(*missile, posY+0.04, 0.05, 0.02, r, g, b);
        }
    }
}

void Vaisseaux::tirer() {
    struct timeval t1, t2;
    gettimeofday(&t2, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
    temps2 = t2.tv_sec * 1000000 + t2.tv_usec;
    /** armement des missiles dans le canon */
    if ((temps2 - temps1) > frequence * 1000000) {
        missiles.push_back(posX + width); // j'arme
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
        temps1 = t1.tv_sec * 1000000 + t1.tv_usec;
    }
    /** vitesse de deplacement des missiles */
    for (std::vector<float>::iterator missile = missiles.begin(); missile != missiles.end(); missile++) {
        *missile = *missile + 0.01;
    }
}

void Vaisseaux::setR(float r_c) { r = r_c; }
void Vaisseaux::setG(float g_c) { g = g_c; }
void Vaisseaux::setB(float b_c) { b = b_c; }
