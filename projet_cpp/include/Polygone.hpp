//
//  Polygone.h
//  projet_cpp
//
//  Created by Grace on 05/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Polygone_h
#define Polygone_h

#include <stdio.h>

class Polygone {
    float r, g, b;
    float x, y;
    float taille;
    
public:
    Polygone();
    Polygone(float x, float y, int cote, float taille, float r, float g, float b);
    
    float getX();
    float getY();
    
    void draw();
};

#endif /* Polygone_h */
