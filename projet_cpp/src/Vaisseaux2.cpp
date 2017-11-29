//
//  Vaisseaux2.cpp
//  projet_cpp
//
//  Created by Grace on 21/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

//#include "Vaisseaux2.hpp"

#include "../include/Vaisseaux.hpp"
#include "../include/Vaisseaux2.hpp"

Vaisseaux2::Vaisseaux2(float x, float y) : Vaisseaux(x, y) {
    width = 0.1;
    height = 0.1;
    r = 0.573;
    g = 0.173;
    b = 0.573;
    type = 2;
    frequence = 4;
}

Vaisseaux2::~Vaisseaux2() {}
