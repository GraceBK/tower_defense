#include "MyControlEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (menu_jeu->isStart()) {
            //
            if (menu_jeu->clic_home((x-CURSOR_X) / CURSOR_X_F, (y-CURSOR_Y)/ -CURSOR_Y_F)) {
                resetGrille();
            }
        } else {
            if (menu_jeu->clic_btn_play((x-CURSOR_X) / CURSOR_X_F, (y-CURSOR_Y)/ -CURSOR_Y_F)) {
                std::cout << "PLAY" << std::endl;
                menu_jeu->setStart(true);
                menu_jeu->setOver(false);
            }
        }
    }
}

void MyControlEngine::KeyboardReleaseCallback(unsigned char key, int x, int y) {
    if (menu_jeu->isStart()) {
        if (cursorInGrille((x-CURSOR_X) / CURSOR_X_F, (y-CURSOR_Y) / -CURSOR_Y_F)) {
            if (key == 'a') {
                if (menu_jeu->getBank() >= menu_jeu->getPrixV()) {
                    int case_index;
                    case_index = grille->mettre_vaissaux((x-CURSOR_X) / CURSOR_X_F, (y-CURSOR_Y) / -CURSOR_Y_F);
//                    std::cout << "======> " << case_index << std::endl;
                    if (case_index != -1) {
                        vaisseaux->push_back(new Vaisseaux(grille->getCase(case_index).getX(), grille->getCase(case_index).getY()));
                        menu_jeu->setBank(menu_jeu->getBank() - menu_jeu->getPrixV());
                    } else {}
                }
            }
            if (key == 'z') {
                std::cout << "VAISSEAU de type BOUMER" << std::endl;
                if (menu_jeu->getBank() >= menu_jeu->getPrixV1()) {
                    int case_index;
                    case_index = grille->mettre_vaissaux((x-CURSOR_X) / CURSOR_X_F, (y-CURSOR_Y) / -CURSOR_Y_F);
//                    std::cout << "======> " << case_index << std::endl;
                    if (case_index != -1) {
                        vaisseaux->push_back(new Vaisseaux1(grille->getCase(case_index).getX(), grille->getCase(case_index).getY()));
                        menu_jeu->setBank(menu_jeu->getBank() - menu_jeu->getPrixV1());
                    } else {}
                }
            }
            if (key == 'e') {
                std::cout << "VAISSEAU de type ATOMIC" << std::endl;
                if (menu_jeu->getBank() >= menu_jeu->getPrixV2()) {
                    int case_index;
                    case_index = grille->mettre_vaissaux((x-CURSOR_X) / CURSOR_X_F, (y-CURSOR_Y) / -CURSOR_Y_F);
//                    std::cout << "======> " << case_index << std::endl;
                    if (case_index != -1) {
                        vaisseaux->push_back(new Vaisseaux2(grille->getCase(case_index).getX(), grille->getCase(case_index).getY()));
                        menu_jeu->setBank(menu_jeu->getBank() - menu_jeu->getPrixV2());
                    } else {}
                }
            }
        }
        
        if (key == 'v') {
            std::cout << "LANCER VAGUE" << std::endl;
            if (!menu_jeu->isRunning()) {
                menu_jeu->setRunning(true);
            }
        }
        
        if (key == 'h') {
            std::cout << "Page HOME (HELP)" << std::endl;
            resetGrille();
        }
    }
}

bool MyControlEngine::cursorInGrille(float x, float y) {
    float posX(grille->getInitPosX()+0.4), posY(grille->getInitPosY()+0.105), w(grille->getCase(0).getWidth()+0.105*((grille->getWidth()/2)-1)), h(grille->getCase(0).getHeight()+0.105*(grille->getHeight()-1));
    if (x >= posX && x <= posX + w && y >= posY && y <= posY + h) {
        return true;
    } else {
        return false;
    }
}

void MyControlEngine::resetGrille() {
    for (int i = (int) vaisseaux->size() - 1; i >= 0; i--) {
        vaisseaux->erase(vaisseaux->begin() + i);
    }
    grille->reset_grille();
    for (int i = (int) asteroids->size() - 1; i >= 0; i--) {
        asteroids->erase(asteroids->begin() + i);
    }
    menu_jeu->setBank(BANK);
    menu_jeu->setRunning(false);
    menu_jeu->setOver(false);
    menu_jeu->setStart(false);
}
