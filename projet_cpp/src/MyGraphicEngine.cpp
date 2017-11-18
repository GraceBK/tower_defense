
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw() {
    if (menu_jeu->isOver() == false) {
        GraphicPrimitives::drawFillRect2D(-1, -1, 2.0f, 2.0f, 0, 0.098, 0);  //fond ecrant
        
        if (menu_jeu->isStart() == true) {
            // Si je suis dans le mode avec 1 ligne
            interface_player();
            
            grille->draw_();
            interface_vaisseaux();
            interface_boutons();
            
            for (int i(0); i < vaisseaux->size(); i++) {
                (*vaisseaux)[i]->draw();
            }
            
            for (int i(0); i < asteroids->size(); i++) {
                (*asteroids)[i]->draw();
            }
        } else if (menu_jeu->isStartN() == true) {
            // Si je suis dans le mode avec n lignes
            interface_player();
            
            grille->draw();
            interface_vaisseaux();
            interface_boutons();
            
            for (int i(0); i < vaisseaux->size(); i++) {
                (*vaisseaux)[i]->draw();
            }
            
            for (int i(0); i < asteroids->size(); i++) {
                (*asteroids)[i]->draw();
            }
            
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
    std::string v1 = "d = defaut - $ 20";
    std::string v2 = "b = boum - $ 30";
    std::string v3 = "a = atomic - $ 40";
    char * defaut = new char[v1.length() + 1];
    char * boum = new char[v2.length() + 1];
    char * atomic = new char[v3.length() + 1];
    
    std::strcpy(defaut, v1.c_str());
    std::strcpy(boum, v2.c_str());
    std::strcpy(atomic, v3.c_str());
    
    float x(-0.95), y(0.78), n(0.08);
    
    //GraphicPrimitives::drawFillRect2D(x, y, n, n, 0.298, 0.667, 0.361);
    GraphicPrimitives::drawFillTriangle2D(x, y, x+n, y+n/2, x, y+n, 0.298, 0.667, 0.361);
    GraphicPrimitives::drawText2D(defaut, x+0.12, y+0.02, 1.0, 1.0, 1.0);
    //GraphicPrimitives::drawFillRect2D(x, y-0.1, n, n, 0.69, 0.098, 0.11);
    GraphicPrimitives::drawFillTriangle2D(x, y-0.1, x+n, y-0.1+n/2, x, y-0.1+n, 0.69, 0.098, 0.11);
    GraphicPrimitives::drawText2D(boum, x+0.12, y-0.08, 1.0, 1.0, 1.0);
    //GraphicPrimitives::drawFillRect2D(x, y-0.2, n, n, 0.573, 0.173, 0.573);
    GraphicPrimitives::drawFillTriangle2D(x, y-0.2, x+n, y-0.2+n/2, x, y-0.2+n, 0.573, 0.173, 0.573);
    GraphicPrimitives::drawText2D(atomic, x+0.12, y-0.18, 1.0, 1.0, 1.0);
    
    //GraphicPrimitives::drawFillPolygone2D(<#std::vector<float> &x#>, <#std::vector<float> &y#>, 1.0, 1.0, 1.0);
    
    delete [] defaut;
    delete [] boum;
    delete [] atomic;
}

void MyGraphicEngine::interface_boutons() {
    menu_jeu->draw_home();
    menu_jeu->draw_btn_save();
    menu_jeu->draw_btn_run();
}





void MyGraphicEngine::interface_player() {
    float x(-0.95), y(0.93);
    char * towers = new char[7]{'T','O','W','E','R','S','\0'};
    char * stats = new char[6]{'S','T','A','T','S','\0'};
    
    char * bank = new char[5]{'B','A','N','K','\0'};
    char * score = new char[6]{'S','C','O','R','E','\0'};
    char * lives = new char[6]{'L','I','V','E','S','\0'};
    char * level = new char[6]{'L','E','V','E','L','\0'};
    
    
    // fond longueur
    GraphicPrimitives::drawFillRect2D(-1.0f, 0.5f, 2.0f, 0.4f, 0, 0.2, 0);
    // fond largeur
    GraphicPrimitives::drawFillRect2D(-1.0f, -1.0f, 0.55f, 2.0f, 0, 0.298, 0);
    
    GraphicPrimitives::drawText2D(towers, x, y, 1.0, 1.0, 1.0);
    GraphicPrimitives::drawText2D(stats, x + 0.55f, y, 1.0, 1.0, 1.0);
    
    GraphicPrimitives::drawText2D(bank, x + 0.55f, y - 0.13f, 0.0, 0.0, 0.0);
    GraphicPrimitives::drawText2D(score, x + 0.55f, y - 0.23f, 0.0, 0.0, 0.0);
    
    GraphicPrimitives::drawText2D(lives, x + 1.1f, y - 0.13f, 0.0, 0.0, 0.0);
    GraphicPrimitives::drawFillRect2D(x + 1.3f, y - 0.135f, 0.5f, 0.05f, 0.69, 0.098, 0.11);
    GraphicPrimitives::drawText2D(level, x + 1.1f, y - 0.23f, 0.0, 0.0, 0.0);
}
