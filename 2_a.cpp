#include <vector>
#include "faster_terrain.cpp"
#include "/home/pranjal/Desktop/Arcade Machine/obstacles_coins.cpp"
#include <string>
#include </home/pranjal/Desktop/Arcade Machine/CharacterOutline.cpp>

int IR()
{
    Terrain t;
    Obstacle o;
    character c;
    Coin c1;

    initCanvas("Game", wwidth, wheight);
    c.init_Character();
    Rectangle r0(wwidth / 2, wheight - 25, wwidth, 150);
    r0.setColor(COLOR("brown"));
    r0.setFill(true);
    t.initTerrain();
    Text txt(1380, 10, "Score :");
    int i;
    for (i = 0;; i++)
    {
        Text txt1(1445, 10, to_string(i));
        XEvent event;
        if (checkEvent(event))
        {
            if (charFromEvent(event) == 'w')
            {
                c.jumpup();
                txt1.hide();
                for (int k = 0; k <= 12; k++)
                {
                    i++;
                    Text txt1(1455, 10, to_string(i));
                    o.moveObstacles();
                    c1.moveCoin();
                    int h= c1.check_coin();
                    if (h!=-1)
                    {
                        i+=500;
                        c1.collect(h);
                    }
                    wait(0.05);
                }
                c.fall();
            }

            //else if(charFromEvent(event) == 'q')
        }
        if (o.check())
        {
            break;
        }
        int j = randuv(0, 11);
        //t.genTerrain();
        if (j == 5)
        {
            o.initObstacles();
        }
        j = randuv(0, 20);

        if (j == 10)
        {
            c1.makeCoin(o);
        }
        c1.moveCoin();
        o.moveObstacles();
        wait(0.05);
    }
    string str = "Final Score : " + to_string(i);
    Text t1(750, 150, str);
    getClick();
}
