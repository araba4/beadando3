#include "widgets.hpp"
#include "graphics.hpp"
#include "application.hpp"

using namespace genv;

Widget::Widget(Application *parent): _parent(parent)
{
    if (_parent)
        _parent->register_widget(this);
    inGame = 0;
    turn = 0;
    xWin = 0;
    oWin = 0;
    tie = 0;
}

Widget::Widget(Application *parent,
               int x, int y, int sx, int sy) :
        _parent(parent), _x(x), _y(y), _sx(sx), _sy(sy)
{
    if (_parent)
        _parent->register_widget(this);
    inGame = 0;
    turn = 0;
    xWin = 0;
    oWin = 0;
    tie = 0;
}

bool Widget::isSelected(int mx, int my)
{
    return mx>_x && mx<_x+_sx && my>_y && my<_y+_sy;
}

void Widget::inGameSwitch()
{
    inGame = !inGame;
    turn = 0;
    xWin = 0;
    oWin = 0;
    tie = 0;
}

void Widget::turnSwitch()
{
    if(turn==0)
        turn = 1;
    else
        turn = -turn;
}

void Widget::win(int type)
{
    if (type == 1)
        xWin = 1;
    if (type == -1)
        oWin = 1;
    if (type == 0)
        tie = 0;
    inGame = !inGame;
}
