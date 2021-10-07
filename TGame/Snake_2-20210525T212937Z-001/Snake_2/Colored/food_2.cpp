#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <cstdlib>
#include <ctime>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1000

class Food : public Fl_Widget {

private:
    int x, y, w, h;
    // Food_Shape fs;
    int num_foods = 0;

public:
    Food (int x, int y, int w, int h);
    virtual void makeFood();
    virtual void draw() {}
    virtual void wipe();
    // virtual void refresh() = 0;

    friend class snake;
};

Food :: Food (int x, int y, int w, int h) : Fl_Widget (x,y,w,h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    num_foods = 0;
    // makeFood();
}

void Food :: wipe() {
    fl_draw_box (FL_FLAT_BOX,x,y,w+1,h+1,79);
}

void Food :: makeFood() {

    srand (time(0));
    int v = rand()%3;

    int x1 = 0, y1 = 0;
    while (!(x1>10)) {
        x1 = rand() % (WINDOW_WIDTH - 10);
    }
    while (!(y1>10)) {
        y1 = rand() % (WINDOW_HEIGHT - 10);
    }

    x = x1; y = y1;
    resize(x,y,w,h);

    if (v==0) {
        fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
    }
    else if (v==1) {
        fl_color(130);
        fl_pie (x,y,w,h,0,360);
    }
    else if (v==2) {
        fl_color(240);
        fl_polygon (x,y,x,y+h,x+w,y+h);
    }

    num_foods++;

}
