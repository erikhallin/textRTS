#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct unit
{
    unit()
    {
        pos[0]=pos[1]=0;
        symbol='x';
        pos_to[0]=pos_to[1]=0;
        move_speed=1;
        move_tile_prog=1;
    }

    int pos[2];
    int pos_to[2];
    char symbol;
    float move_speed;
    float move_tile_prog;

};

class game
{
    public:
        game();

        bool init();
        bool update(float time_dif);
        bool print_map();
        bool find_units();
        bool move_unit(int x_from,int y_from, int x_to,int y_to);

    private:

        float m_time_dif;
        vector<unit> m_vec_units;
};

#endif // GAME_H
