//
//  Case.cpp
//  projet_cpp
//
//  Created by Grace on 03/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Case.hpp"

Case::Case(float x, float y) : posX(x), posY(y), width(C_SIZE), height(C_SIZE), empty(true) {}

Case::~Case() {}

void Case::draw() {
    GraphicPrimitives::drawFillRect2D(posX, posY, width, height, BLACK, G_C, BLACK);
}

// GETTERS et SETTERS
float Case::getX() { return posX; }
float Case::getY() { return posY; }
float Case::getWidth() { return width; }
float Case::getHeight() { return height; }

bool Case::isEmpty() { return empty; }

void Case::setX(float newX) { posX = newX; }
void Case::setY(float newY) { posY = newY; }
void Case::setEmpty(bool vide) { empty = vide; }
