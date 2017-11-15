#pragma once

#include "Engine.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Game.hpp"

class MyGameEngine:public GameEngine {
    
    Game *menu_jeu;
    
    std::vector<Vaisseaux *> *vaisseaux;
    
public:
    
    MyGameEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux):menu_jeu(menu_jeu), grille(grille), vaisseaux(vaisseaux){}
    
    virtual void idle();
    
    Damier *grille;
    
};
