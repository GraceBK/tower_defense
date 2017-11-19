
#include "MyGameEngine.h"


void MyGameEngine::idle(){
    if (menu_jeu->isOver() == false) {
        move();
    }
}

void MyGameEngine::move() {
    for (int i(0); i < asteroids->size(); i++) {
        (*asteroids)[i]->move();
    }
}
