#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <bits/stdc++.h>

using namespace std;

char *int2charstar(int n){
  char *s=new char[sizeof(int)];
  sprintf(s,"%d",n);
  return s;
}
class MyButton : public Fl_Button {
public:
    MyButton* neighbours[4];
		MyButton (int x, int y, int w, int h, const char *l);
		int handle(int e); // e is incoming mouse event of different kinds
 };

MyButton :: MyButton (int x, int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
    for(int i=0;i<4;i++){
      neighbours[i]=NULL;
    }
}
int MyButton :: handle (int e) {
	if(e==FL_PUSH){
    for(int i=0;i<4;i++){
      if(neighbours[i]!=NULL && neighbours[i]->label()==""){
        neighbours[i]->label(label());
        label("");
      }
    }
  }
	return 1;
}

int main(int argc,char *argv[]){
  Fl_Window *window;
  window = new Fl_Window (600,600,"DEMO");
  MyButton *buttons[4][4];
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(i+j<6)
      buttons[i][j]=new MyButton(100+100*j,100+100*i,100,100,int2charstar(4*i+j+1));
    }
  }
  buttons[3][3]= new MyButton(400,400,100,100,"");
  for (int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if((i-1)>=0)
        buttons[i][j]->neighbours[0]=buttons[i-1][j];
      if(j+1<4)
        buttons[i][j]->neighbours[1]=buttons[i][j+1];
      if(i+1<4)
        buttons[i][j]->neighbours[2]=buttons[i+1][j];
      if(j-1>=0)
        buttons[i][j]->neighbours[3]=buttons[i][j-1];
    }
  }
  window->end();
  window->show();
  return (Fl::run());
}
