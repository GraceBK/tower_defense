//
//  Vaisseaux1.cpp
//  projet_cpp
//
//  Created by Grace on 21/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Vaisseaux1.hpp"

Vaisseaux1::Vaisseaux1(float x, float y) : Vaisseaux(x, y) {
    r = R_V1;
    g = G_V1;
    b = B_V1;
    type = 1;
    frequence = 2;
}

Vaisseaux1::~Vaisseaux1() {}
