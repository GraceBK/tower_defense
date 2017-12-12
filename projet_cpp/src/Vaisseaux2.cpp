//
//  Vaisseaux2.cpp
//  projet_cpp
//
//  Created by Grace on 21/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Vaisseaux2.hpp"

Vaisseaux2::Vaisseaux2(float x, float y) : Vaisseaux(x, y) {
    r = R_V2;
    g = G_V2;
    b = B_V2;
    type = 2;
    frequence = 4;
}

Vaisseaux2::~Vaisseaux2() {}
