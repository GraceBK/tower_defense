#include "MyGameEngine.h"

void MyGameEngine::idle(){
    if (!menu_jeu->isOver()) {
        if (menu_jeu->isStart()) {
            for (int i(0); i < vaisseaux->size(); i++) {
                (*vaisseaux)[i]->tirer(asteroids);
                for (int y(0); y < ((*vaisseaux)[i])->missiles.size(); y++) {
                    ((*vaisseaux)[i])->missiles[y]->action();
                }
            }
            chargerVague();
            if (menu_jeu->isRunning()) {
                startAsteroids(NB_ASTO);
                move();
            }
        }
    }
}

void MyGameEngine::chargerVague()  {
    if ((compteur_asteroides <= 0) && (asteroids->size() <= 0)) {
        vague += 1;
        compteur_asteroides = NB_ASTO;
        menu_jeu->setRunning(false);
        if (vague > 2) {
            for (int i(0); i < asteroids->size(); i++) {
                (*asteroids)[i]->setVie(-200);
                if ((*asteroids)[i]->type == 1) {
                    (*asteroids)[i]->vitesse += VITESSE_AS1*2;
                } else if ((*asteroids)[i]->type == 2) {
                    (*asteroids)[i]->vitesse += VITESSE_AS1*3;
                } else {
                    (*asteroids)[i]->vitesse += VITESSE_AS1;
                }
            }
        } else if (vague > 4) {
            for (int i(0); i < asteroids->size(); i++) {
                (*asteroids)[i]->setVie(-500);
                if ((*asteroids)[i]->type == 1) {
                    (*asteroids)[i]->vitesse += VITESSE_AS2*2;
                } else if ((*asteroids)[i]->type == 2) {
                    (*asteroids)[i]->vitesse += VITESSE_AS2*3;
                } else {
                    (*asteroids)[i]->vitesse += VITESSE_AS2;
                }
            }
        }
    }
}

void MyGameEngine::move() {
    for (int i(0); i < asteroids->size(); i++) {
        (*asteroids)[i]->move();
    }
}

void MyGameEngine::startAsteroids(int nombre_asteroids) {
    
//    std::cout << "vague " << vague << " run " << menu_jeu->isRunning() << std::endl;
    
    
    float tab[grille->getHeight()];
    tab[0] = -0.79;
    tab[1] = -0.685;
    tab[2] = -0.58;
    tab[3] = -0.475;
    tab[4] = -0.37;
    tab[5] = -0.265;
    tab[6] = -0.16;
    tab[7] = -0.055;
    tab[8] = 0.05;
    tab[9] = 0.155;
    tab[10] = 0.26;
    tab[11] = 0.365;
    
    std::vector<float> my_vector;
    float posX((grille->getInitPosX()+0.4)+(grille->getCase(0).getWidth()+(0.105*(grille->getWidth()-1))));
    
    struct timeval t1, t2;
    gettimeofday(&t2, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
    temps2 = t2.tv_sec * TICK + t2.tv_usec;
    /** choix ligne */
    if (((temps2 - temps1) > 0.9*TICK) && (compteur_asteroides <= nombre_asteroids) && (compteur_asteroides > -3)) {
        /** probabilite d'avoir des asteroids differents */
        int freq = (rand()%12);
        if (freq <= 2) {
            int freqH = (rand()%12);
            if (freqH <= 2) {
                asteroids->push_back(new Asteroids2(posX, tab[rand()%grille->getHeight()]));
                compteur_asteroides -= 1;
            } else {
                asteroids->push_back(new Asteroids1(posX, tab[rand()%grille->getHeight()]));
                compteur_asteroides -= 1;
            }
        } else {
            asteroids->push_back(new Asteroids(posX, tab[rand()%grille->getHeight()]));
            compteur_asteroides -= 1;
        }
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
        temps1 = t1.tv_sec * TICK + t1.tv_usec;
    }
    
//    std::cout << "asto " << asteroids->size() << std::endl;
//    if (asteroids->size() == 0) {
//        menu_jeu->setRunning(false);
//    }
    
    /** Collision Vaisseaux avec Asteroides */
    for (int i(0); i < vaisseaux->size(); i++) {
        for (int j(0); j < asteroids->size(); j++) {
            if (distance((*vaisseaux)[i]->posX, (*vaisseaux)[i]->posY, (*asteroids)[j]->posX, (*asteroids)[j]->posY) < 0.1) {
                asteroids->erase(asteroids->begin() + j);
                vaisseaux->erase(vaisseaux->begin() + i);
            }
        }
    }
    
    /** On supprime les asteroids une fois arrivee en fin de route */
    for (int i(0); i < asteroids->size(); i++) {
        if ((*asteroids)[i]->getX() < (grille->getInitPosX()+0.4)) {
            asteroids->erase(asteroids->begin() + i);
            menu_jeu->setVie(0.1f);
        }
        if ((*asteroids)[i]->getVie() <= 0) {
            asteroids->erase(asteroids->begin() + i);
            menu_jeu->setBank(menu_jeu->getBank() + 20);
        }
    }
}

float MyGameEngine::variation(float v1, float v2) {
    return (v2 - v1) / v1 * 100;
}

int MyGameEngine::my_random(int n) {
    return std::rand() % n;
}

float MyGameEngine::distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrtf((dx * dx) + (dy * dy));
}
