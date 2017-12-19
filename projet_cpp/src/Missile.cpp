//
//  Missile.cpp
//  projet_cpp
//
//  Created by Grace on 12/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Missile.hpp"

Missile::Missile(float x, float y, float vitesse, int type) : posX(x), posY(y), vitesse(vitesse), type(type), isAlive(true) {}

void Missile::draw(int type) {
    if (type == 1) {
        GraphicPrimitives::drawFillRect2D(posX, posY+0.045, 0.05, 0.01, R_V1, G_V1, B_V1);
        GraphicPrimitives::drawFillRect2D(posX, posY+0.025, 0.01, 0.05, R_V1, G_V1, B_V1);
    } else if (type == 2) {
        GraphicPrimitives::drawFillRect2D(posX, posY+0.045, 0.05, 0.01, R_V2, G_V2, B_V2);
        GraphicPrimitives::drawFillRect2D(posX+0.02, posY+0.025, 0.01, 0.05, R_V2, G_V2, B_V2);
    } else {
        GraphicPrimitives::drawFillRect2D(posX, posY+0.05, 0.05, 0.01, R_V, G_V, B_V);
    }
}

void Missile::action() {
    posX += vitesse;
    if (posX <= -0.5f) {
        isAlive = false;
    }
}
