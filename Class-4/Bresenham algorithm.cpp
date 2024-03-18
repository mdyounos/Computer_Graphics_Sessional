//st id: 194028
//report_title: implementation bresenham line drawing algorithm
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int xc,yc,dx,dy;
void bresenham1(int x1,int y1,int x2,int y2)
{
    int x,y,endx;
    int d = 2*dy-dx;
    int incr = 2*dy;
    int incr2 = 2*(dy-dx);
    if(dx<0)
    {
        x = x2;
        y = y2;
        endx = x1;
    }
    else
    {
        x = x1;
        y = y1;
        endx = x2;
    }

    putpixel((xc)+x,(yc)+y,WHITE);
    while(x<endx)
    {
        if(d<0)
        {
            d+=incr;
            x++;
        }
        else
        {
            d+=incr2;
            x++;
            y++;
        }
        putpixel((xc)+x,(yc)+y,WHITE);
    }
}
void bresenham2(int x1,int y1,int x2,int y2)
{
    int x,y,endx;
    int d = 2*dx-dy;
    int incr = 2*dx;
    int incr2 = 2*(dx-dy);
    if(dx<0)
    {
        x = x2;
        y = y2;
        endx = x1;
    }
    else
    {
        x = x1;
        y = y1;
        endx = x2;
    }

    putpixel((xc)+x,(yc)+y,WHITE);
    while(x<endx)
    {
        if(d<0)
        {
            d+=incr;
            x++;
        }
        else
        {
            d+=incr2;
            x++;
            y++;
        }
        putpixel((xc)+x,(yc)+y,WHITE);
    }
}

int main()
{
    initwindow(600,500);
    int a = getmaxx();
    int b = getmaxy();
    xc=a/2,yc=b/2;
    rectangle(0,0,a,b);
    line(xc,0,xc,b);
    line(0,yc,a,yc);

    int x1,y1,x2,y2;
    cout<<"Initial Point: ";
    cin>>x1>>y1;
    cout<<"End Point: ";
    cin>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    float m=float(dy)/(dx);

    if(m>1)
        bresenham1(x1,y1,x2,y2);
    else
        bresenham2(x1,y1,x2,y2);

    while(!kbhit())
    {
        delay(200);
    }
    return 0;
}
