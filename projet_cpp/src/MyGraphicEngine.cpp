#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw() {
//    if (menu_jeu->isOver() == false) {
    GraphicPrimitives::drawFillRect2D(-1, -1, 2.0f, 2.0f, BLACK, 0.098, BLACK);  //fond ecrant
        
    if (menu_jeu->inHelp() == true) {
        // Si je suis dans HELP
        menu_jeu->draw_home();
        
    } else if (menu_jeu->isStart() == true) {
        if (menu_jeu->getVie() < 0.5f) {
            // Si je suis dans PLAY
            interface_player();
            
            menu_jeu->show_stats();
            
            grille->draw();
            interface_vaisseaux();
            interface_boutons();
            int nb_tire = 0;
            for (int i(0); i < vaisseaux->size(); i++) {
                (*vaisseaux)[i]->draw();
//                for (int y(0); y < ((*vaisseaux)[i])->missiles.size(); y++) {
//                    //((*vaisseaux)[i])->missiles[y]->action();
////                    ((*vaisseaux)[i])->missiles[y]->draw();
//                    nb_tire += ((*vaisseaux)[i])->missiles.size();
//                }
            }
                
            for (int i(0); i < asteroids->size(); i++) {
                (*asteroids)[i]->draw();
            }
        } else {
            menu_jeu->drawGameOver();
        }
    } else {
        // Je reste dans le MENU (page d'ACCEUIL)
        menu_jeu->draw();
    }
}

void MyGraphicEngine::interface_vaisseaux() {
    std::string v1 = "a = $ 50";
    std::string v2 = "z = $ 100";
    std::string v3 = "e = $ 500";
    char * defaut = new char[v1.length() + 1];
    char * boum = new char[v2.length() + 1];
    char * atomic = new char[v3.length() + 1];
    
    strcpy(defaut, v1.c_str());
    strcpy(boum, v2.c_str());
    strcpy(atomic, v3.c_str());
    
    float x(-0.4), y(0.7), n(0.08);
    
    GraphicPrimitives::drawFillTriangle2D(x, y, x+n, y+n/2, x, y+n, R_V, G_V, B_V);
    GraphicPrimitives::drawText2D(defaut, x+MGE_IV_X, y+MGE_IV_Y, WHITE, WHITE, WHITE);
    
    GraphicPrimitives::drawFillTriangle2D(x+0.4, y, x+0.4+n, y+n/2, x+0.4, y+n, R_V1, G_V1, B_V1);
    GraphicPrimitives::drawText2D(boum, x+0.4+MGE_IV_X, y+MGE_IV_Y, WHITE, WHITE, WHITE);
    
    GraphicPrimitives::drawFillTriangle2D(x+0.8, y, x+0.8+n, y+n/2, x+0.8, y+n, R_V2, G_V2, B_V2);
    GraphicPrimitives::drawText2D(atomic, x+0.8+MGE_IV_X, y+MGE_IV_Y, WHITE, WHITE, WHITE);
    
    delete [] defaut;
    delete [] boum;
    delete [] atomic;
}

void MyGraphicEngine::interface_boutons() {
    menu_jeu->draw_home();
    menu_jeu->draw_btn_run();
}

void MyGraphicEngine::interface_player() {
    float x(-0.95), y(0.95);
    char * bank = new char[5]{'B','A','N','K','\0'};
    char * score = new char[6]{'S','C','O','R','E','\0'};
    char * lives = new char[6]{'L','I','V','E','S','\0'};
    char * level = new char[6]{'L','E','V','E','L','\0'};
    
    GraphicPrimitives::drawFillRect2D(-1.0f, 0.6f, 2.0f, 0.4f, BLACK, G_C, BLACK);  // fond longueur
    GraphicPrimitives::drawText2D(bank, x + 0.55f, y - 0.005f, BLACK, BLACK, BLACK);
    GraphicPrimitives::drawText2D(score, x + 0.55f, y - 0.1f, BLACK, BLACK, BLACK);
    GraphicPrimitives::drawText2D(lives, x + 1.1f, y - 0.005f, BLACK, BLACK, BLACK);
    GraphicPrimitives::drawFillRect2D(x + 1.3f, y - 0.013f, 0.5f - menu_jeu->getVie(), 0.05f, 0.69, 0.098, 0.11);
    GraphicPrimitives::drawText2D(level, x + 1.1f, y - 0.1f, BLACK, BLACK, BLACK);
}
