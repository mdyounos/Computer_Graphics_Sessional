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
    int y=Y/2;
//    rectangle(0,0,X,Y);
//    line(x,0,x,Y);
//    line(0,y,X,y);
//    circle(x+100,y-100,50);
//    circle(x-100,y-100,50);
//    circle(x+100,y+100,50);
//    circle(x-100,y+100,50);
    //arc(x+100, y+100, 0, 135, 50);
    //line(x+100,y,x+100,Y);
    //line(x,y+100,X,y+100);
    //bar(x+100, y-100, x+200, y-200);
    int point1[]={100,100,150,200,40,200,100,100};
    drawpoly(4, point1);

    int point2[]={100,100,150,200,300,200,250,100,100,100};
    drawpoly(5, point2);

    int point3[]={40,200,40,350,150,350,150,200,40,200};
    drawpoly(5, point3);

    int point4[]={150,200,150,350,300,350,300,200,40,200};
    drawpoly(5, point4);
    floodfill(141,300,WHITE);
//    line(100,100,150,200);
//    line(150,200,40,200);
//    line(40,200,100,100);
//    bar(100,100,300,200);
    while(!kbhit())
    {
        delay(200);
    }
    return 0;
}
