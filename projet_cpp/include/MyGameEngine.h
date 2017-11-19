#pragma once

#include "Engine.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Asteroids.hpp"
#include "Game.hpp"

class MyGameEngine:public GameEngine {
    
    Game *menu_jeu;
    
    std::vector<Vaisseaux *> *vaisseaux;
    std::vector<Asteroids *> *asteroids;
    
    // position du curseur
    int cursor_x = 400;
    int cursor_y = 400;
    float cursor_x_f = 400.f;
    float cursor_y_f = 400.f;
    
public:
    
    MyGameEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux, std::vector<Asteroids *> *asteroids):menu_jeu(menu_jeu), grille(grille), vaisseaux(vaisseaux), asteroids(asteroids){}
    
    virtual void idle();
    
    Damier *grille;
    
    void move();
    void genererAsteroids();
    
};
