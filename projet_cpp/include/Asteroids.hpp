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
#include "all_others.hpp"

class Asteroids {
protected:
    float width = A_SIZE;
    float height = A_SIZE;
    int vie = 100;
    
public:
    Asteroids(float x, float y);
    ~Asteroids();
    
    void draw();
    
    void toString();
    
    void move();
    bool touche(int type_missile);
    
    // GETTERS et SETTERS
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    
    int getVie();
    
    void setX(float newX);
    void setY(float newY);
    void setR(float r_c);
    void setG(float g_c);
    void setB(float b_c);
    
    void setVie(int v);
    
    float posX, posY;
    float vitesse = 0.0009;
    
    float r = WHITE;
    float g = WHITE;
    float b = WHITE;
    
    long int temps1 = time(0);
    long int temps2;
};

#endif /* Asteroids_hpp */
