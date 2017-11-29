//
//  Asteroids2.cpp
//  projet_cpp
//
//  Created by Grace on 21/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

//#include "Asteroids2.hpp"
#include "../include/Asteroids.hpp"
#include "../include/Asteroids2.hpp"

Asteroids2::Asteroids2(float x, float y) : Asteroids(x, y) {
    width = 0.1;
    height = 0.1;
    r = 0.69;
    g = 0.098;
    b = 0.11;
}

Asteroids2::~Asteroids2() {}
