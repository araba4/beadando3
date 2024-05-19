#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>
#include <iostream>

class Widget;

class Application
{
public:
    Application(int, int);

    virtual void event_loop();
    virtual void register_widget(Widget*);

    bool _pushed;

protected:
    std::vector<Widget*> widgets;
};

#endif
