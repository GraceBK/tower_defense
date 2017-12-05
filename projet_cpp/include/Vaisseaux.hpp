//
//  Vaisseaux.hpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Vaisseaux_hpp
#define Vaisseaux_hpp

#include <stdio.h>
#include <sys/time.h>
//#include <list>
#include <ctime>

#include "GraphicPrimitives.h"
#include "Asteroids.hpp"

class Vaisseaux {
    
public:
    Vaisseaux(float x, float y);
    ~Vaisseaux();
    
    void draw();
    
    void toString();
    void tirer(std::vector<Asteroids *> *asteroids);
    
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
    
    
    float posX, posY, width, height;
    float r, g, b;
    std::vector<float> missiles;
    double frequence;  // la frequence de tire
    int puissance;  // la puissance du tire
    float vitesse;    // la vitesse de  deplacement du tire
    int type;
    int prix = 10;
    
    long int temps1 = time(0);
    long int temps2;
};

#endif /* Vaisseaux_hpp */
