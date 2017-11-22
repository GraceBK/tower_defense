
#include "MyGameEngine.h"


void MyGameEngine::idle(){
    if (menu_jeu->isOver() == false) {
        if (!menu_jeu->isRunning()) {
//            genererAsteroids();
//            startAsteroids();
//            move();
        }
        
    }
}

void MyGameEngine::move() {
    for (int i(0); i < asteroids->size(); i++) {
        (*asteroids)[i]->move();
    }
}

void MyGameEngine::genererAsteroids() {
    float posX((grille->getInitPosX()+0.4)+(grille->getCase(0).getWidth()+(0.105*(grille->getWidth()-1)))), y(grille->getInitPosY()+0.105), y2 = y + grille->getCase(0).getHeight()+0.105*(11-1);
    
    float alea = (y+1) + (((float) rand())/(float)RAND_MAX) * (y2-(y+1))/**()*/;
    std::cout << "**********1******** " << alea << std::endl;
    float posY = y + (alea * grille->getCase(0).getHeight()) + y2;
    
//    int frequence_creature = (rand() % 4);
    //if (frequence_creature != 0) {
    /*asteroids->push_back(new Asteroids(posX, ((-0.8)+0.01)));//0 = -0.79 //floorf(posY * 100) / 100));
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
    */
    int frequence = rand() % 500;
    if (frequence <= 1) {
//        asteroids->push_back(new Asteroids(posX-0.3, ((alea))));//4 = -0.37
        startAsteroids();
    } else {
    }
}

void MyGameEngine::startAsteroids() {
    std::srand(unsigned (std::time(0)));    // permet de generer un random semblable au precedent
    std::vector<float> my_vector;
    // on met les points de depart des Asteroids dans my_vector
    
    my_vector.push_back(-0.79);
    my_vector.push_back(-0.685);
    my_vector.push_back(-0.58);
    my_vector.push_back(-0.475);
    my_vector.push_back(-0.37);
    my_vector.push_back(-0.265);
    my_vector.push_back(-0.16);
    my_vector.push_back(-0.055);
    my_vector.push_back(0.05);
    my_vector.push_back(0.155);
    my_vector.push_back(0.26);
    my_vector.push_back(0.365);
    
    // utilisation du random generator built-in
    std::random_shuffle(my_vector.begin(), my_vector.end());
    // utilisation de my_random
//    std::random_shuffle(my_vector.begin(), my_vector.end());
    std::cout << ">>>>>";
    float posX((grille->getInitPosX()+0.4)+(grille->getCase(0).getWidth()+(0.105*(grille->getWidth()-1))));
    for (std::vector<float>::iterator it=my_vector.begin(); it!=my_vector.end(); ++it) {
        std::cout << ' ' << *it;
        asteroids->push_back(new Asteroids(posX-0.3, *it));
    }
    std::cout << '\n';
}

int MyGameEngine::my_random(int n) {
    return std::rand() % n;
}
