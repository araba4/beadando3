#include "ui.hpp"
#include "graphics.hpp"
#include "application.hpp"
#include "button.hpp"

#include <string>
#include <iostream>

using namespace genv;

UI::UI(Application *parent): Widget(parent)
{}

void UI::draw() const
{
    if (!inGame &&
        !xWin &&
        !oWin &&
        !tie){
        gout.load_font("LiberationSans-Regular.ttf", 40);

        gout << color(255, 255, 255)
             << move_to(XX/2 - gout.twidth("Tic-Tac-Toe")/2, GW/3)
             << text("Tic-Tac-Toe");
    }

    else if (inGame &&
             !xWin &&
             !oWin &&
             !tie){
            gout.load_font("LiberationSans-Regular.ttf", 40);

            gout << color(255, 255, 255);

            for(int i=1; i<15; i++){
                gout << move_to(0+(GW/15)*i+5, YY-GW-5)
                     << line(0, GW);
            }

            for(int i=1; i<15; i++){
                gout << move_to(5, YY-GW+(GW/15)*i-5)
                     << line(GW, 0);
            }

            if (turn == -1)
                gout << color(0, 0, 255)
                     << move_to((610/2)-gout.twidth("O's turn")/2, 50-(gout.cdescent()+gout.cascent())/2)
                     << text("O's turn");

            if (turn == 1)
                gout << color(255, 0, 0)
                     << move_to((610/2)-gout.twidth("X's turn")/2, 50-(gout.cdescent()+gout.cascent())/2)
                     << text("X's turn");
    }

    if (xWin){
        gout.load_font("LiberationSans-Regular.ttf", 60);

        gout << color(255, 0, 0)
             << move_to(XX/2 - gout.twidth("X won!")/2, GW/3)
             << text("X won!");
    }

    if (oWin){
        gout.load_font("LiberationSans-Regular.ttf", 60);

        gout << color(0, 0, 255)
             << move_to(XX/2 - gout.twidth("O won!")/2, GW/3)
             << text("O won!");
    }

    if (tie){
        gout.load_font("LiberationSans-Regular.ttf", 60);

        gout << color(255, 255, 255)
             << move_to(XX/2 - gout.twidth("Tie!")/2, GW/3)
             << text("Tie!");
    }
}

void UI::handle(event ev)
{
    return;
}
