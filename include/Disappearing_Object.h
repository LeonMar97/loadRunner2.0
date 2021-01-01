#include "Game_Object.h"
#pragma once
class Disapearing_Object:public Game_Object {

public://functions
    using Game_Object::Game_Object;
    Game_Object() = 0;
    virtual void draw_On_Board() = 0;
    virtual void effect() = 0;
private:

private:    //members


}

