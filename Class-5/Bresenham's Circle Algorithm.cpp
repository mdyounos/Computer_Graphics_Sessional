#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int x,y;
void drawing(int X,int Y,int h,int k)
{
    int a=x/2,b=y/2;
    putpixel(a+(X+h),b+(Y+k),15);
    putpixel(a+(Y+h),b+(X+k),15);
    putpixel(a+(-Y+h),b+(X+k),15);
    putpixel(a+(-X+h),b+(Y+k),15);

    putpixel(a+(-X+h),b+(-Y+k),15);
    putpixel(a+(-Y+h),b+(-X+k),15);
    putpixel(a+(Y+h),b+(-X+k),15);
    putpixel(a+(X+h),b+(-Y+k),15);
}


int main()
{
    initwindow(800,600,"Screen");
    x=getmaxx();
    y=getmaxy();
    rectangle(0,0,x,y);
    line(0,y/2,x,y/2);
    line(x/2,0,x/2,y);

    int h,k;
    cout<<"Coordinate of center: ";
    cin>>h>>k;
    cout<<"Radius of circle: ";
    int r;
    cin>>r;
    int X=0,Y=r,d=3-2*r;


    while(X<=Y)
    {
        drawing(X,Y,h,k);
        if(d<0)
        {
            d=d+4*X+6;
            X++;
        }
        else
        {
            d=d+4*(X-Y)+10;
            X++;
            Y--;
        }
    }
        while(!kbhit())
        {
            delay(200);
        }
}
