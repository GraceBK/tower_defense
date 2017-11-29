//
//  Case.cpp
//  projet_cpp
//
//  Created by Grace on 03/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

//#include "Case.hpp"
#include "../include/Case.hpp"

Case::Case(float x, float y) : posX(x), posY(y), width(0.1), height(0.1), empty(true) {}

Case::~Case() {}

void Case::draw() {
    GraphicPrimitives::drawFillRect2D(posX, posY, width, height, 0, 0.2, 0);
}

void Case::draw_() {
    GraphicPrimitives::drawFillRect2D(posX, posY, width, height, 0.0, 0.5, 0.255);
}

void Case::toString() {
//    std::cout << "Case (" << posX << ", " << posY << ") --> " << isEmpty() << std::endl;
    std::cout << isEmpty() << " " << "type_vaisseau,"; // << std::endl;
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
