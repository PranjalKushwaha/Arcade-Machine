#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class
#include <cstdlib> // to use rand function
#include <ctime> // to seed the rand function with time(0)
#include <FL/fl_ask.H>

#define SIZE 100 // length of button

Fl_Window* window4;

char *int2charstar (int v) { // function to use int as char array
    char *s = new char[sizeof(int)];
    sprintf(s,"%d",v);
    return s;
};

class MyButton_For_Puzzle : public Fl_Button {
    Fl_Button** button; // a pointer to the whole array of button pointers of which button objects are part of
    int id; // button IDs range from 0 to 15, and these are NOT changed throughout the process, rather the label is changed
    Fl_Button* check_button;
	public:
		MyButton_For_Puzzle (int x, int y, int w, int h, const char *l, int id1, Fl_Button* button1[], Fl_Button* check_button1);
		int handle(int e); // e is incoming mouse event of different kinds
		void check();
 };

MyButton_For_Puzzle :: MyButton_For_Puzzle (int x,int y, int w, int h, const char *l, int id1, Fl_Button* button1[], Fl_Button* check_button1) : Fl_Button (x,y,w,h,l) { // initializer-list
    button = button1;
    id = id1;
    check_button = check_button1;
}

int MyButton_For_Puzzle :: handle (int e) { // responds to button clicking

    if (check_button->label() == "Solved") return 0;

    if (e == FL_PUSH) {

        if (id+1 <= 15 && (id+1)%4 != 0) {
            if (button[id+1]->label() == "") { // checked that button[id]->label() indeed gives the label by printing it
                button[id+1]->label(button[id]->label());
                button[id]->label("");
                check();
                return 1;
            }
        }

        if (id-1 >= 0 && (id-1)%4 != 3) {
            if (button[id-1]->label() == "") {
                button[id-1]->label(button[id]->label());
                button[id]->label("");
                check();
                return 1;
            }
        }

        if (id+4 <= 15) {
            if (button[id+4]->label() == "") {
                button[id+4]->label(button[id]->label());
                button[id]->label("");
                check();
                return 1;
            }
        }

        if (id-4 >= 0) {
            if (button[id-4]->label() == "") {
                button[id-4]->label(button[id]->label());
                button[id]->label("");
                check();
                return 1;
            }
        }

	}
	return 1;
};

void MyButton_For_Puzzle::check() {
    for (int i=0; i<15; i++) {
        if (atoi(button[i]->label()) != (i+1)) { // comparing strings gives a wrong result!! but comparing integers (string to int using atoi) gives expected results
            check_button->label("Unsolved");
            return;
        }
    }
    check_button->label("Solved"); // control reaches here only if 0 hasn't been returned in the whole for loop - that means everything is in place
    check_button->color(62);
    window4->hide();
    if(fl_ask("Congratulations! You've solved the puzzle. \n Do you want to return to the main menu?"))
      return;
    else
      exit(0);
}

int Play_Puzzle(){


window4 = new Fl_Window (600,600,"15 square puzzle"); // outer window
window4->color(FL_WHITE);

Fl_Button* button[16]; // id of buttons = 0 to 15 (for simplicity, 2D array not used)

Fl_Button* check_button = new Fl_Button(225,20,150,60,"Unsolved"); // Shows "Solved" if the puzzle is solved
    check_button->color(171);
    check_button->down_color(FL_RED);

Fl_Button* solvable_button = new Fl_Button(200,520,200,60,"This is SOLVABLE for sure!");
    solvable_button->color(189);
    solvable_button->down_color(FL_GREEN);

int num[15];
int inversions = 0;

for (int i=0; i<15; i++) {
    num[i] = i+1;
}

srand(time(0));

while (true) {

    inversions = 0;

    for (int i = 0; i < 15; i++)
    {   // Fisher-Yates Method:
        // generate a random number j such that i <= j < n and
        // swap the element present at index j with the element
        // present at current index i
        int j = i + rand() % (15 - i);
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    for (int i=0; i<15; i++) {
        for (int j=i+1; j<15; j++) {
            if (num[i]>num[j]) inversions++;
        }
    }

    if (inversions%2 == 0 && inversions != 0) break;

    // Method of checking for square matrices:
    // for number of rows/columns = even: (e.g. our 4 X 4 matrix)
        // if the blank cell is present on an "even-row" (second, fourth, ...) and the number of inversions = even, then it is solvable
        // if the blank cell is present on an "odd-row" (first, third, ...) and the number of inversions = odd, then it is solvable
    // for number of rows/columns = odd:
        // if the number of inversions = even, then it is solvable

}

// uncomment the below block to see the "Solved" feature of check_button (this basically arranges everything in place, and 2 more moves will changed the check_button label to "Solved", color changes to green
/*
for (int i=0; i<15; i++) {
    num[i] = i+1;
}
*/

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        if (!(i == 3 && j == 3)) {
            char* label = int2charstar(num[4*i+j]);
            button[4*i+j] = new MyButton_For_Puzzle (100+SIZE*j,100+SIZE*i,SIZE,SIZE,label,4*i+j,button,check_button);
            button[4*i+j]->color(92);
        }
        else {
            button[4*i+j] = new MyButton_For_Puzzle (100+SIZE*j,100+SIZE*i,SIZE,SIZE,"",4*i+j,button,check_button);
            button[4*i+j]->color(92);
        }
    }
}

window4->end();
window4->show();
return(Fl::run());  // the process waits from here on for events
}
