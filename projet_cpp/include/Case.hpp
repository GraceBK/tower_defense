//
//  Case.hpp
//  projet_cpp
//
//  Created by Grace on 03/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Case_hpp
#define Case_hpp

#include <stdio.h>

#include "GraphicPrimitives.h"

class Case {
    float posX, posY, width, height;
    bool empty;
    
public:
    Case(float x, float y);
    ~Case();
    
    void draw();
    
    void toString();
    
    // GETTERS et SETTERS
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    
    bool isEmpty();
    
    void setX(float newX);
    void setY(float newY);
    
};

#endif /* Case_hpp */
