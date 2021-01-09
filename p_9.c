//Author : Deepansh Dubey.
//Purpose: Write a program to perform 2D Rotation on line, ellipse and polygon.
//Date   : 04/01/2021.

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

int x1, y1, x2, y2, rotated_point_x, rotated_point_y;
double degree, radian;
int i, x, y, theta, b;
int t11, u11, t22, u22, t33, u33, t1, u1, t2, u2, t3, u3;
double s, c, angle, g;
float f;

void frame()
{
  line(0, 0, getmaxx(), 0);
  line(0, 0, 0, getmaxy());
  line(0, getmaxy(), getmaxx(), getmaxy());
  line(getmaxx(), 0, getmaxx(), getmaxy());
  line(0, 30, getmaxx(), 30);
  line(213, 0, 213, 465);
  line(426, 0, 426, 465);
  line(0, 465, getmaxx(), 465);
}

void pause()
{
  outtextxy(10, 470, "Press any key to contine ...");
  getch();
}

void rotate_line()
{
  x1 = 50;
  y1 = 250;
  x2 = 160;
  y2 = 250;
  line(x1, y1, x2, y2);
  for (degree = 0; degree < 91; degree++)
  {
    frame();
    outtextxy(68, 12, "-: Line :-");
    outtextxy(15, 65, "# Rotation Details :-");
    outtextxy(15, 95, "* Initial Angle : 0'");
    outtextxy(15, 110, "* Final Angle = 90'");
    line(x1, y1, x2, y2);
    radian = degree * 0.01745;
    rotated_point_x = (int)(x1 + ((x2 - x1) * cos(radian) - (y2 - y1) * sin(radian)));
    rotated_point_y = (int)(y1 + ((x2 - x1) * sin(radian) + (y2 - y1) * cos(radian)));
    line(x1, y1, rotated_point_x, rotated_point_y);
    delay(46);
    cleardevice();
  }
  frame();
  outtextxy(68, 12, "-: Line :-");
  line(x1, y1, x2, y2);
  line(x1, y1, rotated_point_x, rotated_point_y);
  outtextxy(15, 65, "# Rotation Details :-");
  outtextxy(15, 95, "* Initial Angle : 0'");
  outtextxy(15, 110, "* Final Angle = 90'");
}

void rotate_ellipse(int xc, int yc, int a, int b, float alpha, int color)
{
  float t = 3.14 / 180;
  alpha = 360 - alpha;
  for (i = 0; i < 360; i++)
  {
    theta = i;
    x = a * cos(t * theta) * cos(t * alpha) + b * sin(t * theta) * sin(t * alpha);
    y = b * sin(t * theta) * cos(t * alpha) - a * cos(t * theta) * sin(t * alpha);
    putpixel(xc + x, yc - y, color);
  }
}

