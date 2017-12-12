#pragma once
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

class MyControlEngine:public ControlEngine {
    Game *menu_jeu;
    
    std::vector<Vaisseaux *> *vaisseaux;
    std::vector<Asteroids *> *asteroids;
    
public:
    MyControlEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux, std::vector<Asteroids *> *asteroids):menu_jeu(menu_jeu), grille(grille), vaisseaux(vaisseaux), asteroids(asteroids){}
    
    virtual void MouseCallback(int button, int state, int x, int y);
    virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
    
    Damier *grille;
    /**
     * cette fonction remet la grille a zero
     * il remet toute les cases a zero afin de permettre
     * l'ajout des vaisseaux quand on change la grille
     */
    void resetGrille();
    /**
     true si le curseur est sur la grille de jeu,
     permet d'ajouter un vaisseaux
     */
    bool cursorInGrille(float x, float y);
};
