//
//  Vaisseaux.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Vaisseaux.hpp"

Vaisseaux::Vaisseaux(float x, float y) : posX(x), posY(y), width(0.1), height(0.1), r(0.298), g(0.667), b(0.361), frequence(1), puissance(5), vitesse(0.01) {}

Vaisseaux::~Vaisseaux() {}

void Vaisseaux::draw() {
    GraphicPrimitives::drawFillTriangle2D(posX, posY, posX+0.1, posY+0.05, posX, posY+0.1, r, g, b);
    for (std::vector<float>::iterator missile = missiles.begin(); missile != missiles.end(); missile++) {
        if (type == 1) {
            // missile en T
            GraphicPrimitives::drawFillRect2D(*missile/*posX+0.11*/, posY+0.045, 0.05, 0.010, 0.69, 0.098, 0.11);
            GraphicPrimitives::drawFillRect2D(*missile/*posX+0.15*/, posY+0.025, 0.01, 0.05, 0.69, 0.098, 0.11);
        } else if (type == 2) {
            // missile en +
            GraphicPrimitives::drawFillRect2D(*missile/*posX+0.11*/, posY+0.045, 0.05, 0.010, 0.573, 0.173, 0.573);
            GraphicPrimitives::drawFillRect2D(*missile+0.02/*posX+0.13*/, posY+0.025, 0.01, 0.05, 0.573, 0.173, 0.573);
        } else {
            GraphicPrimitives::drawFillRect2D(*missile, posY+0.04, 0.05, 0.02, r, g, b);
        }
    }
}

void Vaisseaux::tirer(std::vector<Asteroids *> *asteroids) {
    struct timeval t1, t2;
    gettimeofday(&t2, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
    temps2 = t2.tv_sec * 1000000 + t2.tv_usec;
    /** armement des missiles dans le canon */
    if ((temps2 - temps1) > frequence * 1000000) {
        missiles.push_back(posX + width); // j'arme
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
        temps1 = t1.tv_sec * 1000000 + t1.tv_usec;
    }
    /** vitesse de deplacement des missiles */
    for (std::vector<float>::iterator missile = missiles.begin(); missile != missiles.end(); missile++) {
        *missile = *missile + vitesse;
        
        /**
         COLLISION Asteroide et Missile
         Si la distance entre posY (position du vaisseau) et getY de l'asteroids est comprise entre [0, 0.009] donc le missile et l'asteroid sont sur la meme trajectoire
            Si la distance entre *missile et getX de l'asteroids est comprise entre [0, 0.009] donc il y a touché sa cible
         */
        
//        std::cout << missiles.size() << std::endl;
        
        for (int i(0); i < asteroids->size(); i++) {
            if (distance(*missile, posY, (*asteroids)[i]->getX(), (*asteroids)[i]->getY()) < 0.05) {
                std::cout << "Touché " << i << " " << missiles.size() << std::endl;
                
                if (type == 1) {
                    // missile en T
                    std::cout << "T " << i << std::endl;
                    (*asteroids)[i]->setVie(5);
                } else if (type == 2) {
                    // missile en +
                    std::cout << "+ " << i << std::endl;
                    (*asteroids)[i]->setVie(100);
                } else {
                    std::cout << "n " << i << std::endl;
                    (*asteroids)[i]->setVie(5);
                }
                
                
                /*if ((*asteroids)[i]->getVie() <= 0) {
                    atteint = true;
                }*/
                
                
                
//                missiles.erase(missiles.begin());
//                for (int j(0); j < missiles.size(); j++) {
//                    missiles.erase(missiles.begin() + j);
//                    if (missiles.size() != 0) {
//                        missiles.erase(missile);
//                    }
//                    missiles.erase(missiles.begin());
//                }
            }
            /*if ((*asteroids)[i]->getX() < 0.0f) {
                std::cout << "------------------" << (*asteroids)[1]->getY() << std::endl;
            }*/
        }
        
        /*
         if (distance(*missie, posY, (*asteoids)[i]->getX(), (*asteoids)[i]->getY() < 0.05) {
            std::cout << "Touché" << std::endl;
         }
         */
        
        /*for (int i(0); i < asteroids->size(); i++) {
            if ((*asteroids)[i]->getX() < 0.0f) {
                std::cout << "------------------" << (*asteroids)[1]->getY() << std::endl;
            }
        }*/
        
//        std::cout << "------>ASTE " << (*asteroids)[1]->getY() << std::endl;
    }
//    std::cout << "------> " << posY << std::endl;
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
