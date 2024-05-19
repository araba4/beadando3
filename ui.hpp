#ifndef UI_HPP
#define UI_HPP

#include "widgets.hpp"


class UI: public Widget
{
protected:
    const int XX = 620,
              YY = 705,
              GW = 600;
public:
    UI(Application*);
    virtual void draw() const override;
    virtual void handle(genv::event) override;
};

#endif // UI_HPP
