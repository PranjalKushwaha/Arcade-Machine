#include <FL/fl_ask.H>
#include <string>
#include "bird_ufo.cpp"
//#include "Common.cpp"
using namespace std;

Fl_Window window2(new_window_width,window_height,"Flappy Bird - UFO Version");

Bird* b = new Bird;
Bird_Obstacles bo;

void ShowMenu();
void callback(void *)
{
    b->move();
    b->check(&bo);
    bo.move();

    if (b->flying)
        Fl::repeat_timeout(0.01, callback);

    else {
        window2.hide();
        string s = to_string(score);
        s = "Your score is "+s;
        s+="Do you want to return to the main menu?";
        const char * c = s.c_str();
        if(fl_ask("Your score is %d \n Do you want to return to the main menu?",score))
          return;
        else exit(0);

    }

}
