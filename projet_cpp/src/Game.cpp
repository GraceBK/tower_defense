//
//  Game.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Game.hpp"

Game::Game() {}

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


