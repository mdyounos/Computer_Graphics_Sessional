#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int xMin = 100;
const int xMax = 400;
const int yMin = 100;
const int yMax = 400;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xMin)       // to the left of rectangle
        code |= LEFT;
    else if (x > xMax)  // to the right of rectangle
        code |= RIGHT;
    if (y < yMin)       // below the rectangle
        code |= BOTTOM;
    else if (y > yMax)  // above the rectangle
        code |= TOP;

    return code;
}

// Function to clip a line using Cohen-Sutherland algorithm
void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints lie inside the rectangle
            accept = true;
            break;
        }
        else if (code1 & code2) {
            // Both endpoints are outside the rectangle, in the same region
            break;
        }
        else {
            // Some segment of the line lies inside the rectangle
            int codeOut;
            int x, y;

            // Pick an endpoint that is outside the rectangle
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Find intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            // Replace the outside endpoint with the intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the line segment
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;

    // Input coordinates of the line
    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the clipping window
    rectangle(xMin, yMin, xMax, yMax);

    // Draw the original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Clip and draw the line using Cohen-Sutherland algorithm
    cohenSutherland(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
