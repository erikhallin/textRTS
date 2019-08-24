#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <stdio.h>

#include "game.h"

using namespace std;

int main()
{
    cout<<"Startup"<<endl;

    game Game;
    Game.init();


    //game loop
    float time_last=(float)clock()/(float)CLOCKS_PER_SEC;
    while(true)
    {
        string input,word;
        getline(cin,input);
        bool valid_command=false;
        //split
        stringstream ss(input);
        ss>>word;
        string word_first=word;
        ss>>word;
        string word_second=word;

        float time_now=(float)clock()/(float)CLOCKS_PER_SEC;

        //timing
        Game.update(time_now-time_last);

        if(input=="map")
        {
            valid_command=Game.print_map();
        }
        if(input=="find units")
        {
            valid_command=Game.find_units();
        }
        if(word_first=="move")
        {
            if(word_second=="unit")
            {
                //get pos
                int x_from,x_to,y_from,y_to;
                ss>>word;
                istringstream(word)>>x_from;
                ss>>word;
                istringstream(word)>>y_from;
                ss>>word;
                istringstream(word)>>x_to;
                ss>>word;
                istringstream(word)>>y_to;

                valid_command=Game.move_unit(x_from,y_from,x_to,y_to);

            }
        }



        if(input=="exit"||input=="quit") break;

        if(!valid_command)
        {
            cout<<"Command not found"<<endl;
        }

        time_last=time_now;
    }

    cout<<"end"<<endl;
    return 0;
}
