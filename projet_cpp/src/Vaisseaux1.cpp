//
//  Vaisseaux1.cpp
//  projet_cpp
//
//  Created by Grace on 21/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

//#include "Vaisseaux1.hpp"

#include "../include/Vaisseaux.hpp"
#include "../include/Vaisseaux1.hpp"

Vaisseaux1::Vaisseaux1(float x, float y) : Vaisseaux(x, y) {
    width = 0.1;
    height = 0.1;
    r = 0.69;
    g = 0.098;
    b = 0.11;
}

Vaisseaux1::~Vaisseaux1() {}
