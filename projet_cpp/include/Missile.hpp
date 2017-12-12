//
//  Missile.hpp
//  projet_cpp
//
//  Created by Grace on 12/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Missile_hpp
#define Missile_hpp

#include <stdio.h>

class Missile {
    
public:
    Missile();
    ~Missile();
    
    void draw();
    
    float posX, posY;
};

#endif /* Missile_hpp */
