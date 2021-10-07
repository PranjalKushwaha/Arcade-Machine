#include <simplecpp>
#include <ctime>
#include <cassert>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 400
#define OBSTACLE_MAX_H 100
#define OBSTACLE_W 100
#define GAP_OBSTACLES 300
#define GAP_OBSTACLE_COIN 200
#define GAP_COINS 400

class Obstacle
{

private:
    bool terrain_drawn;
    vector<Rectangle> upper;
    int num = 0;

public:
    void initTerrain();
    void initObstacles();
    void moveObstacles();
    bool check();
    friend class Coin;
};

bool Obstacle::check()
{
    for (int i = 0; i < num; i++)
    {
        int x = upper[i].getX();
        if (x <= 540 && x >= 400)
        {
            return true;
        }
    }
    return false;
}

void Obstacle ::initTerrain()
{
    terrain_drawn = true;
}

void Obstacle ::initObstacles()
{

    // assert(terrain_drawn);

    srand(time(0));
    double y, w, h;

    //if (i==0) x = START_OBSTACLE_X;
    //else if (x+OBSTACLE_W >= WINDOW_WIDTH) break;
    // x = randuv(10 * OBSTACLE_W, 15 * OBSTACLE_W);
    w = OBSTACLE_W;
    h = randuv(-OBSTACLE_MAX_H, OBSTACLE_MAX_H);
    if (abs(h) < 20)
    {
        h += 20;
    }
    y = WINDOW_HEIGHT - 110 - h / 2;

    if (num == 0)
    {
        /*
        if (c1.num_coins > 0 && !(WINDOW_WIDTH - c1.coins[c1.num_coins-1].getX() > GAP_OBSTACLE_COIN))
            return;
*/
        Rectangle u(WINDOW_WIDTH, y, w, h);
        (h > 0) ? u.setColor(COLOR("red")) : u.setColor(COLOR("white"));
        u.setFill(true);
        upper.push_back(u);
        num++;
    }

    if (num > 0 && (WINDOW_WIDTH - upper[num - 1].getX() > GAP_OBSTACLES)
        //        && (WINDOW_WIDTH - c1.coins[c1.num_coins-1].getX() > GAP_OBSTACLE_COIN)
    )
    {

        Rectangle u(WINDOW_WIDTH, y, w, h);
        (h > 0) ? u.setColor(COLOR("red")) : u.setColor(COLOR("white"));
        u.setFill(true);
        upper.push_back(u);
        num++;
    }

    /*
        double x1 = randuv (START_OBSTACLE_X, WINDOW_WIDTH);
        while (true) {
            x1 = randuv (x, WINDOW_WIDTH);
            if (x1-x > OBSTACLE_W/2) break;
        }
        x = x1;
*/
}

void Obstacle ::moveObstacles()
{

    for (int i = 0; i < num; i++)
    {
        upper[i].move(-20, 0);
    }
}

class Coin
{

private:
    int num_coins = 0;
    vector<simplecpp::Circle> coins;
    int radius = 10;

public:
    void makeCoin(Obstacle &o1);
    void moveCoin();
    int check_coin();
    void collect(int i);
    friend class Obstacle;
};
int Coin::check_coin()
{
    for (int i = 0; i < num_coins; i++)
    {
        int x = coins[i].getX();
        if ((x <= 540 && x >= 400))
        {
            return i;
        }
    }
    return -1;
}

void Coin::collect(int i)
{
    if (!coins.empty())
    {
        num_coins--;
        coins.erase(coins.begin() + i);
    }
}
void Coin ::makeCoin(Obstacle &o1)
{

    srand(time(0));

    int y = 150; //randuv(WINDOW_HEIGHT - 150, WINDOW_HEIGHT - 75);

    if (num_coins == 0)
    {

        if (o1.num > 0 && !(WINDOW_WIDTH - o1.upper[o1.num - 1].getX() > GAP_OBSTACLE_COIN))
            return;

        simplecpp::Circle c(WINDOW_WIDTH, y, radius);
        c.setColor(COLOR(255, 215, 0));
        c.setFill(true);

        coins.push_back(c);
        num_coins++;
    }

    else if (num_coins > 0 && (WINDOW_WIDTH - coins[num_coins - 1].getX() > GAP_COINS))
    {

        if (o1.num > 0 && !(WINDOW_WIDTH - o1.upper[o1.num - 1].getX() > GAP_OBSTACLE_COIN))
            return;

        simplecpp::Circle c(WINDOW_WIDTH, y, radius);
        c.setColor(COLOR(255, 215, 0));
        c.setFill(true);

        coins.push_back(c);
        num_coins++;
    }
}

void Coin ::moveCoin()
{

    for (int i = 0; i < num_coins; i++)
    {
        coins[i].move(-20, 0);
    }
}
