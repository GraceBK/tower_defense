
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (menu_jeu->isStart()) {
            if (menu_jeu->clic_home((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                menu_jeu->setStart(false);
            }
            if (menu_jeu->clic_btn_save((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "SAVE: Vous avez clique sur la SAVE" << std::endl;
                grille->save();
            }
            if (menu_jeu->clic_btn_run((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "RUN: A l'attacque" << std::endl;
            }
        }
        if (menu_jeu->isStartN()) {
            //
            if (menu_jeu->clic_home((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                menu_jeu->setStartN(false);
            }
            if (menu_jeu->clic_btn_save((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "SAVE: Vous avez clique sur la SAVE" << std::endl;
                grille->save();
            }
            if (menu_jeu->clic_btn_run((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "RUN: A l'attacque" << std::endl;
            }
        } else {
            if (menu_jeu->clic_btn_one((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "Jeu sur 1 ligne" << std::endl;
                std::cout << "--> GO 1 ligne = " << menu_jeu->isStart() << std::endl;
                menu_jeu->setStart(true);
                std::cout << "--> GO 1 ligne == " << menu_jeu->isStart() << std::endl;
            }
            if (menu_jeu->clic_btn_multi((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "Jeu sur plusieurs ligne" << std::endl;
                std::cout << "--> GO multi = " << menu_jeu->isStartN() << std::endl;
                menu_jeu->setStartN(true);
                std::cout << "--> GO multi == " << menu_jeu->isStartN() << std::endl;
            }
            if (menu_jeu->clic_btn_load((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "Jeu chargé" << std::endl;
            }
            // Je quitte le jeu
            if (menu_jeu->clic_btn_exit((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "BYE BYE ;P" << std::endl;
                exit(0);
            }
        }
    }
}

void MyControlEngine::KeyboardReleaseCallback(unsigned char key, int x, int y) {
    if (key == 'd') {
        //int case_index;
        //case_index = grille->
        //vaisseaux->push_back(new Vaisseaux(grille->getCase(<#int x#>)))
    }
}
