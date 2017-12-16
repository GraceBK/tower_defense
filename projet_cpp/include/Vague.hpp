//
//  Vague.hpp
//  projet_cpp
//
//  Created by Grace on 16/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef Vague_hpp
#define Vague_hpp

#include <stdio.h>
#include <vector>
#include "Vaisseaux.hpp"
#include "Vaisseaux1.hpp"
#include "Vaisseaux2.hpp"
#include "Asteroids.hpp"
#include "Asteroids1.hpp"
#include "Asteroids2.hpp"
#include "all_others.hpp"

class Vague {
public:
    Vague(int n_asteroids);
    
    int nombre_asteroids;
    int frequence;
    std::vector<Asteroids *> asteroids;
    
    void genererAsteroids();
};

#endif /* Vague_hpp */
