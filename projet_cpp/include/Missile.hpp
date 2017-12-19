//
//  Missile.hpp
//  projet_cpp
//
//  Created by Grace on 12/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Missile_hpp
#define Missile_hpp

#pragma once
#include <stdio.h>
#include "GraphicPrimitives.h"
#include "all_others.hpp"

class Missile {
    
public:
    Missile(float x, float y, float vitesse, int type);
    
    void draw(int type);
    bool touche();
    
    void action();
    
    float posX, posY, width, height;
    float vitesse;
    int type;
    bool isAlive;
};

#endif /* Missile_hpp */
