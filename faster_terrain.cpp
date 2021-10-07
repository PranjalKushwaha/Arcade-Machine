//slightly faster due to use of vectors.
#include <simplecpp>
#include <vector>
#define wheight 400
#define wwidth 1500
#define surface_rad 10

class Terrain
{
	int Y_max = 300, Y_min = 300;
	int x = 0;
	int h;
	vector<int> a;
	vector<simplecpp::Circle> c;
	vector<vector<simplecpp::Circle>> b;

public:
	void initTerrain();
	void genTerrain();
};
void Terrain::initTerrain()
{
	{
		for (; x <= wwidth; x += 20)
		{
			float k = randuv(Y_min, Y_max + 1);
			simplecpp::Circle c1(x, k, surface_rad);
			c1.setFill(true);
			c1.setColor(COLOR("green"));
			c.push_back(c1);

			h = 0;
			k += 15;
			c1.imprint();
			vector<simplecpp::Circle> v;
			/*for (; k <= wheight; k += r_rad * 2)
			{
				int r_rad = randuv(6, 16);
				simplecpp::Circle b1(x, k, r_rad);
				b1.setFill(true);
				b1.setColor(COLOR(165, 42, 42));
				h++;
				v.push_back(b1);
			}
			b.push_back(v);
			a.push_back(h);*/
		}
	}
}

void Terrain::genTerrain()
{
	float k = randuv(Y_min, Y_max + 1);
	simplecpp::Circle c1(x, k, surface_rad);
	c1.setFill(true);
	c1.setColor(COLOR("green"));
	c.push_back(c1);

	k += 15;
	vector<simplecpp::Circle> v;
	h = 0;
	/*for (; k <= wheight; k += r_rad * 2)
	{
		int r_rad = randuv(6, 16);
		simplecpp::Circle b1(x, k, r_rad);
		b1.setFill(true);
		b1.setColor(COLOR(165, 42, 42));
		v.push_back(b1);
		h++;
	}
	a.push_back(h);
	b.push_back(v);*/
	c.erase(c.begin());
	//b.erase(b.begin());
	//a.erase(a.begin());
	for (int i = 0; i < wwidth / 20; i++)
	{
		c[i].move(-20, 0);
		/*for (int j = 0; j < a[i]; j++)
		{
			b[i][j].move(-20, 0);
		}*/
	}
}
