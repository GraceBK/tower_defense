#pragma once
#include <string>
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Game.hpp"

class MyGraphicEngine:public GraphicEngine {
    
    //std::vector<Papillon * > *paps;
    Game *menu_jeu;
    
    Damier *grille;
    std::vector<Vaisseaux *> *vaisseaux;
    
    char * str;
public:
    
    MyGraphicEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux) :
        /*paps(paps_),*/
    /*str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}),*/
    menu_jeu(menu_jeu),
    grille(grille),
    vaisseaux(vaisseaux)
        {}
    
    float x1,x2,vx1,vx2;
    
    virtual void Draw();
    
    
    void interface_vaisseaux();
    void interface_boutons();
    void interface_player();
    
};
