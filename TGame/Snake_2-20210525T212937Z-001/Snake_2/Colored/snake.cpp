#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <vector>

#include "food_2.cpp"
// #include "obstacles.cpp"

#define snake_rad 20
#define window_height 1000
#define window_width 1200
using namespace std;
int running = 1;
int score = 0;

class Shape : public Fl_Widget
{
protected:
    int x, y, w, h;

public:
    Shape(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    virtual void wipe(int x, int y) = 0;
    virtual void refresh(int dx, int dy) = 0;
    virtual int handle(int e) = 0;
};

class Circle : public Shape
{
public:
    Circle(int x, int y, int w) : Shape(x, y, w, w) {}
    virtual void draw()
    {
        fl_color(fl_rgb_color(120));
        fl_pie(x, y, w, h, 0, 360);
    }
    void wipe(int a, int b)
    {
        fl_color(79);
        fl_pie(a, b, snake_rad, h, 0, 360);
    }
    void refresh(int dx, int dy)
    {
        x = dx;
        y = dy;
        resize(x, y, w, h);
        fl_color(fl_rgb_color(130));
        fl_pie(x, y, w, h, 0, 360);
    }
    virtual int handle(int e)
    {
        if (e == FL_PUSH)
        {
            refresh(20, 0);
            if (1)
            {
            }
        }
        return 1;
    };
};
class snake : public Circle
{
    Circle *s[1000];
    vector<vector<int>> pos; //[x,y]
    int direction = 0;   //0 down,1 right, 2 up, 3 left
    int num = 0;

public:
    snake() : Circle(0, 0, 0) {}
    void init_snake();
    void move();
    void check (Food* f);
    void eat();
    void turn(int i);
    int handle(int e);
};
int snake::handle(int e)
{
    if (e == FL_KEYDOWN)
    {
        if (Fl::event_key() == 97)
            turn(1);
        else if (Fl::event_key() == 108)
            turn(-1);
    }
    return 1;
}
void snake::turn(int i)
{
    direction += i;
    if (direction==-1)
    direction = 3;
    direction = direction % 4;
}
void snake::init_snake()
{
    Circle *c1 = new Circle(window_width / 2, window_height / 2, snake_rad);
    Circle *c2 = new Circle(window_width / 2, window_height / 2 - snake_rad, snake_rad);
    Circle *c3 = new Circle(window_width / 2, window_height / 2 - 2 * snake_rad, snake_rad);
    num = 3;
    vector<int> v{window_width / 2, window_height / 2};
    pos.push_back(v);
    v[1] -= snake_rad;
    pos.push_back(v);
    v[1] -= snake_rad;
    pos.push_back(v);
    s[0] = c1;
    s[1] = c2;
    s[2] = c3;
}
void snake::move()
{

    int f = pos[num - 1][0];
    int g = pos[num - 1][1];
    for (int i = num - 1; i > 0; i--)
    {
        s[i]->refresh((pos[i - 1][0]), (pos[i - 1][1]));
        pos[i][0] = pos[i - 1][0];
        pos[i][1] = pos[i - 1][1];
    }
    s[num - 1]->wipe(f, g);
    if (direction == 0)
    {
        s[0]->refresh(pos[0][0], pos[0][1] + snake_rad);
        pos[0][0] += 0;
        pos[0][1] += 1 * snake_rad;
    }
    else if (direction == 2)
    {
        s[0]->refresh(pos[0][0], pos[0][1] - snake_rad);
        pos[0][0] += 0;
        pos[0][1] -= 1 * snake_rad;
    }
    else if (direction == 3)
    {
        s[0]->refresh(pos[0][0] - snake_rad, pos[0][1]);
        pos[0][1] += 0;
        pos[0][0] += -1 * snake_rad;
    }
    else if (direction == 1)
    {
        s[0]->refresh(pos[0][0] + snake_rad, pos[0][1]);
        pos[0][1] += 0;
        pos[0][0] += 1 * snake_rad;
    }
    if(pos[0][0]<0||pos[0][0]>window_width||pos[0][1]<0||pos[0][1]>window_height)
    {
        running = 0;
    }
}

void snake::check (Food* f)
{
    // cout << f->num_foods << endl;

    if (f->num_foods == 0) f->makeFood();

    if (f->num_foods > 0) {
        if (abs (pos[0][0] - f->x) < 20 && abs (pos[0][1] - f->y) < 20)
        {
            if (f->num_foods > 0) f->wipe();
            // this->eat();
            f->makeFood();
            score++;
        }
    }

}

void snake::eat()
{
    int x = pos[num][0];
    int y = pos[num][1];
    this->move();
    Circle *c = new Circle(x, y, snake_rad);
    vector<int> v{x, y};
    pos.push_back(v);
    s[num] = c;
}
