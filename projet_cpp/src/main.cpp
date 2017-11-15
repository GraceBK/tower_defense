//
//  main.cpp
//  projet_cpp
//
//  Created by Grace on 03/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include <iostream>

#include "Engine.h"
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"

int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Engine e(argc, argv);
    //std::vector<Papillon *> paps;
    Game *game = new Game();
    
    Damier *damier = new Damier();
    std::vector<Vaisseaux *> vaisseaux;
    
    
    GraphicEngine *ge = new MyGraphicEngine(game, damier, &vaisseaux);
    GameEngine *gme = new MyGameEngine(game, damier, &vaisseaux);
    ControlEngine *ce = new MyControlEngine(game, damier, &vaisseaux);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
