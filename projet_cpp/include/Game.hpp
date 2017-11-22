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
#include <string>
#include "GraphicPrimitives.h"

class Game {
    float r, g, b;
    
    int score, argent;
    
    bool start;
    bool start_n;
    bool finished;  // fin d'une partie
    bool is_running; // si une vague est lancee
    
    char * nX1 = new char[8]{'1', ' ', 'L', 'i', 'g', 'n', 's', '\0'};
    char * nXn = new char[6]{'M', 'u', 'l', 't', 'i', '\0'};
    char * exit = new char[8]{'Q', 'u', 'i', 't', 't', 'e', 'r', '\0'};

    char * game_over = new char[10] {'G','A','M','E',' ','O','V','E','R','\0'};
    
public:
    Game();
    
    void drawGameOver();
    
    // Méthode de draw bouton
    void draw();
    void draw_btn_one();
    void draw_btn_multi();
    void draw_btn_load();
    void draw_btn_exit();
    
    void draw_home();
    void draw_btn_save();
    void draw_btn_run();
    
    void show_stats();
    
    
    // Gestion des clics
    bool clic_btn_one(float clic_x, float clic_y);
    bool clic_btn_multi(float clic_x, float clic_y);
    bool clic_btn_load(float clic_x, float clic_y);
    bool clic_btn_exit(float clic_x, float clic_y);
    
    bool clic_home(float clic_x, float clic_y);
    bool clic_btn_save(float clic_x, float clic_y);
    bool clic_btn_run(float clic_x, float clic_y);
    
    // GETTERS et SETTERS
    bool isOver();
    void setOver(bool b);
    
    bool isStart();
    void setStart(bool b);
    
    bool isStartN();
    void setStartN(bool b);
    
    bool isRunning();
    void setRunning(bool b);
};

#endif /* Game_hpp */
