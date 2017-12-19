//
//  Vaisseaux.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Vaisseaux.hpp"

Vaisseaux::Vaisseaux(float x, float y) : posX(x), posY(y), width(V_SIZE), height(V_SIZE), r(R_V), g(G_V), b(B_V), frequence(1), puissance(5), vitesse(0.01) {}

Vaisseaux::~Vaisseaux() {}

void Vaisseaux::draw() {
    GraphicPrimitives::drawFillTriangle2D(posX, posY, posX+0.1, posY+0.05, posX, posY+0.1, r, g, b);
    for (int i(0); i < missiles.size(); i++) {
        missiles[i]->draw(type);
    }
}

void Vaisseaux::tirer(std::vector<Asteroids *> *asteroids) {
    struct timeval t1, t2;
    gettimeofday(&t2, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
    temps2 = t2.tv_sec * TICK + t2.tv_usec;
    /** armement des missiles dans le canon */
    if ((temps2 - temps1) > frequence * TICK) {
        missiles.push_back(new Missile(posX, posY, vitesse, 1)); // j'arme
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
        temps1 = t1.tv_sec * TICK + t1.tv_usec;
    }
    /** missile arrive en bout de course */
    for (int i(0); i < missiles.size(); i++) {
        if (missiles[i]->posX >= 0.8f) {
            missiles.erase(missiles.begin());
        }
    }
    /** missile entre en collision avec un asteroise */
    for (int i(0); i < missiles.size(); i++) {
        for (int j(0); j < asteroids->size(); j++) {
            if (distance(missiles[i]->posX, missiles[i]->posY, (*asteroids)[j]->getX(), (*asteroids)[j]->getY()) < 0.05) {
                missiles.erase(missiles.begin());
                if (type == 1) {
                    (*asteroids)[j]->setVie(10);
                    (*asteroids)[j]->vitesse -= VITESSE_FREIN;
                    if ((*asteroids)[j]->vitesse <= 0) {
                        (*asteroids)[j]->vitesse = 0.005;
                    }
                } else if (type == 2) {
                    (*asteroids)[j]->setVie(100);
                } else {
                    (*asteroids)[j]->setVie(50);
                }
            }
        }
    }
}
                
float Vaisseaux::distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrtf((dx * dx) + (dy * dy));
}

void Vaisseaux::setR(float r_c) { r = r_c; }
void Vaisseaux::setG(float g_c) { g = g_c; }
void Vaisseaux::setB(float b_c) { b = b_c; }

float Vaisseaux::getY() { return posY; }
