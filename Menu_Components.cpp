#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <bits/stdc++.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.H>
#include </home/pranjal/Desktop/Arcade Machine/2_a.cpp>
//#include "Common.cpp"
using namespace std;

//void Snake_Game(){}
//void Infinite_Runner(){}
int Tic_Tac_Toe();
int Flappy_UFO();
int Puzzle();
int IR1();
class Button_For_Snake: public Fl_Button{
 public:
  Button_For_Snake(int x,int y,int w,int h,const char* l): Fl_Button(x,y,w,h,l){}
  int handle(int e);
};

int Button_For_Snake:: handle(int e){
  if (e==FL_PUSH){
    //Snake_Game();
  }
  return 0;
}

class Button_For_IR: public Fl_Button{
  public :
   Button_For_IR(int x,int y,int w,int h,const char* l): Fl_Button(x,y,w,h,l){}
   int handle(int e);
};

int Button_For_IR:: handle(int e){
  if (e==FL_PUSH){
    IR1();//Infinite_Runner();
  }
  return 0;
}

class Button_For_FB: public Fl_Button{
  public:
   Button_For_FB(int x,int y,int w,int h,const char* l): Fl_Button(x,y,w,h,l){}
   int handle(int e);
};

int Button_For_FB:: handle(int e){
  if (e==FL_PUSH){
    Flappy_UFO();
  }
  return 0;
}

class Button_For_Tic : public Fl_Button{
 public:
  Button_For_Tic(int x,int y,int w,int h,const char* l): Fl_Button(x,y,w,h,l){}
  int handle(int e);
};

int Button_For_Tic :: handle(int e){
  if (e==FL_PUSH){
  cout << 2<< endl;
    Tic_Tac_Toe();
  }
  return 0;
}

class Button_For_15Puzzle : public Fl_Button{
 public:
  Button_For_15Puzzle(int x,int y,int w,int h,const char* l): Fl_Button(x,y,w,h,l){}
  int handle(int e);
};

int Button_For_15Puzzle :: handle(int e){
  if (e==FL_PUSH){
    Puzzle();
  }
  return 0;
}

class Menu{
  private:
    Fl_Button* menutext;
    Button_For_Snake* option1;
    Button_For_IR* option2;
    Button_For_FB* option3;
    Button_For_Tic* option4;
    Button_For_15Puzzle* option5;
    Fl_Box* box;
    Fl_JPEG_Image* backimg;
    //Fl_JPEG_Image* IRImg;
    //Fl_JPEG_Image* SnakeImg;
  public:
    void initMenu();
};

void Menu:: initMenu(){
  box= new Fl_Box(0,0,800,800);
  backimg=new Fl_JPEG_Image("retro.jpg");
  box->image(backimg);
  //IRImg= new Fl_JPEG_Image("IR.jpg");
  option2= new Button_For_IR(150,400,200,100,"Mario Infinite Runner");
  //option2->image(IRImg);
  //option2->label("Mario Infinite Runner");
  option1= new Button_For_Snake(450,400,200,100,"Snake Game");
  menutext= new Fl_Button(200,200,400,100,"Welcome to our Arcade Machine");
  option3= new Button_For_FB(150,520,200,100,"Flappy UFO");
  option4= new Button_For_Tic(450,520,200,100,"Tic_Tac_Toe");
  option5= new Button_For_15Puzzle(300,640,200,100,"15 Squares Puzzle");
}
