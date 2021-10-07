#define window_height 1000
#define window_width 1200
#include <FL/fl_ask.H>
#include <string>
#include "snake.cpp"
using namespace std;
Fl_Window window(window_width, window_height, "Snake");
snake *s = new snake();
Food *f = new Food (0,0,20,20);

void callback(void *)
{
    s->move();
    s->check(f);

    if (running == 1)
        Fl::repeat_timeout(0.16-0.005*score, callback);
    else
    {
        window.hide();
        string s = to_string(score);
        s = "Your score is "+s;
        s+="Do you want to return to the main menu?";
        const char * c = s.c_str();
        if(fl_ask("Your score is %d \n Do you want to return to the main menu?",score));
    }
}

int main(int argc, char *argv[])
{
    // outer window

    s->init_snake();
    window.color(79);
    window.end();
    window.show();
    Fl::add_timeout(0.04, callback);
    return Fl::run(); // the process waits from here on for events

}
