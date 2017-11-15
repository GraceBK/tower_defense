
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw() {
    if (menu_jeu->isOver() == false) {
        
        if (menu_jeu->isStart() == true) {
            // Si je suis dans le mode avec 1 ligne
            grille->draw_();
            interface_vaisseaux();
            interface_boutons();
        } else if (menu_jeu->isStartN() == true) {
            // Si je suis dans le mode avec n lignes
            grille->draw();
            interface_vaisseaux();
            interface_boutons();
        } else {
            menu_jeu->draw();
        }
        
        
    } else {
        // si c'est Game Over j'affiche le message Game Over ensuite je retourne normalement au menu
        menu_jeu->drawGameOver();
    }
//    menu_jeu->draw();
    //grille->draw();
    
    for (int i(0); i < vaisseaux->size(); i++) {
        (*vaisseaux)[i]->draw();
    }
}



void MyGraphicEngine::interface_vaisseaux() {
    std::string v1 = "d = defaut 20";
    std::string v2 = "b = boum 30";
    std::string v3 = "a = atomic 40";
    char * defaut = new char[v1.length() + 1];
    char * boum = new char[v2.length() + 1];
    char * atomic = new char[v3.length() + 1];
    
    std::strcpy(defaut, v1.c_str());
    std::strcpy(boum, v2.c_str());
    std::strcpy(atomic, v3.c_str());
    
    float x(0.55), y(0.9), n(0.08);
    
    GraphicPrimitives::drawFillRect2D(x, y, n, n, 0.298, 0.667, 0.361);
    GraphicPrimitives::drawText2D(defaut, x+0.12, y, 1.0, 1.0, 1.0);
    GraphicPrimitives::drawFillRect2D(x, y-0.1, n, n, 0.69, 0.098, 0.11);
    GraphicPrimitives::drawText2D(boum, x+0.12, y-0.1, 1.0, 1.0, 1.0);
    GraphicPrimitives::drawFillRect2D(x, y-0.2, n, n, 0.573, 0.173, 0.573);
    GraphicPrimitives::drawText2D(atomic, x+0.12, y-0.2, 1.0, 1.0, 1.0);
    
    delete [] defaut;
    delete [] boum;
    delete [] atomic;
}

void MyGraphicEngine::interface_boutons() {
    menu_jeu->draw_home();
    menu_jeu->draw_btn_save();
    menu_jeu->draw_btn_run();
}
