//
//  Damier.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Damier.hpp"

Damier::Damier() {
    float x = pos_x_case_zero;
    float y = pos_y_case_zero;
    for (int i(0); i < taille; i++) {
        y = y + decalage;
        x = -0.4;
        for (int z(0); z < taille; z++) {
            grille.push_back(Case(x, y));
            x = x + decalage;
        }
    }
}

Damier::~Damier() {
    delete &grille;
}

void Damier::draw() {
    for (int i(0); i < grille.size(); i++) {
        grille[i].draw();
    }
}

void Damier::toString() {
    for (int i(0); i < grille.size(); i++) {
        grille[i].toString();
    }
}
