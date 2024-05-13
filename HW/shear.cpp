#include <iostream>
#include <graphics.h>
using namespace std;

// Function to shear a rectangle
void shearRectangle(int x1, int y1, int x2, int y2, float shearFactor, bool shearX, int& newX1, int& newY1, int& newX2, int& newY2, int& newX3, int& newY3, int& newX4, int& newY4) {
    // Calculate new coordinates after shearing
    if (shearX) {
        newX1 = x1 + shearFactor * y1;
        newY1 = y1;
        newX2 = x2 + shearFactor * y2;
        newY2 = y2;
        newX3 = x2;
        newY3 = y2;
        newX4 = x1;
        newY4 = y1;
    } else {
        newX1 = x1;
        newY1 = y1 + shearFactor * x1;
        newX2 = x2;
        newY2 = y2 + shearFactor * x2;
        newX3 = x2;
        newY3 = y2;
        newX4 = x1;
        newY4 = y1;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    float shearFactor;
    char axis;

    // Input coordinates of the rectangle and shearing factor
    cout << "Enter the coordinates of the rectangle (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the shearing factor: ";
    cin >> shearFactor;
    cout << "Enter the axis of shearing (x or y): ";
    cin >> axis;

    int newX1, newY1, newX2, newY2, newX3, newY3, newX4, newY4;

    // Shear the rectangle
    if (axis == 'x' || axis == 'X') {
        shearRectangle(x1, y1, x2, y2, shearFactor, true, newX1, newY1, newX2, newY2, newX3, newY3, newX4, newY4);
    } else if (axis == 'y' || axis == 'Y') {
        shearRectangle(x1, y1, x2, y2, shearFactor, false, newX1, newY1, newX2, newY2, newX3, newY3, newX4, newY4);
    } else {
        cout << "Invalid axis. Please enter 'x' or 'y'." << endl;
        closegraph();
        return 1;
    }

    // Draw the original rectangle
    rectangle(x1, y1, x2, y2);

    // Draw the sheared rectangle
    setcolor(RED);
    line(newX1, newY1, newX2, newY2);
    line(newX2, newY2, newX3, newY3);
    line(newX3, newY3, newX4, newY4);
    line(newX4, newY4, newX1, newY1);


    getch();
    closegraph();
    return 0;
}
