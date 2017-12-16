#pragma once

#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "Engine.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Vaisseaux1.hpp"
#include "Vaisseaux2.hpp"
#include "Asteroids.hpp"
#include "Asteroids1.hpp"
#include "Asteroids2.hpp"
#include "Game.hpp"
#include "all_others.hpp"

class MyGameEngine:public GameEngine {
    
    Game *menu_jeu;
    
    std::vector<Vaisseaux *> *vaisseaux;
    std::vector<Asteroids *> *asteroids;
    
    int compteur_asteroides = 0;
    int vague = 1;
    
    // position du curseur
    int cursor_x = 400;
    int cursor_y = 400;
    float cursor_x_f = 400.f;
    float cursor_y_f = 400.f;
    
public:
    
    MyGameEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux, std::vector<Asteroids *> *asteroids):menu_jeu(menu_jeu), grille(grille), vaisseaux(vaisseaux), asteroids(asteroids) {
        srand(unsigned (time(NULL)));    // permet de generer un random semblable au precedent
    }
    
    virtual void idle();
    
    Damier *grille;
    
    void move();

    void startAsteroids(int nombre_asteroids);
    int my_random(int n);
    
    long int temps1 = time(0);
    long int temps2;
    
    float variation(float v1, float v2);
    
    float distance(float x1, float y1, float x2, float y2);
    
};
