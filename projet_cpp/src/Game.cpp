//
//  Game.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Game.hpp"

Game::Game() {
    score = SCORE;
    bank = BANK;
    level = LEVEL;
}


void Game::drawGameOver() {
    float x(-0.1), y(0.1), r(WHITE), g(BLACK), b(BLACK);
    char sc[5];
    sprintf(sc, "%d", score);
    GraphicPrimitives::drawText2D(game_score, x - 0.05f, y - 0.1f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(sc, x + 0.3f, y - 0.1f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(game_over, x, y, r, g, b);
}

// Affichage du menu principal
void Game::draw() {
    float x(-0.5f);
    GraphicPrimitives::drawText2D(welcome, x + 0.15f, 0.9f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(aide1, -0.7f, 0.7f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(aide2, -0.68f, 0.6f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(t, x - 0.05f, 0.5f, R_V, G_V, B_V);
    GraphicPrimitives::drawText2D(t1, x - 0.05f, 0.4f, R_V1, G_V1, B_V1);
    GraphicPrimitives::drawText2D(t2, x - 0.05f, 0.3f, R_V2, G_V2, B_V2);
    GraphicPrimitives::drawText2D(lancer_vague, x - 0.1f, 0.2f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(replay, x - 0.1f, 0.1f, WHITE, WHITE, WHITE);
    
    GraphicPrimitives::drawText2D(lancer_partie, x - 0.1f, 0.0f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(motivation, x + 0.12f, -0.3f, WHITE, WHITE, WHITE);
    draw_btn_play();
}

void Game::draw_btn_help() {
    float x(-0.5f), y(-0.5f), w(0.45f), h(0.45f), r(0.09), g(0.459), b(0.722);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
    GraphicPrimitives::drawText2D(new char[5]{'H', 'E', 'L', 'P', '\0'}, x + 0.1, y + 0.2, WHITE, WHITE, WHITE);
}

void Game::draw_btn_play() {
    float x(-0.25f), y(-0.7f), w(0.45f), h(0.30f), r(0.992), g(0.761), b(0.204);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
    GraphicPrimitives::drawText2D(new char[5]{'P', 'L', 'A', 'Y', '\0'}, x + 0.17, y + 0.13, WHITE, WHITE, WHITE);
}

void Game::draw_btn_load() {
    float x(0.05f), y(0.05f), w(0.45f), h(0.45f), r(0.459), g(0.741), b(0.306);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
    GraphicPrimitives::drawText2D(new char[8]{'R', 'E', ' ', 'P', 'L', 'A', 'Y', '\0'}, x + 0.1, y + 0.2, WHITE, WHITE, WHITE);
}

void Game::draw_btn_exit() {
    float x(0.05f), y(-0.5f), w(0.45f), h(0.45f), r(0.929), g(0.314), b(0.192);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
    GraphicPrimitives::drawText2D(new char[5]{'E', 'X', 'I', 'T', '\0'}, x + 0.1, y + 0.2, WHITE, WHITE, WHITE);
}

// Gestion des clics
bool Game::clic_btn_play(float clic_x, float clic_y) {
    float x(-0.25f), y(-0.7f), w(0.45f), h(0.30f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}

bool Game::clic_btn_help(float clic_x, float clic_y) {
    float x(-0.5f), y(-0.5f), w(0.45f), h(0.45f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}

bool Game::clic_btn_load(float clic_x, float clic_y) {
    float x(0.05f), y(0.05f), w(0.45f), h(0.45f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}

bool Game::clic_btn_exit(float clic_x, float clic_y) {
    float x(0.05f), y(-0.5f), w(0.45f), h(0.45f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}







bool Game::isOver() { return finished; }
void Game::setOver(bool b) { finished = b; }

bool Game::inHelp() { return in_help; }
void Game::setHelp(bool b) { in_help = b; }

bool Game::isStart() { return start; }
void Game::setStart(bool b) { start = b; }

bool Game::isRunning() { return is_running; }
void Game::setRunning(bool b) { is_running = b; }


float Game::getVie() { return vie; }
void Game::setVie(float v) { vie += v; }



int Game::getBank() { return bank; }
int Game::getScore() { return score; }
int Game::getLevel() { return level; }
int Game::getPrixV() { return prix_v; }
int Game::getPrixV1() { return prix_v1; }
int Game::getPrixV2() { return prix_v2; }

void Game::setBank(int p) { bank = p; }
void Game::setScore() {
    int bank_tmp = BANK;
    if (bank > bank_tmp && bank != BANK) {
        bank_tmp = bank;
        score = bank_tmp / 100;
    }
}
void Game::setLevel(int l){ level = l; }
void Game::setPrixV(int p) { prix_v = p; }
void Game::setPrixV1(int p) { prix_v1 = p; }
void Game::setPrixV2(int p) { prix_v2 = p; }



void Game::draw_btn_save() {
    float x(0.0f), y(-0.95f), w(0.4f), h(0.1f);
    char * save = new char[12] {'S','A','U','V','E','G','A','R','D','E','R','\0'};
    GraphicPrimitives::drawFillRect2D(x, y, w, h, BLACK, 0.498, BLACK);
    GraphicPrimitives::drawText2D(save, x + 0.03, y + 0.03, BLACK, BLACK, BLACK);
}

bool Game::clic_btn_save(float clic_x, float clic_y) {
    float x(0.0f), y(-0.95f), w(0.4f), h(0.1f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}



void Game::draw_btn_run() {
    float x(0.45f), y(-0.95f), w(0.3f), h(0.1f);
    char * wave = new char[9]{ 'A','T','T','A','Q','U','E','R','\0' };
    GraphicPrimitives::drawFillRect2D(x, y, w, h, BLACK, 0.498, BLACK);
    GraphicPrimitives::drawText2D(wave, x + 0.03, y + 0.03, BLACK, BLACK, BLACK);
}

bool Game::clic_btn_run(float clic_x, float clic_y) {
    float x(0.45f), y(-0.95f), w(0.3f), h(0.1f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}




void Game::draw_home() {
    float x(-0.3f), y(-0.95f), w(0.25f), h(0.1f);
    char * home = new char[8]{ 'A','C','C','U','E','I','L','\0' };
    GraphicPrimitives::drawFillRect2D(x, y, w, h, 0, 0.498, 0);
    GraphicPrimitives::drawText2D(home, x + 0.03, y + 0.03, BLACK, BLACK, BLACK);
}

bool Game::clic_home(float clic_x, float clic_y) {
    float x(-0.3f), y(-0.95f), w(0.25f), h(0.1f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}

void Game::show_stats() {
    float x(-0.95+0.75f), y(0.93-0.23f);
    char ar[5], sc[5], le[3];
    sprintf(ar, "%d", bank);
    sprintf(sc, "%d", score);
    sprintf(le, "%d", level);
    GraphicPrimitives::drawText2D(ar, x, y + 0.25f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(sc, x, y + 0.15f, WHITE, WHITE, WHITE);
    GraphicPrimitives::drawText2D(le, x + 0.55f, y + 0.15f, WHITE, WHITE, WHITE);
}
