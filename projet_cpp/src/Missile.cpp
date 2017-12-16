//
//  Missile.cpp
//  projet_cpp
//
//  Created by Grace on 12/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Missile.hpp"

Missile::Missile(float x, float y, float vitesse, int type) : posX(x), posY(y), vitesse(vitesse), type(type), isAlive(true) {}

void Missile::draw() {
    GraphicPrimitives::drawFillRect2D(posX, posY+0.04, 0.05, 0.02, 0.0, 0.0, 0.0);
}

void Missile::action() {
    posX += vitesse;
    if (posX <= -0.5f) {
        isAlive = false;
    }
}
