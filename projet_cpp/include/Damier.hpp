//
//  Damier.hpp
//  projet_cpp
//
//  Created by Grace on 07/11/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Damier_hpp
#define Damier_hpp

#include <stdio.h>
#include <vector>
#include <math.h>

#include <fstream>

#include "GraphicPrimitives.h"
#include "Case.hpp"

class Damier {
    int taille = 12;
    float decalage = 0.105;
    float pos_x_case_zero = -0.8f;
    float pos_y_case_zero = -0.9f;
    
    
    std::vector<Case> grille;
    
public:
    Damier();
    ~Damier();
    
    void draw();
    
    void draw_();
    
    void toString();
    
    std::vector<int> indice_case_vaisseau(float x, float y);
    
    int mettre_vaissaux(float x, float y);
    
//    void ajouterVaisseaux(float x, float y);
    
    Case getCase(int x);
    
    float getInitPosX();
    float getInitPosY();
    
    
    
    
    
    
    
    // Methode pour la sauvegarde
    void save();
    void load();
};

#endif /* Damier_hpp */
