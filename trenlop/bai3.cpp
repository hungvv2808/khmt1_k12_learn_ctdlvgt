#include <graphics.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(1); // set backgroud
    int x = 250;
    setcolor(12); //outline heart
    circle(x + 50, 50, 40);
    delay(1000);
    circle(x + 110, 50, 40);
    delay(500);
    line(x + 22, 80, x + 80, 140);
    delay(500);
    line(x + 80, 140, x + 138, 80);
    delay(500);

    floodfill(x + 50, 50, 12); //fill heart
    delay(500);
    floodfill(x + 110, 50, 12);
    delay(500);
    floodfill(x + 80, 50, 12);
    delay(500);
    floodfill(x + 80, 100, 12);
    delay(500);
    setcolor(RED);
    outtextxy(x + 35, 50, "I L O V E U");
    outtextxy(x + 35, 150, "K I N G K O N G");

    cin.get();
    closegraph();
    return 0;
}
