
//troche chujowe te kolizje, popraw.

#ifndef HITBOX_H_INCLUDED
#define HITBOX_H_INCLUDED
#include <iostream>
#endif // HITBOX_H_INCLUDED

using namespace std;


class Hitbox
{
public:

    bool Detect (SDL_Rect object1, SDL_Rect object2)
    {
        //if they collide
        if ( object1.x  <= object2.x + object2.w  && object1.x + object1.w >= object2.x  && object1.y  < object2.y + object1.h  && object1.y  > object2.y - object2.h)
        {
            return true;
            cout << "collision detected"<<endl;
        }
        else
        {
            return false;
        }

    }
};
