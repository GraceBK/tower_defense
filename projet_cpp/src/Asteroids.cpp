//
//  Asteroids.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Asteroids.hpp"

Asteroids::Asteroids(float x, float y) : posX(x), posY(y) {}

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

bool Asteroids::touche(int type_missile) {
    if (type_missile == 1) {
        std::cout << "VAISO 1" << std::endl;
        return true;
    } else if (type_missile == 2) {
        std::cout << "VAISO 2" << std::endl;
        return true;
    } else {
        std::cout << "VAISO Default" << std::endl;
        return true;
    }
    return false;
}

void Asteroids::setX(float newX) { posX = posX - newX; }

void Asteroids::setR(float r_c) { r = r_c; }
void Asteroids::setG(float g_c) { g = g_c; }
void Asteroids::setB(float b_c) { b = b_c; }

void Asteroids::setVie(int v) { vie = vie - v; }
int Asteroids::getVie() { return vie; }

float Asteroids::getX() { return posX; }
float Asteroids::getY() { return posY; }

float Asteroids::getWidth() { return width; }
float Asteroids::getHeight() { return height; }
