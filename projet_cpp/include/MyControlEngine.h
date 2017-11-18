#pragma once
#include "Engine.h"
#include "Damier.hpp"
#include "Vaisseaux.hpp"
#include "Asteroids.hpp"
#include "Game.hpp"

class MyControlEngine:public ControlEngine {
    Game *menu_jeu;
    
    
    std::vector<Vaisseaux *> *vaisseaux;
    std::vector<Asteroids *> *asteroids;
    
    // position du curseur
    int cursor_x = 400;
    int cursor_y = 400;
    float cursor_x_f = 400.f;
    float cursor_y_f = 400.f;
    
public:
    /*float random_between_two_int(float min, float max);*/
    MyControlEngine(Game *menu_jeu, Damier *grille, std::vector<Vaisseaux *> *vaisseaux, std::vector<Asteroids *> *asteroids):menu_jeu(menu_jeu), grille(grille), vaisseaux(vaisseaux), asteroids(asteroids){}
    
    virtual void MouseCallback(int button, int state, int x, int y);
    virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
    
    Damier *grille;
    
    void ajouterVaisseaux(float x, float y);
    
    void act();
    
    /**
     true si le curseur est sur la grille de jeu,
     permet d'ajouter un vaisseaux
     */
    bool cursorInGrille(float x, float y);
};
