//
//  Asteroids.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

//#include "Asteroids.hpp"
#include "../include/Asteroids.hpp"

Asteroids::Asteroids(float x, float y) : posX(x), posY(y), width(0.09), height(0.09), r(1.0), g(1.0), b(1.0), vitesse(0.0009) {}

Asteroids::~Asteroids() {}

void Asteroids::draw() {
    GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
    
}

void Asteroids::move() {
    struct timeval t1, t2;
    gettimeofday(&t2, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
    temps2 = t2.tv_sec * 1000000 + t2.tv_usec;
    /** armement des missiles dans le canon */
    if ((temps2 - temps1) > 1000000) {
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
        temps1 = t1.tv_sec * 1000000 + t1.tv_usec;
    }
    /** vitesse de deplacement des missiles */
    
    posX = posX - vitesse*1;
}

void Asteroids::setX(float newX) { posX = posX - newX; }

void Asteroids::setR(float r_c) { r = r_c; }
void Asteroids::setG(float g_c) { g = g_c; }
void Asteroids::setB(float b_c) { b = b_c; }

float Asteroids::getX() { return posX; }
float Asteroids::getY() { return posY; }
