#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <cstdlib>
#include <ctime>

#define new_window_width 400
#define window_width 800
#define window_height 600

#define num_obs 14

int score = 0;

class Obstacle_Rec: public Fl_Widget{

   public:
     int x,y,w,h;
     Obstacle_Rec(int x,int y,int w,int h): Fl_Widget(x,y,w,h){
       this->x=x , this->y=y;
       this->w=w , this->h=h;

     }
     int getX();
     int getY();
     int getW();
     int getH();
     virtual void draw();
     virtual void refresh(int dx, int dy);
     virtual void wipe();
};

int Obstacle_Rec :: getX(){
   return x;
}

int Obstacle_Rec :: getY(){
   return y;
}

int Obstacle_Rec :: getW(){
   return w;
}

int Obstacle_Rec :: getH(){
   return h;
}

void Obstacle_Rec :: draw(){
   fl_draw_box(FL_FLAT_BOX,x,y,w,h,FL_GREEN);
}


void Obstacle_Rec :: wipe(){
   fl_draw_box(FL_FLAT_BOX,x,y,w,h,247);
}

void Obstacle_Rec :: refresh(int dx, int dy){
   wipe();
   x=dx , y=dy;
   resize(x,y,w,h);
   fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_GREEN);
}

class Bird_Obstacles : public Obstacle_Rec {

  Obstacle_Rec* v[14];

   public:
    Bird_Obstacles() : Obstacle_Rec(0,0,0,0) {}
    void init_Obstacles();
    void move();

    friend class Bird;

};

void Bird_Obstacles :: init_Obstacles(){
    srand(time(0));
    int u=40+rand()%100;
    v[0]= new Obstacle_Rec(window_width/2+2*window_width/14*0,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[1]= new Obstacle_Rec(window_width/2+2*window_width/14*0,0,window_width/14,1.0*window_height/3-60+u);
    u=40+rand()%100;
    while(abs(1.0*window_height/3+60+u-v[0]->getX())<6){
      u=40+rand()%100;
    }
    v[2]= new Obstacle_Rec(window_width/2+2*window_width/14*2,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[3]= new Obstacle_Rec(window_width/2+2*window_width/14*2,0,window_width/14,1.0*window_height/3-60+u);
    u=40+rand()%100;
    while(abs(1.0*window_height/3+60+u-v[2]->getX())<6){
      u=40+rand()%100;
    }
    v[4]= new Obstacle_Rec(window_width/2+2*window_width/14*4,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[5]= new Obstacle_Rec(window_width/2+2*window_width/14*4,0,window_width/14,1.0*window_height/3-60+u);
    u=40+rand()%100;
    while(abs(1.0*window_height/3+60+u-v[4]->getX())<6){
      u=40+rand()%100;
    }
    v[6]= new Obstacle_Rec(window_width/2+2*window_width/14*6,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[7]= new Obstacle_Rec(window_width/2+2*window_width/14*6,0,window_width/14,1.0*window_height/3-60+u);
    u=40+rand()%100;
    while(abs(1.0*window_height/3+60+u-v[6]->getX())<6){
      u=40+rand()%100;
    }
    v[8]= new Obstacle_Rec(window_width/2+2*window_width/14*8,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[9]= new Obstacle_Rec(window_width/2+2*window_width/14*8,0,window_width/14,1.0*window_height/3-60+u);
    u=40+rand()%100;
    while(abs(1.0*window_height/3+60+u-v[8]->getX())<6){
      u=40+rand()%100;
    }
    v[10]= new Obstacle_Rec(window_width/2+2*window_width/14*10,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[11]= new Obstacle_Rec(window_width/2+2*window_width/14*10,0,window_width/14,1.0*window_height/3-60+u);
    u=40+rand()%100;
    while(abs(1.0*window_height/3+60+u-v[10]->getX())<6){
      u=40+rand()%100;
    }
    v[12]= new Obstacle_Rec(window_width/2+2*window_width/14*12,1.0*window_height/3+60+u,window_width/14,2.0*window_height/3);
    v[13]= new Obstacle_Rec(window_width/2+2*window_width/14*12,0,window_width/14,1.0*window_height/3-60+u);
}

void Bird_Obstacles :: move(){
  for(int i=0;i<14;i++){
    v[i]->refresh(v[i]->getX()-1,v[i]->getY());
    if(i%2==0 && v[i]->getX()<-1.0*window_width/14){
        v[i]->refresh(v[(13+i)%14]->getX()+3.0*window_width/14,v[i]->getY());
        v[i+1]->refresh(v[(13+i)%14]->getX()+3.0*window_width/14,v[i+1]->getY());
        score++;
    }
  }
}
