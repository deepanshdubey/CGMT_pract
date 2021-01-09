//Author : Deepansh Dubey.
//Purpose: Write a program to perform 3D Rotation an object.
//Date   : 05/01/2021.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int maxx, maxy, midx, midy;

void frame()
{
  outtextxy(250, 12, "-: 3D Rotation :-");
  line(0, 0, getmaxx(), 0);
  line(0, 0, 0, getmaxy());
  line(0, getmaxy(), getmaxx(), getmaxy());
  line(getmaxx(), 0, getmaxx(), getmaxy());
  line(0, 30, getmaxx(), 30);
  line(0, 450, getmaxx(), 450);
}

void pause()
{
  outtextxy(10, 460, "Press any key to Continue ...");
  getch();
}

void main()
{
  int gd = DETECT, gm, x, y, z, ang, x1, x2, y1, y2;
  initgraph(&gd, &gm, "C://TURBOC3//BGI");
  setcolor(2);
  setfillstyle(2, 25);
  setcolor(2);
  maxx = getmaxx();
  maxy = getmaxy();
  midx = maxx / 2 + 60;
  midy = maxy / 2 + 50;

  frame();
  printf("\n\n\n Enter Rotation angle : ");
  frame();
  scanf("%d", &ang);
  x1 = 100 * cos(ang * 3.14 / 180) - 20 * sin(ang * 3.14 / 180);
  y1 = 100 * sin(ang * 3.14 / 180) + 20 * sin(ang * 3.14 / 180);
  x2 = 60 * cos(ang * 3.14 / 180) - 90 * sin(ang * 3.14 / 180);
  y2 = 60 * sin(ang * 3.14 / 180) + 90 * sin(ang * 3.14 / 180);
  outtextxy(50, 150, "[ Rotated about Z-axis ]");
  frame();
  outtextxy(450, 150, "[ Original Figure ]");
  bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 1);
  bar3d(midx + x1, midy - y1, midx + x2, midy - y2, 20, 1);
  pause();
  outtextxy(400, 400, "[ Rotated about X-axis ]");
  frame();
  bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 1);
  bar3d(midx + 100, midy - x1, midx + 60, midy - x2, 20, 1);
  pause();
  outtextxy(50, 250, "[ Rotated about Y-axis ]");
  frame();
  bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 1);
  bar3d(midx + x1, midy - 20, midx + x2, midy - 90, 20, 1);
  cleardevice();
  bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 1);
  bar3d(midx + x1, midy - y1, midx + x2, midy - y2, 20, 1);
  bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 1);
  bar3d(midx + 100, midy - x1, midx + 60, midy - x2, 20, 1);
  bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 1);
  bar3d(midx + x1, midy - 20, midx + x2, midy - 90, 20, 1);
  outtextxy(50, 150, "[ Rotated about Z-axis ]");
  outtextxy(450, 150, "[ Original Figure ]");
  outtextxy(400, 400, "[ Rotated about X-axis ]");
  outtextxy(50, 250, "[ Rotated about Y-axis ]");
  frame();
  outtextxy(10, 460, "Press any key to EXIT ...");
  getch();
  closegraph();
}