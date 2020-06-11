#include "laser.h"
#include <iostream>
#include<stdio.h>
#include"SDL2/SDL_image.h"
#include "laserspawner.h"


//TODO: LIMIT FPS TO 60

SDL_Window* window1 = NULL;
SDL_Surface* sur1 = NULL;


void MakeWindow(int width, int height, const char* name)
{
    window1 = SDL_CreateWindow( name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
    sur1 = SDL_GetWindowSurface( window1 );
    SDL_FillRect( sur1, NULL, SDL_MapRGB( sur1->format, 0xFF, 0xFF, 0xFF ) );
}


void CleanUp()
{
    //do stuff here idk lol
}

Player p1;


int main(int, char **)
{
    LaserSpawner l1;
    SDL_Event e; //do sprawdzania wcisnietych klawiszy itp.
    int difficulty = 0;
    bool quit = false;
    long int score = 0;
    MakeWindow(1200,600,"cock and ball torture");
    p1.Spawn(440,490, 7);
    l1.Spawn(3);

            while ( quit == false)  //glowny loop
            {
                SDL_FillRect( sur1, NULL, SDL_MapRGB( sur1->format,  23, 17, 59  ) ); //czyszczenie ekranu


                while ( SDL_PollEvent(&e) != 0)
                {
                    switch ( e.type )
                    {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    }
                }

                p1.Update(sur1, e);
                l1.Update(sur1, p1);

                difficulty++;  //zwiekszanie trudnosci co 1000 iteracji.
                if ( difficulty == 1000)
                {
                    l1.SpeedUp();
                    difficulty = 0;
                }

                  score++;
                SDL_UpdateWindowSurface( window1 );
                SDL_Delay(10);
            }


    cout << "closing" << endl;
    return 0;

}



