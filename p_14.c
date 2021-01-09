//Author : Deepansh Dubey.
//Purpose: Write a program to implement Mid-point line clipping algorithm.
//Date   : 05/01/2021.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

typedef struct coordinate
{
  int x, y;
  char code[4];
} PT;

void view_win()
{
  outtextxy(150, 12, "-: Mid - Point Line Clipping Algorithm :-");
  line(0, 0, getmaxx(), 0);
  line(0, 0, 0, getmaxy());
  line(0, getmaxy(), getmaxx(), getmaxy());
  line(getmaxx(), 0, getmaxx(), getmaxy());
  line(0, 30, getmaxx(), 30);
  line(0, 450, getmaxx(), 450);
}

void draw_window()
{
  line(150, 100, 450, 100);
  line(450, 100, 450, 400);
  line(450, 400, 150, 400);
  line(150, 400, 150, 100);
}

void drawline(PT p1, PT p2, int cl)
{
  setcolor(cl);
  line(p1.x, p1.y, p2.x, p2.y);
}

void pause()
{
  outtextxy(10, 460, "Press any key to Continue ...");
  getch();
}

PT setcode(PT p)
{
  PT ptemp;
  if (p.y <= 100)
    ptemp.code[0] = '1';
  else
    ptemp.code[0] = '0';
  if (p.y >= 400)
    ptemp.code[1] = '1';
  else
    ptemp.code[1] = '0';
  if (p.x >= 450)
    ptemp.code[2] = '1';
  else
    ptemp.code[2] = '0';
  if (p.x <= 150)
    ptemp.code[3] = '1';
  else
    ptemp.code[3] = '0';
  ptemp.x = p.x;
  ptemp.y = p.y;
  return (ptemp);
}

int visibility(PT p1, PT p2)
{
  int i, flag = 0;
  for (i = 0; i < 4; i++)
  {
    if ((p1.code[i] != '0') || (p2.code[i] != '0'))
      flag = 1;
  }
  if (flag == 0)
    return (0);
  for (i = 0; i < 4; i++)
  {
    if ((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
      flag = 0;
  }
  if (flag == 0)
    return (1);
  return (2);
}

void midsub(PT p1, PT p2)
{
  PT mid;
  int v;
  p1 = setcode(p1);
  p2 = setcode(p2);
  v = visibility(p1, p2);
  switch (v)
  {
  case 0:
    drawline(p1, p2, 1);
    break;
  case 1:
    break;
  case 2:
    mid.x = p1.x + (p2.x - p1.x) / 2;
    mid.y = p1.y + (p2.y - p1.y) / 2;
    midsub(p1, mid);
    mid.x = mid.x + 1;
    mid.y = mid.y + 1;
    midsub(mid, p2);
    break;
  }
}

PT resetendpt(PT p1, PT p2);

void main()
{
  int gd = DETECT, gm, v;
  PT p1, p2, ptemp;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI ");
  setcolor(2);
  view_win();
  printf("\n\n\n\tEnter x1 : ");
  scanf("%d", &p1.x);
  view_win();
  printf("\tEnter y1 : ");
  scanf("%d", &p1.y);
  view_win();
  printf("\tEnter x2: ");
  view_win();
  scanf("%d", &p2.x);
  printf("\tEnter y2 : ");
  scanf("%d", &p2.y);
  view_win();
  pause();
  cleardevice();
  view_win();
  draw_window();
  pause();
  setcolor(1);
  drawline(p1, p2, 15);
  pause();
  cleardevice();
  view_win();
  draw_window();
  midsub(p1, p2);
  outtextxy(10, 460, "Press any key to Continue ...");
  getch();
  closegraph();
}