//Line drawing using DDA algorithm
#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
#include<dos.h>


int xp,yp,x,y;
float xf;
float yf;
int dx;
int dy;
float m,minv,b;

void draw1(int x1,int y1,int x2,int y2)
{
    xp=x1;
    yp=y1;
    putpixel(x+xp,y+yp,4);
    while(yp<y2)
    {
        yp++;
        xf= xf+minv;
        xp = xf + 0.5;
        putpixel(x+xp,y+yp,4);
    }
}

void draw2(int x1,int y1,int x2,int y2)
{
    xp=x1;
    yp=y1;
    putpixel(x+xp,y+yp,1);
    while(xp<x2)
    {
        xp++;
        yf= yf+m;
        yp = yf + 0.5;
        putpixel(x+xp,y+yp,1);
    }
}


int main()
{
    initwindow(1000,600,"First sample");
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
    dx=x2-x1;
    dy=y2-y1;

    m=(float)dy/dx;
    minv=(float)dx/dy;
    if(m<=1)
    {
        draw2(x1,y1,x2,y2);
    }
    if(m>1)
    {
        draw1(x1,y1,x2,y2);
    }



    while(!kbhit())
    {
        delay(200);
    }
    return 0;
}

