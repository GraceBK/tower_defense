#pragma once
#include <string>
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Game.hpp"
#include "Asteroids.hpp"

class MyGraphicEngine:public GraphicEngine {
    Game *menu_jeu;
    Damier *grille;
    std::vector<Vaisseaux *> *vaisseaux;
    std::vector<Asteroids *> *asteroids;
    
    char * str;
public:
    
    MyGraphicEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux, std::vector<Asteroids *> *asteroids) :
    menu_jeu(menu_jeu),
    grille(grille),
    vaisseaux(vaisseaux),
    asteroids(asteroids) {}
    
    float x1,x2,vx1,vx2;
    
    virtual void Draw();
    
    void interface_vaisseaux();
    void interface_boutons();
    void interface_player();
};
