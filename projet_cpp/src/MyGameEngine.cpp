
#include "MyGameEngine.h"


void MyGameEngine::idle(){
    
}

void MyGameEngine::move() {
    for (int i(0); i < asteroids->size(); i++) {
        (*asteroids)[i]->move();
    }
}
