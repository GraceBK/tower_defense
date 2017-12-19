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
#include "all_others.hpp"

class Game {
    float r, g, b;
    
    int bank;
    int level;
    int score;
    
    bool in_help;
    bool start;
    bool finished;  // fin d'une partie
    bool is_running; // si une vague est lancee
    
    char * nX1 = new char[8]{'1', ' ', 'L', 'i', 'g', 'n', 's', '\0'};
    char * nXn = new char[6]{'M', 'u', 'l', 't', 'i', '\0'};
    char * exit = new char[8]{'Q', 'u', 'i', 't', 't', 'e', 'r', '\0'};

    char * game_over = new char[10] {'G','A','M','E',' ','O','V','E','R','\0'};
    char * game_score = new char[14] {'S','C','O','R','E',' ','F','I','N','A','L',':',' ','\0'};
    
    /** Prix des vaissaux */
    int prix_v = PRIX_V;
    int prix_v1 = PRIX_V1;
    int prix_v2 = PRIX_V2;
    
    float vie = 0.0f;
    
public:
    Game();
    
    void drawGameOver();
    
    // Méthode de draw bouton
    void draw();
    void draw_btn_help();
    void draw_btn_play();
    void draw_btn_load();
    void draw_btn_exit();
    
    void draw_home();
    void draw_btn_save();
    void draw_btn_run();
    
    void show_stats();
    
    
    // Gestion des clics
    bool clic_btn_help(float clic_x, float clic_y);
    bool clic_btn_play(float clic_x, float clic_y);
    bool clic_btn_load(float clic_x, float clic_y);
    bool clic_btn_exit(float clic_x, float clic_y);
    
    bool clic_home(float clic_x, float clic_y);
    bool clic_btn_save(float clic_x, float clic_y);
    bool clic_btn_run(float clic_x, float clic_y);
    
    // GETTERS et SETTERS
    bool isOver();
    void setOver(bool b);
    
    bool inHelp();
    void setHelp(bool b);
    
    bool isStart();
    void setStart(bool b);
    
    bool isRunning();
    void setRunning(bool b);
    
    int getBank();
    int getLevel();
    int getScore();
    int getPrixV();
    int getPrixV1();
    int getPrixV2();
    
    void setBank(int p);
    void setLevel(int l);
    void setScore();
    void setPrixV(int p);
    void setPrixV1(int p);
    void setPrixV2(int p);
    
    float getVie();
    void setVie(float v);
};

#endif /* Game_hpp */
