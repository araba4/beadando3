#include "mark.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Mark::Mark(Application *parent, int x, int y, int sx, int sy, function<void()> f, int posX, int posY):
    Widget(parent, x, y, sx, sy), _f(f), _posX(posX), _posY(posY)
    {
        _type = 0;
    }

void Mark::draw() const
{
    if (inGame){
        if (_type == 1)
        {
            gout << color(255, 0, 0)
                 << move_to(_x+5, _y+5)
                 << line(_sx-10, _sy-10)
                 << move_to(_x+_sx-5, _y+5)
                 << line(-_sx+10, _sy-10)
                 << move_to(_x+6, _y+5)
                 << line(_sx-11, _sy-11)
                 << move_to(_x+_sx-6, _y+5)
                 << line(-_sx+11, _sy-11)
                 << move_to(_x+5, _y+6)
                 << line(_sx-11, _sy-11)
                 << move_to(_x+_sx-5, _y+6)
                 << line(-_sx+11, _sy-11)
                 << move_to(_x+7, _y+5)
                 << line(_sx-12, _sy-12)
                 << move_to(_x+_sx-7, _y+5)
                 << line(-_sx+12, _sy-12)
                 << move_to(_x+5, _y+7)
                 << line(_sx-12, _sy-12)
                 << move_to(_x+_sx-5, _y+7)
                 << line(-_sx+12, _sy-12);
        }

        if (_type == -1)
        {
            gout << color(0, 0, 255);

            for (int y=-_sy/2; y<=_sy/2; y++)
                for (int x=-_sx/2; x<=_sx/2; x++)
                    if (x*x + y*y <= 250 &&
                        x*x + y*y >= 160)
                        gout << move_to(_x+x+_sx/2, _y+y+_sy/2)
                             << dot;
        }
    }
}

void Mark::handle(event ev)
{
    if (ev.type == ev_mouse &&
        ev.button == btn_left &&
        isSelected(ev.pos_x, ev.pos_y) &&
        inGame)
        {
            if (_type==0){
                _type = turn;
                action();

            }
        }
}

void Mark::action()
{
    _f();
}

void Mark::typeReset()
{
    _type = 0;
}

int Mark::getPosY() const
{
    return _posY;
}

int Mark::getPosX() const
{
    return _posX;
}

int Mark::getType() const
{
    return _type;
}
