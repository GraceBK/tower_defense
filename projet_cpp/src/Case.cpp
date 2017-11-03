//
//  Case.cpp
//  projet_cpp
//
//  Created by Grace on 03/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Case.hpp"

Case::Case(float x, float y) : posX(x), posY(y), width(0.1), height(0.1), empty(true) {}

Case::~Case() {}

void Case::drawCase() {
    GraphicPrimitives::drawFillRect2D(posX, posY, width, height, 0.122, 0.224, 0.255);
}


// GETTERS et SETTERS
float Case::getX() { return posX; }
float Case::getY() { return posY; }
float Case::getWidth() { return width; }
float Case::getHeight() { return height; }

bool Case::isEmpty() { return empty; }

void Case::setX(float newX) { posX = newX; }
void Case::setY(float newY) { posY = newY; }
