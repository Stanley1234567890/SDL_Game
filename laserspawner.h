#ifndef LASERSPAWNER_H_INCLUDED
#define LASERSPAWNER_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <time.h>
#endif // LASERSPAWNER_H_INCLUDED
using namespace std;


class LaserSpawner
{

private:
    int randomnum;
    int howmany;
    Laser lasers[10];
    int currentlaser = 0;
    int speed = 1;
    int startertick = 0;

    int Randomize(int minimum, int maximum)
    {
        int seed = 0;

        srand(time(NULL));
        seed = rand();
        srand(seed);
        return minimum + rand() % (( maximum + 1 ) - minimum);
    }


public:



    void Spawn(int howmanyin)
    {
        howmany = howmanyin;
        lasers[currentlaser].spawn(Randomize(0,1200), 10);
        lasers[currentlaser].SpeedChange(Randomize(1,6));
        currentlaser++;
    }

    void SpeedUp()
    {
        int random = Randomize(0, howmany);
        speed++;
        lasers[random].SpeedChange(Randomize(speed,10));
    }

    void Check4hits(Player p1)
    {
        for ( int i = 0; i < howmany; i++)
        {
            lasers[i].HitDet(p1);
        }
    }


    void Update(SDL_Surface* s1, Player p1)
    {
        for ( int i = 0; i < howmany; i++)
        {
            lasers[i].Move(s1);
        }


        for ( int i = 0; i < howmany; i++)          //if laser is despawned, respawn it.
        {
            if ( lasers[i].despawned == true)
            {
                lasers[i].respawn(Randomize(0,1200),10);
            }
        }

        startertick++;
        if ( startertick >= 1000 && currentlaser < howmany )    //spawning lasers every 1000 ticks
        {
            lasers[currentlaser].spawn(Randomize(0,1200),10);
            cout<<"laser number "<<currentlaser<<" spawned!"<<endl;
            lasers[currentlaser].SpeedChange(Randomize(1,6));
            currentlaser++;
            startertick = 0;
        }

        Check4hits(p1);
    }
};
