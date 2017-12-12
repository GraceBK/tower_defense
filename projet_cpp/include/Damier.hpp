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
#include "Vaisseaux.hpp"
#include "all_others.hpp"

class Damier {
    int height = SIZE_GRILLE;
    int width = SIZE_GRILLE;
    float pos_x_case_zero = CASE_Z_X;
    float pos_y_case_zero = CASE_Z_Y;
    
    std::vector<Case> grille;
    
public:
    Damier();
    ~Damier();
    
    void draw();
    
    std::vector<int> indice_case_vaisseau(float x, float y);
    
    int mettre_vaissaux(float x, float y);
    void action();
    void reset_grille();
    
    Case getCase(int x);
    
    float getInitPosX();
    float getInitPosY();
    
    int getHeight();
    int getWidth();
    
    // Methode pour la sauvegarde
    void save();
    void load();
    
    
//    Vaisseaux *vaisseaux;
};

#endif /* Damier_hpp */
