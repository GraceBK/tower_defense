
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (menu_jeu->isStart()) {
            if (menu_jeu->clic_home((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                menu_jeu->setStart(false);
                // J'efface les vaisseaux
                for (int i = (int) vaisseaux->size() - 1; i >= 0; i--) {
                    vaisseaux->erase(vaisseaux->begin() + i);
                    grille->getCase(0).setEmpty(false);
                    std::cout << grille->getCase(i).isEmpty() << " -case- " << i << std::endl;
                }
                
            }
            if (menu_jeu->clic_btn_save((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "SAVE: Vous avez clique sur la SAVE" << std::endl;
                grille->save();
            }
            if (menu_jeu->clic_btn_run((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "RUN: A l'attacque" << std::endl;
                act();
            }
        }
        if (menu_jeu->isStartN()) {
            //
            if (menu_jeu->clic_home((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                menu_jeu->setStartN(false);
                // J'efface les vaisseaux
                for (int i = (int) vaisseaux->size() - 1; i >= 0; i--) {
                    vaisseaux->erase(vaisseaux->begin() + i);
                    grille->getCase(i).setEmpty(true);
                }
            }
            if (menu_jeu->clic_btn_save((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "SAVE: Vous avez clique sur la SAVE" << std::endl;
                grille->save();
            }
            if (menu_jeu->clic_btn_run((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "RUN: A l'attacque" << std::endl;
                act();
            }
        } else {
            if (menu_jeu->clic_btn_one((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "Jeu sur 1 ligne" << std::endl;
                std::cout << "--> GO 1 ligne " << menu_jeu->isStart() << menu_jeu->isStartN() << std::endl;
                menu_jeu->setStart(true);
                std::cout << "--> GO 1 ligne == " << menu_jeu->isStart() << menu_jeu->isStartN() << std::endl;
            }
            if (menu_jeu->clic_btn_multi((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f)) {
                std::cout << "Jeu sur plusieurs ligne" << std::endl;
                std::cout << "--> GO multi = " << menu_jeu->isStart() << menu_jeu->isStartN() << std::endl;
                menu_jeu->setStartN(true);
                std::cout << "--> GO multi == " << menu_jeu->isStart() << menu_jeu->isStartN() << std::endl;
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
    if (menu_jeu->isStart() || menu_jeu->isStartN()) {
        if (cursorInGrille((x-cursor_x) / cursor_x_f, (y-cursor_y) / -cursor_y_f)) {
            if (key == 'd') {
                int case_index;
                case_index = grille->mettre_vaissaux((x-cursor_x) / cursor_x_f, (y-cursor_y) / -cursor_y_f);
                std::cout << "======> " << case_index << std::endl;
                if (case_index != -1) {
                    vaisseaux->push_back(new Vaisseaux(grille->getCase(case_index).getX(), grille->getCase(case_index).getY()));
                } else {}
                
            }
        }
    }
}

void MyControlEngine::ajouterVaisseaux(float x, float y) {
//    int posX_ = (int) (x / grille->)
}

void MyControlEngine::act() {
//    float posX((grille->getInitPosX()+0.4)+(grille->getCase(0).getWidth()+(0.105*(12-1)))), y(grille->getInitPosY()+0.105), y2 = y + grille->getCase(0).getHeight()+0.105*(12-1);
    float posX((grille->getInitPosX()+0.4)+(grille->getCase(0).getWidth()+(0.105*(12-1)))), y(grille->getInitPosY()+0.105), y2 = y + grille->getCase(0).getHeight()+0.105*(11-1);
    //std::cout << "**********1******** " << posX << std::endl;
    /**
     On choisi aleatoirement la ligne de l'asteroide
     */
//    int alea = rand()%12;
    float alea = (y+1) + (((float) rand())/(float)RAND_MAX) * (y2-(y+1))/**()*/;
    std::cout << "**********1******** " << alea << std::endl;
//    float posY = grille->getInitPosY() + ((rand() % 8) -1) * 0.5;
    float posY = y + (alea * grille->getCase(0).getHeight()) + y2;//+((grille->getCase(0).getHeight()/2)+0.105);
    //float posY = (rand()/(double)RAND_MAX)*(y2-y)+y;
    /** la frequence (probabilite d'avoir des asteroides plus puissante */
    int frequence_creature = (rand() % 4);
    //if (frequence_creature != 0) {
    asteroids->push_back(new Asteroids(posX, ((-0.8)+0.01)));//0 = -0.79 //floorf(posY * 100) / 100));
    asteroids->push_back(new Asteroids(posX, ((-0.7)+0.015)));//1 = -0.685
    asteroids->push_back(new Asteroids(posX, ((-0.6)+0.02)));//2 = -0.58
    asteroids->push_back(new Asteroids(posX, ((-0.5)+0.025)));//3 = -0.475
    asteroids->push_back(new Asteroids(posX, ((-0.4)+0.03)));//4 = -0.37
    asteroids->push_back(new Asteroids(posX, ((-0.3)+0.035)));//5 = -0.265
    asteroids->push_back(new Asteroids(posX, ((-0.2)+0.04)));//6 = -0.16
    asteroids->push_back(new Asteroids(posX, ((-0.1)+0.045)));//7 = -0.055
    asteroids->push_back(new Asteroids(posX, ((0.0)+0.05)));//8 = 0.05
    asteroids->push_back(new Asteroids(posX, ((0.1)+0.055)));//9 = 0.155
    asteroids->push_back(new Asteroids(posX, ((0.2)+0.06)));//10 = 0.26
    asteroids->push_back(new Asteroids(posX, ((0.3)+0.065)));//11 = 0.365
    float y2a = y + grille->getCase(0).getHeight()+0.105*(11-1);
    float pos2Y = y2a;
    float pos2aY = y;
    
    asteroids->push_back(new Asteroids(posX-0.3, ((alea))));//4 = -0.37
//    asteroids->push_back(new Asteroids(posX-0.3, ((pos2aY))));//4 = -0.37
    //}
    std::cout << floorf(alea * 1000) / 1000 << " # "<< pos2Y <<" **********2******** " << floorf(posY * 1000) / 1000 << std::endl;
}
/*
float    MyControlEngine::random_between_two_int(float min, float max)
{
    return (min + 1) + (((float) rand()) / (float) RAND_MAX) * (max - (min + 1));
}
*/
bool MyControlEngine::cursorInGrille(float x, float y) {
//    float posX(grille->getInitPosX()+0.4), posY(grille->getInitPosY()+0.105), w(grille->getCase(0).getWidth()+0.105*(12-1)), h(grille->getCase(0).getHeight()+0.105*(12-1));
    float posX(grille->getInitPosX()+0.4), posY(grille->getInitPosY()+0.105), w(grille->getCase(0).getWidth()+0.105*((12/2)-1)), h(grille->getCase(0).getHeight()+0.105*(12-1));
    if (x >= posX && x <= posX + w && y >= posY && y <= posY + h) {
        std::cout << "GOOOOOOOOOOOOOOOOOOOD " << std::endl;
        return true;
    } else {
        std::cout << "-------------------------- " << std::endl;
        return false;
    }
}
