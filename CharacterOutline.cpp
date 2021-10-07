#include <simplecpp>
#include <vector>
class character
{
  vector<Rectangle> r1;
  public:
  void init_Character();
  void jumpup();
  void fall();
} ;
void character::fall()
{
  for (int i = 0; i < 41; i++)
  {
    r1[i].move(0,110);
  }
}
void character::jumpup()
{
  for (int i = 0; i < 41; i++)
  {
    r1[i].move(0,-110);
  }
}

void character::init_Character()
{
  //torso
  Rectangle r(50, 80, 26, 26);
  r.setColor(COLOR("red"));
  r.setFill(true);
  Rectangle a(50, 62, 12, 10), b(40, 62, 7, 10);
  b.setColor(COLOR("red"));
  b.setFill(true);
  a.setColor(COLOR("yellow"));
  a.setFill(true);
  Rectangle c(59, 62, 7, 10);
  c.setColor(COLOR("red"));
  c.setFill(true);
  Rectangle d(34, 87, 6, 28), e(40, 97, 6, 8), f(28, 96, 6, 10);
  Rectangle g(66, 87, 6, 28), h(60, 97, 6, 8), i(72, 96, 6, 10);
  d.setColor(COLOR("red"));
  d.setFill(true);
  f.setColor(COLOR("red"));
  f.setFill(true);
  g.setColor(COLOR("red"));
  g.setFill(true);
  h.setColor(COLOR("red"));
  h.setFill(true);
  e.setColor(COLOR("red"));
  e.setFill(true);
  i.setColor(COLOR("red"));
  i.setFill(true);
  //hands
  /*) r.setColor(COLOR("red"));
  r.setFill(true);*/
  Rectangle j(31, 65, 12, 16);
  Rectangle k(28, 77, 6, 8), l(28, 86, 6, 10), m(21, 68, 8, 10), n(14, 70, 6, 6);
  Rectangle o(18, 84, 14, 22);
  j.setColor(COLOR("yellow"));
  j.setFill(true);
  k.setColor(COLOR("yellow"));
  k.setFill(true);
  l.setColor(COLOR(254, 216, 177));
  l.setFill(true);
  m.setColor(COLOR("yellow"));
  m.setFill(true);
  n.setColor(COLOR("yellow"));
  n.setFill(true);
  o.setColor(COLOR(254, 216, 177));
  o.setFill(true);
  Rectangle q(69, 65, 12, 16);
  Rectangle s(72, 77, 6, 8), t(72, 86, 6, 10), u(79, 68, 8, 10), v(86, 70, 6, 6);
  Rectangle w(82, 84, 14, 22);
  q.setColor(COLOR("yellow"));
  q.setFill(true);
  s.setColor(COLOR("yellow"));
  s.setFill(true);
  t.setColor(COLOR(254, 216, 177));
  t.setFill(true);
  u.setColor(COLOR("yellow"));
  u.setFill(true);
  v.setColor(COLOR("yellow"));
  v.setFill(true);
  w.setColor(COLOR(254, 216, 177));
  w.setFill(true);
  //legs
  Rectangle l1(27, 106, 20, 10), l2(14, 108, 6, 6);
  Rectangle l3(73, 106, 20, 10), l4(86, 108, 6, 6);
  l1.setColor(COLOR("black"));
  l1.setFill(true);
  l2.setColor(COLOR("black"));
  l2.setFill(true);
  l3.setColor(COLOR("black"));
  l3.setFill(true);
  l4.setColor(COLOR("black"));
  l4.setFill(true);
  //Face
  Rectangle f1(50, 43, 12, 28), f2(38, 52, 12, 10), f3(63, 54, 14, 6);
  f1.setColor(COLOR(254, 216, 177));
  f1.setFill(true);
  f2.setColor(COLOR(254, 216, 177));
  f2.setFill(true);
  f3.setColor(COLOR(254, 216, 177));
  f3.setFill(true);
  //brown                   //pale                        //pale
  Rectangle f4(38, 38, 12, 18), f5(41, 38, 6, 6), f6(29, 32, 6, 6), f7(29, 41, 6, 12);
  f4.setColor(COLOR(101, 67, 33));
  f4.setFill(true);
  f5.setColor(COLOR(254, 216, 177));
  f5.setFill(true);
  f6.setColor(COLOR(101, 67, 33));
  f6.setFill(true);
  f7.setColor(COLOR(254, 216, 177));
  f7.setFill(true);
  //brown
  Rectangle f8(29, 50, 6, 6), f9(23, 44, 6, 18), f10(59, 35, 6, 12);
  f8.setColor(COLOR(101, 67, 33));
  f8.setFill(true);
  f9.setColor(COLOR(101, 67, 33));
  f9.setFill(true);
  f10.setColor(COLOR("black"));
  f10.setFill(true);
  //pale
  Rectangle f11(62, 45, 12, 6), f12(65, 35.5, 6, 13), f13(72, 38.5, 8, 7);
  f11.setColor(COLOR(254, 216, 177));
  f11.setFill(true);
  f12.setColor(COLOR(254, 216, 177));
  f12.setFill(true);
  f13.setColor(COLOR(254, 216, 177));
  f13.setFill(true);
  //yellow
  Rectangle f14(50, 26, 48, 6), f15(47, 20, 26, 6);
  f14.setColor(COLOR("yellow"));
  f14.setFill(true);
  f15.setColor(COLOR("yellow"));
  f15.setFill(true);
  r1.push_back(a);
  r1.push_back(b);
  r1.push_back(c);
  r1.push_back(d);
  r1.push_back(e);
  r1.push_back(f);
  r1.push_back(g);
  r1.push_back(h);
  r1.push_back(i);
  r1.push_back(j);
  r1.push_back(k);
  r1.push_back(l);
  r1.push_back(m);
  r1.push_back(n);
  r1.push_back(o);
  //r1.push_back(p);
  r1.push_back(q);
  r1.push_back(r);
  r1.push_back(s);
  r1.push_back(t);
  r1.push_back(u);
  r1.push_back(v);
  r1.push_back(w);
  r1.push_back(l1);
  r1.push_back(l2);
  r1.push_back(l3);
  r1.push_back(l4);
  r1.push_back(f1);
  r1.push_back(f2);
  r1.push_back(f3);
  r1.push_back(f4);
  r1.push_back(f5);
  r1.push_back(f6);
  r1.push_back(f7);
  r1.push_back(f8);
  r1.push_back(f9);
  r1.push_back(f10);
  r1.push_back(f11);
  r1.push_back(f12);
  r1.push_back(f13);
  r1.push_back(f14);
  r1.push_back(f15);
  for(int i =0;i<41;i++)
  {
    r1[i].move(400,180);
  }
}
