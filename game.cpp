#include "game.h"

game::game()
{
    m_time_dif=0;
}

bool game::init()
{
    //spawn units
    unit temp_unit;
    temp_unit.pos[0]=5;
    temp_unit.pos[1]=5;
    m_vec_units.push_back(temp_unit);
    temp_unit.pos[0]=15;
    temp_unit.pos[1]=3;
    m_vec_units.push_back(temp_unit);
    temp_unit.pos[0]=12;
    temp_unit.pos[1]=17;
    m_vec_units.push_back(temp_unit);

    return true;
}

bool game::update(float time_dif)
{
    m_time_dif=time_dif;

    //move units
    for(int i=0;i<(int)m_vec_units.size();i++)
    {
        if(m_vec_units[i].pos[0]!=m_vec_units[i].pos_to[0]||
           m_vec_units[i].pos[1]!=m_vec_units[i].pos_to[1])
        {
            if(m_vec_units[i].move_tile_prog<=0)
            {
                m_vec_units[i].move_tile_prog=1;

                //move one step
                int x_dif=m_vec_units[i].pos_to[0]-m_vec_units[i].pos[0];
                int y_dif=m_vec_units[i].pos_to[1]-m_vec_units[i].pos[1];

                //move longest dif
                if(fabs(x_dif)>fabs(y_dif))
                {
                    if(x_dif>0)
                        m_vec_units[i].pos[0]+=1;
                    else
                        m_vec_units[i].pos[0]-=1;
                }
                else
                {
                    if(y_dif>0)
                        m_vec_units[i].pos[1]+=1;
                    else
                        m_vec_units[i].pos[1]-=1;
                }
            }
            else
            {
                //update timer
                m_vec_units[i].move_tile_prog-=time_dif*m_vec_units[i].move_speed;
            }
        }
    }

    return true;
}

bool game::print_map()
{
    int map_size[2]={30,20};
    for(int y=0;y<map_size[1];y++)
    {
        for(int x=0;x<map_size[0];x++)
        {
            bool unit_found=false;
            for(int i=0;i<(int)m_vec_units.size();i++)
            {
                if(m_vec_units[i].pos[0]==x&&m_vec_units[i].pos[1]==y)
                {
                    cout<<m_vec_units[i].symbol;
                    unit_found=true;
                    break;
                }
            }

            if(!unit_found) cout<<'.';
        }

        //new row
        cout<<endl;
    }

    return true;
}

bool game::find_units()
{
    for(int i=0;i<(int)m_vec_units.size();i++)
    {
        cout<<"> "<<m_vec_units[i].pos[0]<<", "<<m_vec_units[i].pos[1]<<endl;
    }

    return true;
}

bool game::move_unit(int x_from,int y_from, int x_to,int y_to)
{
    //find unit
    for(int i=0;i<(int)m_vec_units.size();i++)
    {
        if(m_vec_units[i].pos[0]==x_from&&m_vec_units[i].pos[1]==y_from)
        {
            m_vec_units[i].pos_to[0]=x_to;
            m_vec_units[i].pos_to[1]=y_to;

            return true;
        }
    }

    cout<<"Unit at that position not found"<<endl;

    return true;
}


