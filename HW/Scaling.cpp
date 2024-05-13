#include <iostream>
#include <graphics.h>
using namespace std;

// Function to scale a line
void scaleLine(int x1, int y1, int x2, int y2, float scaleFactor, int& newX1, int& newY1, int& newX2, int& newY2) {
    // Calculate new coordinates after scaling
    newX1 = x1 * scaleFactor;
    newY1 = y1 * scaleFactor;
    newX2 = x2 * scaleFactor;
    newY2 = y2 * scaleFactor;
}

int main()
{
    initwindow(1000,600,"Scaling");

    int x1, y1, x2, y2;
    float scaleFactor;

    // Input coordinates of the line and scaling factor
    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the scaling factor: ";
    cin >> scaleFactor;

    int newX1, newY1, newX2, newY2;

    // Scale the endpoints of the line
    scaleLine(x1, y1, x2, y2, scaleFactor, newX1, newY1, newX2, newY2);

    // Draw the original line
    line(x1, y1, x2, y2);

    // Draw the scaled line
    setcolor(RED);
    line(newX1, newY1, newX2, newY2);

    getch();
    closegraph();
    return 0;
}
