#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#endif // PLAYER_H_INCLUDED

#include <iostream>
#include<SDL2/SDL.h>
#include<stdio.h>
#include <string>
using namespace std;

class Player
{

private:

    string name;
    SDL_Event Keypress;
    SDL_Surface* image = NULL;
    int speed = 5;
    bool dead = false;
    int hp = 100;

public:
    SDL_Rect position;

    void Spawn( int spawnX, int spawnY,int PlayerSpeed)
    {
        image = SDL_LoadBMP( "player.bmp" );
        position.x = spawnX;
        position.y = spawnY;
        position.h = 50;
        position.w = 50;


        speed = PlayerSpeed;

        if ( image == NULL)
        {
            cout <<"Player's image got fucked. Here's why: ";
            cout << SDL_GetError() << endl;
            cout <<"if nothing appeared here, then you must've made the image null somewhere." << endl;
        }


    }


    void TakeDMG(int howmuch)
    {
        hp -= howmuch;

        cout<<hp<<endl;

        if ( hp <= 0)
        {
            dead = true;
            cout <<"player died"<<endl;
        }


    }


    void Update(SDL_Surface* a, SDL_Event e)
    {
        if ( dead == false)
        {
            if (e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym)
                {
                case SDLK_UP:
                    position.y -= speed;
                    break;

                case SDLK_DOWN:
                    position.y += speed;
                    break;

                case SDLK_LEFT:
                    position.x -= speed;
                    break;

                case SDLK_RIGHT:
                    position.x += speed;
                    break;
                }

            }
            SDL_BlitSurface(image,NULL,a,&position);
        }
    }

};
