
//#include "MyGameEngine.h"


#include "../include/MyGameEngine.h"

void MyGameEngine::idle(){
    if (!menu_jeu->isOver()) {
        if (menu_jeu->isStart()) {
            for (int i(0); i < vaisseaux->size(); i++) {
                (*vaisseaux)[i]->tirer(asteroids);
            }
//            grille->action();
            if (menu_jeu->isRunning()) {
                startAsteroids();
                move();
            }
        }
    }
}

void MyGameEngine::move() {
    for (int i(0); i < asteroids->size(); i++) {
        (*asteroids)[i]->move();
    }
}

void MyGameEngine::startAsteroids() {
    
    
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
    
//    std::cout << tab[rand()%grille->getHeight()] << std::endl;
    
    
    std::vector<float> my_vector;
    float posX((grille->getInitPosX()+0.4)+(grille->getCase(0).getWidth()+(0.105*(grille->getWidth()-1))));
    float y(grille->getInitPosY()+0.105);
    float y2 = y + grille->getCase(0).getHeight()+0.105*(11-1);
    // on met les points de depart des Asteroids dans my_vector
    
    struct timeval t1, t2;
    gettimeofday(&t2, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
    temps2 = t2.tv_sec * 1000000 + t2.tv_usec;
    /** choix ligne */
    if ((temps2 - temps1) > 0.9*1000000) {
        /** probabilite d'avoir des asteroids differents */
        int freq = (rand()%12);
        if (freq <= 2) {
            asteroids->push_back(new Asteroids1(posX, tab[rand()%grille->getHeight()]));
        } else {
            asteroids->push_back(new Asteroids(posX, tab[rand()%grille->getHeight()]));
        }
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l'horloge juste avant la boucle
        temps1 = t1.tv_sec * 1000000 + t1.tv_usec;
    }
    
    /** vitesse de deplacement des missiles */
    /*for (std::vector<Asteroids *>::iterator asteroid = asteroids->begin(); asteroid != asteroids->end(); asteroid++) {
//        std::cout << (*asteroid)->getX() << std::endl;
        if ((*asteroid)->getX() < -0.0f) {
            std::cout << "------------------" << (*asteroid)->getX() << std::endl;
        }
    }*/
    /** Collision Vaisseaux avec Asteroides */
    for (int i(0); i < vaisseaux->size(); i++) {
        for (int j(0); j < asteroids->size(); j++) {
            if (distance((*vaisseaux)[i]->posX, (*vaisseaux)[i]->posY, (*asteroids)[j]->posX, (*asteroids)[j]->posY) < 0.1) {
                std::cout << " BOUM " << std::endl;
                asteroids->erase(asteroids->begin() + j);
                vaisseaux->erase(vaisseaux->begin() + i);
            }
        }
    }
    
    /*for (std::vector<Asteroids *>::iterator asteroid = asteroids->begin(); asteroid != asteroids->end(); asteroid++) {
        std::cout << "------> " << (*asteroid)->getX() << std::endl;
        
    }*/
//    if (variation(<#float v1#>, <#float v2#>)) {
//        <#statements#>
//    }
//
//    for (int i(0); i < asteroids->size(); i++) {
//        std::cout << "Y - asto ------> " << (*asteroids)[i]->posY << std::endl;
//    }
    
    /** On supprime les asteroids une fois arrivee en fin de route */
    for (int i(0); i < asteroids->size(); i++) {
        if ((*asteroids)[i]->getX() < (grille->getInitPosX()+0.4)) {
            asteroids->erase(asteroids->begin() + i);
            menu_jeu->setVie(0.1f);
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
