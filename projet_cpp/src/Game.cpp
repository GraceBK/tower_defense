//
//  Game.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Game.hpp"

Game::Game() {}


void Game::drawGameOver() {
    float x(-0.1), y(0.1), r(1.0), g(0.0), b(0.0);
    GraphicPrimitives::drawText2D(game_over, x, y, r, g, b);
}

// Affichage du menu principal
void Game::draw() {
    draw_btn_one();
    draw_btn_multi();
    draw_btn_load();
    draw_btn_exit();
}

void Game::draw_btn_one() {
    float x(-0.5f), y(0.05f), w(0.45f), h(0.45f), r(0.992), g(0.761), b(0.204);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
}

void Game::draw_btn_multi() {
    float x(0.05f), y(0.05f), w(0.45f), h(0.45f), r(0.459), g(0.741), b(0.306);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
}

void Game::draw_btn_load() {
    float x(-0.5f), y(-0.5f), w(0.45f), h(0.45f), r(0.09), g(0.459), b(0.722);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
}

void Game::draw_btn_exit() {
    float x(0.05f), y(-0.5f), w(0.45f), h(0.45f), r(0.929), g(0.314), b(0.192);
    GraphicPrimitives::drawFillRect2D(x, y, w, h, r, g, b);
}

// Gestion des clics
bool Game::clic_btn_one(float clic_x, float clic_y) {
    float x(-0.5f), y(0.05f), w(0.45f), h(0.45f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}

bool Game::clic_btn_multi(float clic_x, float clic_y) {
    float x(0.05f), y(0.05f), w(0.45f), h(0.45f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}

bool Game::clic_btn_load(float clic_x, float clic_y) {
    float x(-0.5f), y(-0.5f), w(0.45f), h(0.45f);
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

bool Game::isStart() { return start; }
void Game::setStart(bool b) { start = b; }

bool Game::isStartN() { return start_n; }
void Game::setStartN(bool b) { start_n = b; }



void Game::draw_home() {
    float x(-1.0f), y(-0.9f), w(0.25f), h(0.1f);
    char * home = new char[8]{ 'A','C','C','U','E','I','L','\0' };
    GraphicPrimitives::drawFillRect2D(x, y, w, h, 0.043, 0.235, 0.231);
    GraphicPrimitives::drawText2D(home, x + 0.03, y + 0.03, 0.0, 0.0, 0.0);
}

bool Game::clic_home(float clic_x, float clic_y) {
    float x(-1.0f), y(-0.9f), w(0.25f), h(0.1f);
    if (clic_x >= x && clic_x <= x + w && clic_y >= y && clic_y <= y + h) {
        return true;
    } else {
        return false;
    }
}