void rotate_polygon()
{
  t11 = t1 = 450;
  u11 = u1 = 300;
  t22 = t2 = 550;
  u22 = u2 = 350;
  t33 = t3 = 450;
  u33 = u3 = 400;
  outtextxy(480, 12, "-: Polygon :-");
  for (g = 0; g < 16; g = g + 1)
  {
    frame();
    outtextxy(68, 12, "-: Line :-");
    outtextxy(265, 12, "-: Ecllipse :-");
    outtextxy(480, 12, "-: Polygon :-");
    line(x1, y1, x2, y2);
    line(x1, y1, rotated_point_x, rotated_point_y);
    outtextxy(15, 65, "# Rotation Details :-");
    outtextxy(15, 95, "* Initial Angle : 0'");
    outtextxy(15, 110, "* Final Angle = 90'");
    rotate_ellipse(319, 300, 70, 40, f, 15);
    outtextxy(228, 65, "# Rotation Details :-");
    outtextxy(228, 95, "* Initial Angle : 0'");
    outtextxy(228, 110, "* Final Angle = 90'");
    outtextxy(441, 65, "# Rotation Details :-");
    outtextxy(441, 95, "* Initial Angle : 90'");
    outtextxy(441, 110, "* Final Angle = 80'");
    line(t11, u11, t22, u22);
    line(t22, u22, t33, u33);
    line(t33, u33, t11, u11);
    angle = g / 10;
    c = cos(angle * M_PI / 180);
    s = sin(angle * M_PI / 180);
    t1 = floor(t1 * c + u1 * s);
    u1 = floor(-t1 * s + u1 * c);
    t2 = floor(t2 * c + u2 * s);
    u2 = floor(-t2 * s + u2 * c);
    t3 = floor(t3 * c + u3 * s);
    u3 = floor(-t3 * s + u3 * c);
    line(t1, u1, t2, u2);
    line(t2, u2, t3, u3);
    line(t3, u3, t1, u1);
    delay(100);
    cleardevice();
  }
  frame();
  outtextxy(68, 12, "-: Line :-");
  outtextxy(265, 12, "-: Ecllipse :-");
  outtextxy(480, 12, "-: Polygon :-");
  line(x1, y1, x2, y2);
  line(x1, y1, rotated_point_x, rotated_point_y);
  outtextxy(15, 65, "# Rotation Details :-");
  outtextxy(15, 95, "* Initial Angle : 0'");
  outtextxy(15, 110, "* Final Angle = 90'");
  rotate_ellipse(319, 300, 70, 40, f, 15);
  outtextxy(228, 65, "# Rotation Details :-");
  outtextxy(228, 95, "* Initial Angle : 0'");
  outtextxy(228, 110, "* Final Angle = 90'");
  outtextxy(441, 65, "# Rotation Details :-");
  outtextxy(441, 95, "* Initial Angle : 90'");
  outtextxy(441, 110, "* Final Angle = 80'");
  line(t11, u11, t22, u22);
  line(t22, u22, t33, u33);
  line(t33, u33, t11, u11);
  line(t1, u1, t2, u2);
  line(t2, u2, t3, u3);
  line(t3, u3, t1, u1);
}

void part1()
{
  outtextxy(68, 12, "-: Line :-");
  outtextxy(15, 65, "# Rotation Details :-");
  outtextxy(15, 95, "* Initial Angle : 0'");
  outtextxy(15, 110, "* Final Angle = 90'");
  frame();
  rotate_line();
  pause();
}

void part2()
{
  for (f = 0; f < 91; f++)
  {
    frame();
    outtextxy(68, 12, "-: Line :-");
    outtextxy(265, 12, "-: Ecllipse :-");
    line(x1, y1, x2, y2);
    line(x1, y1, rotated_point_x, rotated_point_y);
    outtextxy(15, 65, "# Rotation Details :-");
    outtextxy(15, 95, "* Initial Angle : 0'");
    outtextxy(15, 110, "* Final Angle = 90'");
    outtextxy(228, 65, "# Rotation Details :-");
    outtextxy(228, 95, "* Initial Angle : 0'");
    outtextxy(228, 110, "* Final Angle = 90'");
    rotate_ellipse(319, 300, 70, 40, f, 15);
    delay(46);
    cleardevice();
  }
  frame();
  outtextxy(68, 12, "-: Line :-");
  outtextxy(265, 12, "-: Ecllipse :-");
  line(x1, y1, x2, y2);
  line(x1, y1, rotated_point_x, rotated_point_y);
  outtextxy(15, 65, "# Rotation Details :-");
  outtextxy(15, 95, "* Initial Angle : 0'");
  outtextxy(15, 110, "* Final Angle = 90'");
  outtextxy(228, 65, "# Rotation Details :-");
  outtextxy(228, 95, "* Initial Angle : 0'");
  outtextxy(228, 110, "* Final Angle = 90'");
  rotate_ellipse(319, 300, 70, 40, f, 15);
  pause();
}

void part3()
{
  rotate_polygon();
  outtextxy(10, 470, "Press any key to EXIT ...");
  getch();
}

void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  setcolor(2);
  part1();
  part2();
  part3();
  closegraph();
}