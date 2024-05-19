#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "application.hpp"
#include "graphics.hpp"

class Widget
{
protected:
    int _x, _y, _sx, _sy;
    Application *_parent;
    bool inGame,
         xWin,
         oWin,
         tie;
    int turn;
public:
    Widget(Application*);
    Widget(Application*, int x, int y, int sx, int sy);
    virtual bool isSelected(int mouse_x, int mouse_y);
    virtual void draw() const = 0;
    virtual void handle(genv::event) = 0;

    virtual void inGameSwitch();
    virtual void turnSwitch();
    virtual void win(int);
};

#endif // WIDGETS_HPP_INCLUDED
