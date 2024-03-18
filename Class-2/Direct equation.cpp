//Drawing line using direct equation
//St id: 194028
#include<graphics.h>
#include<dos.h>
#include<bits/stdc++.h>
using namespace std;


int xp,yp,x,y;
float xf;
float yf;
int dx;
int dy;
float m,b;

void draw1(int x1,int y1,int x2,int y2)
{
    xp=x1;
    yp=y1;
    putpixel(xp,yp,WHITE);
    while(yp<y2)
    {
        yp++;
        xf=(yp-b)/m;
        xp = xf + 0.5;
        putpixel(x+xp,y+yp,WHITE);
    }
}

void draw2(int x1,int y1,int x2,int y2)
{
    xp=x1;
    yp=y1;
    putpixel(xp,yp,WHITE);
    while(xp<x2)
    {
        xp++;
        yf=m*xf+b;
        yp = yf + 0.5;
        putpixel(x+xp,y+yp,WHITE);
    }
}


int main()
{
    //initwindow(1000,600,"First sample");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);

    int X=getmaxx();
    int Y=getmaxy();
    x=X/2;
    y=Y/2;

    line(0,y,X,y);
    line(x,0,x,Y);
    int x1,x2,y1,y2;
    cout<<"Initial point: ";
    cin>>x1>>y1;
    cout<<"End point: ";
    cin>>x2>>y2;

    dx = x2 -x1;
    dy = y2 -y1;
    m=(float) dy/dx;
    b=y1-m*x1;
    if(m>1)
    {
        draw1(x1,y1,x2,y2);
    }
    if(m<=1)
    {
        draw2(x1,y1,x2,y2);
    }

    cleardevice();
    while(!kbhit())
    {
        delay(200);
    }

    closegraph();
    return 0;
}
