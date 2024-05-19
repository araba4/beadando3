#include "button.hpp"
#include "graphics.hpp"

#include <string>
#include <iostream>

using namespace std;
using namespace genv;

Button::Button(Application *parent, int x, int y, int sx, int sy, string title, function<void()> f):
    Widget(parent, x, y, sx, sy), _title(title), _f(f)
    {
        gout.load_font("LiberationSans-Regular.ttf", 20);
        _x -= gout.twidth(_title)/2;
        _sx += gout.twidth(_title);
        _sy += gout.cascent()+gout.cdescent();
    }

void Button::draw() const
{
    gout.load_font("LiberationSans-Regular.ttf", 20);
    if (!inGame){
        gout << color(255, 255, 255)
             << move_to(_x, _y)
             << box(_sx, _sy)
             << color(0,0,0)
             << move_to(_x+5, _y+5)
             << box(_sx-10, _sy-10)
             << color(255, 255, 255)
             << move_to(_x+10, (_y+_sy/2)-(gout.cascent()+gout.cdescent())/2)
             << text(_title);
    }
}

void Button::handle(event ev)
{
    if (ev.type == ev_mouse &&
        ev.button == btn_left &&
        isSelected(ev.pos_x, ev.pos_y) &&
        !inGame)
            action();
}

void Button::action()
{
    _f();
}
