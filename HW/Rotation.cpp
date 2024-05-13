#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

// Function to rotate a point (x, y) around a pivot point (pivotX, pivotY) by angle theta
void rotatePoint(int x, int y, int pivotX, int pivotY, float theta, int& newX, int& newY) {
    // Convert angle from degrees to radians
    float rad = theta * M_PI / 180.0;

    // (pivotX,pivotY)=(0,0) if rotation point is center
    newX = pivotX + (x - pivotX) * cos(rad) - (y - pivotY) * sin(rad);
    newY = pivotY + (x - pivotX) * sin(rad) + (y - pivotY) * cos(rad);
}

int main()
{

    initwindow(1000,600,"Rotation");

    int x1, y1, x2, y2;
    float angle;
    int pivotX, pivotY;

    // Input coordinates of the line and pivot point
    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the angle of rotation (in degrees): ";
    cin >> angle;
    cout << "Enter the coordinates of the pivot point (pivotX pivotY): ";
    cin >> pivotX >> pivotY;

    int newX1, newY1, newX2, newY2;

    // Rotate the endpoints of the line around the pivot point
    rotatePoint(x1, y1, pivotX, pivotY, angle, newX1, newY1);
    rotatePoint(x2, y2, pivotX, pivotY, angle, newX2, newY2);

    // Draw the original line
    line(x1, y1, x2, y2);

    // Draw the rotated line
    setcolor(RED);
    line(newX1, newY1, newX2, newY2);

    getch();
    closegraph();
    return 0;
}
