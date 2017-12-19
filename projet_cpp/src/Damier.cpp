//
//  Damier.cpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "Damier.hpp"

Damier::Damier() {
    float x = CASE_Z_X;
    float y = CASE_Z_Y;
    for (int i(0); i < height; i++) {
        y = y + DECALAGE;
        x = -0.4;
        for (int z(0); z < width; z++) {
            grille.push_back(Case(x, y));
            x = x + DECALAGE;
        }
    }
}

Damier::~Damier() {
    delete &grille;
}

void Damier::draw() {
    for (int i(0); i < grille.size(); i++) {
        grille[i].draw();
    }
}

Case Damier::getCase(int x) {
    return grille[x];
}

float Damier::getInitPosX() { return pos_x_case_zero; }
float Damier::getInitPosY() { return pos_y_case_zero; }
int Damier::getHeight() { return height; }
int Damier::getWidth() { return width; }

std::vector<int> Damier::indice_case_vaisseau(float x, float y) {
    std::vector<int> case_proche;
    float res;
    for (int i(0); i < grille.size(); ++i) {
        res = 0;
        if (res <= 0.11*sqrt(2)) {
            case_proche.push_back(i);
        }
    }
    return case_proche;
}

int Damier::mettre_vaissaux(float x, float y) {
    std::vector<int> vaisseaux;
    int v_id = 0;
    vaisseaux = indice_case_vaisseau(x, y);
    int indice = 0;
    for (int i(0); i < vaisseaux.size(); ++i) {
        indice = vaisseaux[i];
        if (grille[indice].getX() <= x && grille[indice].getY() <= y) {
            v_id = indice;
        }
    }
//    std::cout << "case -> " << v_id << std::endl;
//    std::cout << "Q1 " << grille[v_id].isEmpty() << std::endl;
    if (grille[v_id].isEmpty()) {
        grille[v_id].setEmpty(false);
//        std::cout << "Q2 " << grille[v_id].isEmpty() << std::endl;
        return v_id;
    } else {
//        std::cout << "Q12 " << grille[v_id].isEmpty() << std::endl;
        return -1;
    }
}

void Damier::reset_grille() {
    for (int i(0); i < width*height; i++) {
        grille[i].setEmpty(true);
    }
}


void Damier::save() {
    // On ouvre le fichier en mode ecriture
    std::ofstream outfile;
    outfile.open("save_partie.txt");
    
    // On ecrit les datas dans le fichier "save_partie.txt"
    outfile << "COUCOU tu dois enregistrer une grille (°_°)" << std::endl;
    
    // On ferme le fichier
    outfile.close();
}

void Damier::load() {
    // On ouvre le fichier en mode lecture
    std::ifstream infile;
    infile.open("save_partie.txt");
    
    
    
    // On ferme le fichier
    infile.close();
}
