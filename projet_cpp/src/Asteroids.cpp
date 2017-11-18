//
//  Asteroids.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Asteroids.hpp"

Asteroids::Asteroids(float x, float y) : posX(x), posY(y), width(0.09), height(0.09), r(1.0), g(1.0), b(1.0) {}

Asteroids::~Asteroids() {}

void Asteroids::draw() {
    GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
}

void Asteroids::move() {
    posX = posX - 0.01f;
}

void Asteroids::setX(float newX) { posX = posX - newX; }

void Asteroids::setR(float r_c) { r = r_c; }
void Asteroids::setG(float g_c) { g = g_c; }
void Asteroids::setB(float b_c) { b = b_c; }
