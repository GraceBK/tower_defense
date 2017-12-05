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
#include <sys/time.h>
#include <ctime>
#include "GraphicPrimitives.h"

class Asteroids {
protected:
    float width = 0.09;
    float height = 0.09;
    
public:
    Asteroids(float x, float y);
    ~Asteroids();
    
    void draw();
    
    void toString();
    
    void move();
    
    // GETTERS et SETTERS
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    
    void setX(float newX);
    void setY(float newY);
    void setR(float r_c);
    void setG(float g_c);
    void setB(float b_c);
    
    
    float posX, posY;
    float vitesse = 0.0009;
    
    float r = 1.0;
    float g = 1.0;
    float b = 1.0;
    
    long int temps1 = time(0);
    long int temps2;
};

#endif /* Asteroids_hpp */
