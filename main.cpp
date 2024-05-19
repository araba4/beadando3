#include "graphics.hpp"
#include "application.hpp"
#include "widgets.hpp"
#include "ui.hpp"
#include "mark.hpp"
#include "gamemaster.hpp"
#include "button.hpp"

#include <vector>

using namespace std;

const int XX = 610,
          YY = 705,
          GW = 600;

int type;

class GameWindow: public Application
{
public:
    GameWindow(int width, int height):
        Application(width, height)
        {
            ui = new UI(this);
            new_game = new Button(this,
                                  XX/2, (GW/3)*2,
                                  20, 20,
                                  "New Game",
                                  [=](){newGame();});
            for (int y=0; y<15; y++)
                for (int x=0; x<15;x++)
                    marks.push_back(new Mark(this,
                                             0+(GW/15)*x+5, YY-GW+(GW/15)*y-5,
                                             40, 40,
                                             [x,y,this](){ttSwitch();
                                                           checkWinInit(marks[x+y*15]);},
                                             x,
                                             y));
            gm = new GameMaster(this,
                                [=](int){winSwitch(type);});
        }

        void newGame()
        {
            for (Widget *w: widgets)
                w->inGameSwitch();
            for (Mark *m: marks)
                m->typeReset();
        }

        void ttSwitch()
        {
            for (Widget *w: widgets)
                w->turnSwitch();
        }

        void checkWinInit(Mark* mark)
        {
            type = mark->getType();
            gm->checkWin(marks, mark);
        }

        void winSwitch(int type)
        {
            for (Widget* w: widgets)
                w->win(type);
        }

protected:
    UI *ui;
    GameMaster *gm;
    Button *new_game;

    vector<Mark*> marks;
};

int main()
{
    GameWindow game(XX,YY);

    game.event_loop();

    return 0;
}
