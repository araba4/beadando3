#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
using namespace genv;

Application::Application(int width, int height)
{
    gout.open(width, height);
}

void Application::register_widget(Widget* widget)
{
    widgets.push_back(widget);
}

void Application::event_loop()
{
    gout << color(0,0,0)
         << move_to(0,0)
         << box(610,705);
    for (Widget* w: widgets)
        w->draw();
    gout << refresh;

    event ev;
    while(gin >> ev)
    {
        gout << color(0,0,0)
             << move_to(0,0)
             << box(610,705);
        for (Widget* w: widgets)
            w->draw();
        gout << refresh;
        if (ev.type == ev_mouse){
            if (ev.button == btn_left){
                gout << color(0,0,0)
                     << move_to(0,0)
                     << box(610,705);
                for (Widget* w: widgets)
                    w->handle(ev);
                for (Widget* w: widgets)
                    w->draw();
                gout << refresh;
            }
        }
    }
}
