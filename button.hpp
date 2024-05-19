#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <functional>

#include "widgets.hpp"

class Button: public Widget
{
protected:
    std::string _title;
    std::function<void()> _f;
public:
    Button(Application*, int, int, int, int,
           std::string, std::function<void()>);

    virtual void draw() const override;
    virtual void handle(genv::event) override;

    void action();
};

#endif // BUTTON_HPP
