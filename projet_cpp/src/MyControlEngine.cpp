
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        paps->push_back(new Papillon((x-cursor_x) / cursor_x_f, (y-cursor_y)/ -cursor_y_f));
    }
}
