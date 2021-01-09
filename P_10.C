//Author : Deepansh Dubey.
//Purpose: Write a program to perform 2D Shearing on line and square.
//Date   : 05/01/2021.

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int factor;

void frame()
{
  outtextxy(265, 12, "-: Shearing :-");
  line(0, 0, getmaxx(), 0);
  line(0, 0, 0, getmaxy());
  line(0, getmaxy(), getmaxx(), getmaxy());
  line(getmaxx(), 0, getmaxx(), getmaxy());
  line(0, 30, getmaxx(), 30);
  line(0, 440, getmaxx(), 440);
}

void pause()
{
  outtextxy(10, 450, "Press any key to Continue ...");
  getch();
}

void shearsqx(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  x1 = x1 + y1 * factor;
  x2 = x2 + y2 * factor;
  x3 = x3 + y3 * factor;
  x4 = x4 + y4 * factor;
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x4, y4);
  line(x4, y4, x1, y1);
}

void shearsqy(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  y1 = y1 + x1 * factor;
  y2 = y2 + x2 * factor;
  y3 = y3 + x3 * factor;
  y4 = y4 + x4 * factor;
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x4, y4);
  line(x4, y4, x1, y1);
}

void shearsqxy(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  int a1 = x1, a2 = x2, a3 = x3, a4 = x4;
  x1 = x1 + y1 * factor;
  x2 = x2 + y2 * factor;
  x3 = x3 + y3 * factor;
  x4 = x4 + y4 * factor;
  y1 = y1 + a1 * factor;
  y2 = y2 + a2 * factor;
  y3 = y3 + a3 * factor;
  y4 = y4 + a4 * factor;
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x4, y4);
  line(x4, y4, x1, y1);
}

void shearlnx(int x1, int y1, int x2, int y2)
{
  x1 = x1 + y1 * factor;
  x2 = x2 + y2 * factor;
  line(x1, y1, x2, y2);
}

void shearlny(int x1, int y1, int x2, int y2)
{
  y1 = y1 + x1 * factor;
  y2 = y2 + x2 * factor;
  line(x1, y1, x2, y2);
}

void shearlnxy(int x1, int y1, int x2, int y2)
{
  int a1 = x1, a2 = x2;
  x1 = x1 + y1 * factor;
  x2 = x2 + y2 * factor;
  y1 = y1 + a1 * factor;
  y2 = y2 + a2 * factor;
  line(x1, y1, x2, y2);
}

void shearsquare()
{
  int x1, y1, x2, y2, x3, y3, x4, y4;
  frame();
  printf("\n\n\n Enter x1 y1 : ");
  scanf("%d %d", &x1, &y1);
  printf("\n Enter x2 y2 : ");
  scanf("%d %d", &x2, &y2);
  printf("\n Enter x3 y3 : ");
  scanf("%d %d", &x3, &y3);
  printf("\n Enter x4 y4 : ");
  scanf("%d %d", &x4, &y4);
  printf("\n Enter Shearing Factor : ");
  scanf("%d", &factor);
  cleardevice();
  frame();
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x4, y4);
  line(x4, y4, x1, y1);
  setcolor(RED);
  shearsqx(x1, y1, x2, y2, x3, y3, x4, y4);
  shearsqy(x1, y1, x2, y2, x3, y3, x4, y4);
  shearsqxy(x1, y1, x2, y2, x3, y3, x4, y4);
  setcolor(15);
}

void shearline()
{
  int x1, y1, x2, y2;
  frame();
  printf("\n\n\n Enter x1 y1 : ");
  scanf("%d %d", &x1, &y1);
  printf("\n Enter x2 y2 : ");
  scanf("%d %d", &x2, &y2);
  printf("\n Enter Shearing Factor : ");
  scanf("%d", &factor);
  cleardevice();
  frame();
  line(x1, y1, x2, y2);
  setcolor(RED);
  shearlnx(x1, y1, x2, y2);
  shearlny(x1, y1, x2, y2);
  shearlnxy(x1, y1, x2, y2);
  setcolor(15);
}

void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  setcolor(2);
  shearline();
  outtextxy(400, 50, "(Sheared on X-axis)");
  outtextxy(20, 420, "(Sheared on Y-axis)");
  outtextxy(400, 420, "(Sheared on both X & Y axis)");
  pause();
  cleardevice();
  clrscr();
  setcolor(2);
  shearsquare();
  outtextxy(400, 50, "(Sheared on X-axis)");
  outtextxy(20, 420, "(Sheared on Y-axis)");
  outtextxy(400, 420, "(Sheared on both X & Y axis)");
  outtextxy(10, 450, "Press any key to Exit ...");
  getch();
  closegraph();
}