//
//  Asteroids.hpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Asteroids_hpp
#define Asteroids_hpp

#include <stdio.h>

class Asteroids {
    
public:
    Asteroids();
    ~Asteroids();
    
    void drawCase();
    
    void toString();
    
    // GETTERS et SETTERS
    
    
    float posX, posY, width, height;
    float r, g, b;
};

#endif /* Asteroids_hpp */
