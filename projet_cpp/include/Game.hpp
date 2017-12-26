//
//  Game.hpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

/*
 char * aide1 = new char[112] {'P', 'o', 's', 'i', 't', 'i', 'o', 'n', 'n', 'e', 'r', ' ', 'l', 'e', ' ', 'c', 'u', 'r', 's', 'e', 'u', 'r', ' ', 'd', 'a', 'n', 's', ' ', 'u', 'n', 'e', ' ', 'd', 'e', 's', ' ', 'c', 'a', 's', 'e', 's', ' ', 'e', 't', ' ', 'u', 't', 'i', 'l', 'i', 's', 'e', 'r', ' ', 'l', 'a', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', 'l', 'e', 's', ' ', 't', 'o', 'u', 'c', 'h', 'e', 's', ' ', '\'', 'a', '\'', ' ', '\'', 'z', '\'', ' ', '\'', 'e', '\'', ' ', 'p', 'o', 'u', 'r', ' ', 'p', 'l', 'a', 'c', 'e', 'r', ' ', 'u', 'n', ' ', 'v', 'a', 'i', 's', 's', 'e', 'a', 'u', '\0'};
 */

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
    bool start = false;
    bool finished = false;  // fin d'une partie
    bool is_running = false; // si une vague est lancee
    
    char * nX1 = new char[8]{'1', ' ', 'L', 'i', 'g', 'n', 's', '\0'};
    char * nXn = new char[6]{'M', 'u', 'l', 't', 'i', '\0'};
    char * exit = new char[8]{'Q', 'u', 'i', 't', 't', 'e', 'r', '\0'};
    char * welcome = new char[25] {'B', 'I', 'E', 'N', 'V', 'E', 'N', 'U', 'E', ' ', 'd', 'a', 'n', 's', ' ', 'S', 'T', 'A', 'R', ' ', 'W', 'A', 'R', 'S', '\0'};
    char * aide1 = new char[61] {'L', 'e', 's', ' ', 'S', 'T', 'O', 'R', 'M', 'T', 'R', 'O', 'O', 'P', 'E', 'R', 'S', ' ', 'n', 'e', ' ', 'd', 'o', 'i', 'v', 'v', 'e', 'n', 't', ' ', 'p', 'a', 's', ' ', 'a', 't', 't', 'e', 'i', 'n', 'd', 'r', 'e', ' ', 'l', 'a', ' ', 'l', 'i', 'g', 'n', 'e', ' ', 'B', 'l', 'a', 'n', 'c', 'h', 'e', '\0'};
    char * aide2 = new char[68] {'P', 'o', 's', 'i', 't', 'i', 'o', 'n', 'n', 'e', 'r', ' ', 'l', 'e', ' ', 'c', 'u', 'r', 's', 'e', 'u', 'r', ' ', 'd', 'a', 'n', 's', ' ', 'u', 'n', 'e', ' ', 'd', 'e', 's', ' ', 'c', 'a', 's', 'e', 's', ' ', 'e', 't', ' ', 'u', 't', 'i', 'l', 'i', 's', 'e', 'r', ' ', 'l', 'e', 's', ' ', 't', 'o', 'u', 'c', 'h', 'e', 's', ' ', ':', '\0'};
    char * t = new char[42] {' ', '*', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', '\'', 'a', '\'', ' ', 'p', 'o', 'u', 'r', ' ', 'v', 'a', 'i', 's', 's', 'e', 'a', 'u', ' ', 'a', ' ', 't', 'i', 'r', 'e', ' ', 'N', 'o', 'r', 'm', 'a', 'l', '\0'};
    char * t1 = new char[48] {' ', '*', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', '\'', 'z', '\'', ' ', 'p', 'o', 'u', 'r', ' ', 'v', 'a', 'i', 's', 's', 'e', 'a', 'u', ' ', 'a', ' ', 't', 'i', 'r', 'e', ' ', 'R', 'a', 'l', 'e', 'n', 't', 'i', 's', 's', 'e', 'u', 'r', '\0'};
    char * t2 = new char[44] {' ', '*', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', '\'', 'e', '\'', ' ', 'p', 'o', 'u', 'r', ' ', 'v', 'a', 'i', 's', 's', 'e', 'a', 'u', ' ', 'a', ' ', 't', 'i', 'r', 'e', ' ', 'P', 'u', 'i', 's', 's', 'a', 'n', 't', '\0'};
    char * lancer_vague = new char[47] {'-', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', '\'', 'v', '\'', ' ', 'l', 'a', 'n', 'c', 'e', 'r', ' ', 'u', 'n', 'e', ' ', 'V', 'A', 'G', 'U', 'E', ' ', 'd', 'e', ' ', 'S', 'T', 'O', 'R', 'M', 'T', 'R', 'O', 'O', 'P', 'E', 'R', 'S', '\0'};
    char * replay = new char[22] {'-', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', '\'', 'r', '\'', ' ', 'R', 'e', '-', 'j', 'o', 'u', 'e', 'r', '\0'};
    char * motivation = new char[27] {'Q', 'U', 'E', ' ', 'L', 'A', ' ', 'F', 'O', 'R', 'C', 'E', ' ', 'S', 'O', 'I', 'T', ' ', 'A', 'V', 'E', 'C', ' ', 'T', 'O', 'I', '\0'};
    char * lancer_partie = new char[36] {'a', 'p', 'p', 'u', 'y', 'e', 'r', ' ', 's', 'u', 'r', ' ', 'P', 'L', 'A', 'Y', ' ', 'p', 'o', 'u', 'r', ' ', 'l', 'a', 'n', 'c', 'e', 'r', ' ', 'l', 'e', ' ', 'j', 'e', 'u', '\0'};
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
