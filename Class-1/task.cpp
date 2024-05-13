//introduction to graphics library function and graphics ide
//student id: 194028

#include<graphics.h>
#include <stdio.h>
#include<dos.h>
//getmaxx()
//getmaxy()
int main()
{
    initwindow(1000, 600, "First Sample");
    int X=getmaxx();
    int Y=getmaxy();
    int x=X/2;
    int y=220;
    rectangle(0,0,X,Y);
    line(x,0,x,Y);
    line(0,y,X,y);
    circle(x+100,y-100,50);
    arc(x+100, y+100, 0, 135, 50);
    line(x+100,y+5,x+100,y+100);
    line(x+100,y+100,x+200,y+100);
    bar(x-100, y-100, x-200, y-200);
    line(100,100,150,200);
    line(150,200,40,200);
    line(40,200,100,100);

    int point1[]={x-100,y+100,x-150,y+200,x-40,y+200,x-100,y+100};
    drawpoly(4, point1);

    int point2[]={x-100,y+100,x-150,y+200,x-300,y+200,x-250,y+100,x-100,y+100};
    drawpoly(5, point2);

    int point3[]={x-40,y+200,x-40,y+350,x-150,y+350,x-150,y+200,x-40,y+200};
    drawpoly(5, point3);

    int point4[]={x-150,y+200,x-150,y+350,x-300,y+350,x-300,y+200,x-40,y+200};
    drawpoly(5, point4);
    floodfill(x-141,y+300,WHITE);


//    setcolor(RED);
//    circle(100,100,50);
//    floodfill(100,100,WHITE);


    while(!kbhit())
    {
        delay(200);
    }
    return 0;
}
