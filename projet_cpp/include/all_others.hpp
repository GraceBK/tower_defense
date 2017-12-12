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

#define WIDTH 800
#define HEIGHT 800
// position du curseur
#define CURSOR_X 400
#define CURSOR_Y 400
#define CURSOR_X_F 400.f
#define CURSOR_Y_F 400.f
// variable vaisseaux
#define V_SIZE 0.1
// variable case
#define C_SIZE 0.1
// vie, argent, score
//#define VIE
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

float distance(float x1, float y1, float x2, float y2);
float variation(float v1, float v2);

#endif /* all_others_h */
