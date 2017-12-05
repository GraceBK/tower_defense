//
//  all_others.c
//  projet_cpp
//
//  Created by Grace on 05/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "all_others.h"

float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrtf((dx * dx) + (dy * dy));
}
/**
 Cette fonction calcul le taux de variation entre deux valeurs
 afin de trouver le %tage de variation (taux d'evolution entre
 deux valeurs
 */
float variation(float v1, float v2) {
    return (v2 - v1) / v1 * 100;
}
