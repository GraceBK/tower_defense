#pragma once
#include "Engine.h"
#include "Papillon.h"
class MyControlEngine:public ControlEngine {
    std::vector<Papillon * > *paps;
    
    // position du curseur
    int cursor_x = 400;
    int cursor_y = 400;
    float cursor_x_f = 400.f;
    float cursor_y_f = 400.f;
    
public:
    MyControlEngine(std::vector<Papillon * > * paps_):paps(paps_){}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
