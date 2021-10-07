#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <bits/stdc++.h>
#include "FlappyBirdWindow.cpp"
#include "Menu_Components.cpp"
#include "tic.cpp"
#include "15square.cpp"
using namespace std;

//void Snake_Game(){}
//void Infinite_Runner(){}


Fl_Window* window = new Fl_Window(800,800,"Menu");

Menu *m;

void ShowMenu(){
  window->show();
}
int IR1(){
	window->hide();
	IR();
	return (Fl::run());
}
int Flappy_UFO(){
      window->hide();
      b->initBird();
      bo.init_Obstacles();
      window2.color(247);
      window2.end();
      window2.show();
      Fl::add_timeout(0.04, callback);
      return (Fl::run());
}

int Tic_Tac_Toe(){
     window->hide();
     Play_Tic();
     return (Fl::run());
}

int Puzzle(){
     window->hide();
     Play_Puzzle();
     return (Fl::run());
}
int main(){
   m=new Menu();
   m->initMenu();
   window->end();
   window->show();
   return (Fl::run());
}
