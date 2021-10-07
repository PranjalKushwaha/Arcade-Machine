#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

#define circle_dia 24
#define circles_dist 40
#define lid_width 32
#define lid_height 24
#define init_vel 20
#define dt 0.1
#define grav 5

#include "bird_obstacles6.cpp"

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
    virtual void wipe() = 0;
    virtual void refresh(int dx, int dy) = 0;
    virtual int handle(int e) = 0;

    friend class Bird;

};

class Circle : public Shape
{
public:
    Circle(int x, int y, int w) : Shape(x, y, w, w) {}
    virtual void draw()
    {
        fl_color(FL_BLACK);
        fl_pie(x, y, w, h, 0, 360);
        fl_pie(x+circles_dist, y, w, h, 0, 360);
        fl_draw_box (FL_FLAT_BOX,x+(circle_dia*0.5),y,circles_dist,h,FL_BLACK);
        fl_color(221);
        fl_pie(x+(circle_dia+circles_dist)*0.5-lid_width*0.5,y-lid_height*0.5,lid_width,lid_height,0,180);

        fl_color(FL_WHITE);
        fl_pie(x+circle_dia*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
        fl_pie(x+circle_dia*0.5+circles_dist*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
        fl_pie(x+circle_dia*0.5+circles_dist*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);

        fl_draw_box (FL_FLAT_BOX,0,window_height-50,new_window_width,50,72);

    }
    virtual void wipe()
    {
        fl_color(247);
        fl_pie(x, y, circle_dia, h, 0, 360);
        fl_pie(x+circles_dist, y, circle_dia, h, 0, 360);
        fl_draw_box (FL_FLAT_BOX,x+(circle_dia*0.5),y,circles_dist,h,247);
        fl_color(247);
        fl_pie(x+(circle_dia+circles_dist)*0.5-lid_width*0.5,y-lid_height*0.5,lid_width,lid_height,0,180);
        fl_color(247);
        fl_pie(x+circle_dia*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
        fl_pie(x+circle_dia*0.5+circles_dist*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
        fl_pie(x+circle_dia*0.5+circles_dist-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
    }
    virtual void refresh(int dx, int dy)
    {
        x = dx;
        y = dy;
        resize(x, y, w, h);
        fl_color(FL_BLACK);
        fl_pie(x, y, w, h, 0, 360);
        fl_pie(x+circles_dist, y, w, h, 0, 360);
        fl_draw_box (FL_FLAT_BOX,x+(circle_dia*0.5),y,circles_dist,h,FL_BLACK);
        fl_color(221);
        fl_pie(x+(circle_dia+circles_dist)*0.5-lid_width*0.5,y-lid_height*0.5,lid_width,lid_height,0,180);
        fl_color(FL_WHITE);
        fl_pie(x+circle_dia*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
        fl_pie(x+circle_dia*0.5+circles_dist*0.5-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);
        fl_pie(x+circle_dia*0.5+circles_dist-w*0.1, y+h*0.3, w*0.2, h*0.4, 0, 360);

        fl_draw_box (FL_FLAT_BOX,0,window_height-50,new_window_width,50,72);
    }
    virtual int handle(int e)
    {
        return 1;
    };
};

class Bird : public Circle {

private:
    Circle* b;
    double vel;

public:
    bool flying;
    Bird() : Circle(0,0,0) {}
    void initBird();
    void move();
    void check (Bird_Obstacles* bo);
    virtual int handle (int e);

};

void Bird :: initBird() {
    b = new Circle(50,300,circle_dia);
    vel = init_vel;
    flying = true;
}

void Bird :: move() {
    b->wipe();
    b->refresh (b->x,b->y-(vel*dt - 0.5*grav*dt*dt));
    vel -= grav*dt;
}

void Bird :: check (Bird_Obstacles* bo) {

    if (flying) {
        if (b->y < 0 || b->y > window_height-50-circle_dia) {
            flying = false;
            return;
        }

        for (int i=0; i<num_obs; i++) {

            if (b->x >= bo->v[i]->getX()
                && b->x <= (bo->v[i]->getX() + bo->v[i]->getW())
                && b->y >= bo->v[i]->getY()
                && b->y <= (bo->v[i]->getY() + bo->v[i]->getH())) {
                    flying = false;
                    return;
            }

            if (b->x+circles_dist+circle_dia >= bo->v[i]->getX()
                && b->x+circles_dist+circle_dia <= (bo->v[i]->getX() + bo->v[i]->getW())
                && b->y >= bo->v[i]->getY()
                && b->y <= (bo->v[i]->getY() + bo->v[i]->getH())) {
                    flying = false;
                    return;
            }

            if (b->x >= bo->v[i]->getX()
                && b->x <= (bo->v[i]->getX() + bo->v[i]->getW())
                && b->y+circle_dia >= bo->v[i]->getY()
                && b->y+circle_dia <= (bo->v[i]->getY() + bo->v[i]->getH())) {
                    flying = false;
                    return;
            }

            if (b->x+circles_dist+circle_dia >= bo->v[i]->getX()
                && b->x+circles_dist+circle_dia <= (bo->v[i]->getX() + bo->v[i]->getW())
                && b->y+circle_dia >= bo->v[i]->getY()
                && b->y+circle_dia <= (bo->v[i]->getY() + bo->v[i]->getH())) {
                    flying = false;
                    return;
            }

        }

    }

}

int Bird :: handle (int e) {

    if (e == FL_KEYDOWN) {
        if (Fl::event_key() == 97)
            vel = vel+30;
    }
    return 1;

}
