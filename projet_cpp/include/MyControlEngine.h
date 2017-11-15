#pragma once
#include "Engine.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Game.hpp"

class MyControlEngine:public ControlEngine {
    Game *menu_jeu;
    
    
    std::vector<Vaisseaux *> *vaisseaux;
    
    // position du curseur
    int cursor_x = 400;
    int cursor_y = 400;
    float cursor_x_f = 400.f;
    float cursor_y_f = 400.f;
    
public:
    MyControlEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux):menu_jeu(menu_jeu), grille(grille), vaisseaux(vaisseaux){}
    
    virtual void MouseCallback(int button, int state, int x, int y);
    virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
    
    Damier *grille;
};
