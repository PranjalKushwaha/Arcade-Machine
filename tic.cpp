#include <stdlib.h>
#include <FL/Fl.H>
#include <iostream>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include "Tic_Tac_Toe.cpp"
using namespace std;

Fl_Window *window3;
int freeze[3][3];
int grid[3][3];
class MyButton : public Fl_Button
{
    int x1, y1, i1, j1;

public:
    MyButton(int x, int y, int w, int h, const char *l, int i, int j);
    int handle(int e);
    void toggle(int t, int i, int j);
};
MyButton *Button[3][3];
void MyButton::toggle(int t, int i, int j)
{
    if (t == 1)
    {
        const char *s = label();
        Button[i1][j1]->label("O");
        color(FL_BLUE);
    }
    else if (t == 0)
    {
        const char *s = label();
        Button[i][j]->label("X");
        Button[i][j]->color(FL_RED);
    }
}
MyButton ::MyButton(int x, int y, int w, int h, const char *l, int i, int j) : Fl_Button(x, y, w, h, l)
{
    x1 = x;
    y1 = y;
    i1 = i;
    j1 = j;
}
void playerwin()
{
    window3->hide();
    if (fl_ask("\t \t \t You Win!  \n Do you want to return to the main menu?"))
        return;
    else
        exit(0);
}
void playerlose()
{
    window3->hide();
    if (fl_ask("\t \t \t You Lose! \n Do you want to return to the main menu?"))
        return;
    else
        exit(0);
}
void gamedraw()
{
    window3->hide();
    if (fl_ask("\t \t \t \t Draw! \n Do you want to return to the main menu?"))
        return;
    else
        exit(0);
}
int MyButton ::handle(int e)
{
    if (e == FL_PUSH)
    {

        if (grid[i1][j1] == 3)
        {
            toggle(1, 0, 0);
            //freeze[i1][j1] = 1;
            grid[i1][j1] = 0;
            if (win(grid) == -1)
            {
                playerwin();
                return 1;
            }
            if (count(grid) == 0)
            {
                gamedraw();
                return 1;
            }
            else
            {
                int g = p(grid);
                grid[g / 10][g % 10] = 1;
                toggle(0, g / 10, g % 10);
                if (win(grid) == 1)
                {
                    playerlose();
                    return 1;
                }
                if (count(grid) == 0)
                {
                    gamedraw();
                    return 1;
                }
            }
        }
    }
    return 1;
};

int Play_Tic()
{
    window3 = new Fl_Window(500, 500, "Tic Tac Toe");
    int x = 100, y = 100;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            freeze[i][j] = 0;
            grid[i][j] = 3;
            Button[i][j] = new MyButton(x, y, 100, 100, "", i, j);
            x += 100;
        }
        y += 100;
        x = 100;
    }
    int n;
    int g = p(grid);
    grid[g / 10][g % 10] = 1;
    Button[g / 10][g % 10]->toggle(0, g / 10, g % 10);
    window3->end();
    window3->show();
    return (Fl::run());
}
