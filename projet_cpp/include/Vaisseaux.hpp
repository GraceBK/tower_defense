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

#include "GraphicPrimitives.h"

class Vaisseaux {
    
public:
    Vaisseaux(float x, float y);
    ~Vaisseaux();
    
    void draw();
    
    void toString();
    void tirer();
    
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
    std::vector<float> missile;
};

#endif /* Vaisseaux_hpp */
