#include <FL/fl_ask.H>
#include <string>
#include "bird_ufo.cpp"
using namespace std;

Fl_Window window(new_window_width,window_height,"Flappy Bird - UFO Version");
Bird* b = new Bird;
Bird_Obstacles bo;

void callback(void *)
{
    b->move();
    b->check(&bo);
    bo.move();

    if (b->flying)
        Fl::repeat_timeout(0.01, callback);

    else {
        window.hide();
        string s = to_string(score);
        s = "Your score is "+s;
        s+="Do you want to return to the main menu?";
        const char * c = s.c_str();
        if(fl_ask("Your score is %d \n Do you want to return to the main menu?",score));
    }

}


int main(){

    b->initBird();
    bo.init_Obstacles();

    window.color(FL_WHITE);

    window.end();
    window.show();

    Fl::add_timeout(0.04, callback);

    return Fl::run(); // the process waits from here on for events

}
