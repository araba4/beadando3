#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include <vector>
#include <functional>

#include "widgets.hpp"
#include "mark.hpp"

class Button;

class GameMaster: public Widget
{
protected:
    std::function<void(int)> _win;
public:
    GameMaster(Application*, std::function<void(int)>);
    virtual void draw() const override;
    virtual void handle(genv::event) override;

    void checkWin(std::vector<Mark*>, Mark*);
    void winAction(int);
};

#endif // GAMEMASTER_HPP
