#include<SDL2/SDL.h>
#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include <iostream>
#include <string>
#include "hitbox.h"
#include "player.h"
#endif // LASER_H_INCLUDED
using namespace std;

class Laser
{
   private:
    const char* path = NULL;
    SDL_Surface* image = NULL;

    int speed = 10;
    int x = position.x;
    int y = position.y;
    Hitbox h1;

    protected:

    bool despawned = true;
    SDL_Rect position;

    //make a despawn function here

    friend class LaserSpawner;

   public:

    void SpeedChange(int in)
    {
        speed = in;
    }


    void respawn(int xin, int yin)
    {
        despawned = false;
        position.x = xin;
        position.y = yin;
    }


    void spawn(int xin, int yin)
    {
    path = "player.bmp";
    despawned = false;
    image = SDL_LoadBMP( path );
    position.x = xin;
    position.y = yin;
    position.w = 50;
    position.h = 50;

        if ( image == NULL)
        {
                cout <<"Laser's image got fucked. Here's why: ";
                cout << SDL_GetError() << endl;
                cout <<"if nothing appeared here, then you must've made the image null somewhere." << endl;
        }

    }

    void HitDet(Player p1)
    {
           h1.Detect(position, p1.position);

           if ( h1.Detect(position, p1.position) == true )
           {
               cout <<"HIT"<<endl;
               p1.TakeDMG(25);
               despawned = true;
           }
    }



    void Move(SDL_Surface* a)
    {
        if ( despawned == false )
        {
            if ( position.y > 600  )
            {
                despawned = true;
            }
            else
            {
                position.y += speed;
                SDL_BlitSurface(image, NULL, a, &position);
            }
        }

    }


};
