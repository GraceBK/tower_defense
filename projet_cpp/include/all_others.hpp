//
//  all_others.h
//  projet_cpp
//
//  Created by Grace on 05/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef all_others_h
#define all_others_h

#include <stdio.h>
#include <math.h>

#define TICK 1000000
#define PRIX_V 20
#define PRIX_V1 50
#define PRIX_V2 1000

#define WIDTH 800
#define HEIGHT 800
#define SIZE_GRILLE 12
#define DECALAGE 0.105

#define CASE_Z_X -0.8f
#define CASE_Z_Y -0.9f

// position du curseur
#define CURSOR_X 400
#define CURSOR_Y 400
#define CURSOR_X_F 400.f
#define CURSOR_Y_F 400.f
// variable vaisseaux
#define V_SIZE 0.1

// variable asteroids
#define A_SIZE 0.09

// variable case
#define C_SIZE 0.1
// vie, argent, score
//#define VIE 100
//#define SCORE
//#define BANK
// couleurs
#define R_C 0
#define G_C 0.2
#define B_C 0

#define R_V 0.298
#define G_V 0.667
#define B_V 0.361

#define R_V1 0.69
#define G_V1 0.098
#define B_V1 0.11

#define R_V2 0.573
#define G_V2 0.173
#define B_V2 0.573

#define R_A 1.0
#define G_A 1.0
#define B_A 1.0

#define R_A1 0.69
#define G_A1 0.098
#define B_A1 0.11

#define R_A2 0.69
#define G_A2 0.098
#define B_A2 0.11

float distance(float x1, float y1, float x2, float y2);
float variation(float v1, float v2);

#endif /* all_others_h */
