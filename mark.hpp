#ifndef MARK_HPP
#define MARK_HPP

#include <functional>

#include "widgets.hpp"

class Mark: public Widget
{
protected:
    std::function<void()> _f;

    int _posX,
        _posY,
        _type;
public:
    Mark(Application*, int, int, int, int, std::function<void()>, int, int);
    virtual void draw() const override;
    virtual void handle(genv::event) override;
    void action();
    void cwAction();
    void typeReset();

    int getPosX() const;
    int getPosY() const;
    int getType() const;
};

#endif // MARK_HPP
