//
//  Game.hpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "GraphicPrimitives.h"

class Game {
    float r, g, b;
    
    char * nX1 = new char[8]{'1', ' ', 'L', 'i', 'g', 'n', 's', '\0'};
    char * nXn = new char[6]{'M', 'u', 'l', 't', 'i', '\0'};
    char * exit = new char[8]{'Q', 'u', 'i', 't', 't', 'e', 'r', '\0'};
    
public:
    Game();
    
    void draw();
    void draw_btn_one();
    void draw_btn_multi();
    void draw_btn_load();
    void draw_btn_exit();
};

#endif /* Game_hpp */
