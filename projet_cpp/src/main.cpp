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
    std::vector<Papillon *> paps;
    
    GraphicEngine *ge = new MyGraphicEngine(&paps);
    GameEngine *gme = new MyGameEngine(&paps);
    ControlEngine *ce = new MyControlEngine(&paps);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
