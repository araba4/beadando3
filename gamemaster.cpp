#include "gamemaster.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

GameMaster::GameMaster(Application *parent, function<void(int)> win):
    Widget(parent), _win(win){}

void GameMaster::draw() const {}

void GameMaster::handle(event ev) {}

void GameMaster::checkWin(vector<Mark*> marks, Mark *m)
{
    int vert_up = 0,
        vert_down = 0,
        hor_left = 0,
        hor_right = 0,
        diag_left_up = 0,
        diag_right_down = 0,
        diag_left_down = 0,
        diag_right_up = 0;


    if (m->getPosY()-1 >= 0){
        int x = m->getPosX(),
            y = m->getPosY()-1;

        while (y>0 &&
               m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0){
                vert_up++;
                y--;
        }

        if (y == 0 &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                vert_up++;
    }

    if (m->getPosY()+1 < 14){
        int x = m->getPosX(),
            y = m->getPosY()+1;

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               y<14){
                vert_down++;
                y++;
        }

        if (y == 14 &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                vert_down++;
    }

    if (vert_up+vert_down+1 >= 5)
        winAction(m->getType());




    if (m->getPosX()-1 >= 0){
        int x = m->getPosX()-1,
            y = m->getPosY();

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               x>0){
                hor_left++;
                x--;
        }

        if (x == 0 &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                hor_left++;
    }

    if (m->getPosX()+1 < 15){
        int x = m->getPosX()+1,
            y = m->getPosY();

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               x<14){
                hor_right++;
                x++;
        }

        if (x == 14 &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                hor_right++;
    }

    if (hor_left+hor_right+1 >= 5)
        winAction(m->getType());



    if (m->getPosX()-1 >= 0 &&
        m->getPosY()+1 < 15){

        int x = m->getPosX()-1,
            y = m->getPosY()+1;

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               x>0 &&
               y<14){
                diag_left_down++;
                x--;
                y++;
        }

        if ((x == 0 || y == 14) &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                diag_left_down++;
    }

    if (m->getPosX()+1 < 15 &&
        m->getPosY()-1 >= 0){

        int x = m->getPosX()+1,
            y = m->getPosY()-1;

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               x<14 &&
               y>0){
                diag_right_up++;
                x++;
                y--;
        }

        if ((x == 14 || y == 0) &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                diag_right_up++;
    }

    if (diag_left_down+diag_right_up+1 >= 5)
        winAction(m->getType());



    if (m->getPosX()-1 >= 0 &&
        m->getPosY()-1 >= 0){

        int x = m->getPosX()-1,
            y = m->getPosY()-1;

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               x>0 &&
               y>0){
                diag_left_up++;
                x--;
                y--;
        }

        if ((x == 0 || y == 0) &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                diag_left_up++;
    }

    if (m->getPosX()+1 < 15 &&
        m->getPosY()+1 < 15){

        int x = m->getPosX()+1,
            y = m->getPosY()+1;

        while (m->getType() == marks[x+y*15]->getType() &&
               marks[x+y*15]->getType() != 0 &&
               x<14 &&
               y<14){
                diag_right_down++;
                x++;
                y++;
        }

        if ((x == 14 || y == 14) &&
            m->getType() == marks[x+y*15]->getType() &&
            marks[x+y*15]->getType() != 0)
                diag_right_down++;
    }

    if (diag_left_up+diag_right_down+1 >= 5)
        winAction(m->getType());


    int tie_check_int = 0;

    for (Mark* mark: marks)
        if (mark->getType() != 0)
            tie_check_int++;

    if (tie_check_int == marks.size())
        winAction(0);

}

void GameMaster::winAction(int type)
{
    _win(type);
}
