#include <iostream>
#include <graphics.h>
using namespace std;

// Function to reflect a line about the x-axis
void reflectLine(int x1, int y1, int x2, int y2, int& newX1, int& newY1, int& newX2, int& newY2) {
    // Calculate new coordinates after reflection
    newX1 = x1;
    newY1 = -y1;
    newX2 = x2;
    newY2 = -y2;
}

int main()
{
    initwindow(1000,600,"Reflection");

    int x1, y1, x2, y2;

    // Input coordinates of the line
    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    int newX1, newY1, newX2, newY2;

    // Reflect the endpoints of the line
    reflectLine(x1, y1, x2, y2, newX1, newY1, newX2, newY2);

    // Draw the original line
    line(x1, y1, x2, y2);

    // Draw the reflected line
    setcolor(RED);
    line(newX1, newY1, newX2, newY2);
    cout<<newX1<<" "<<newY1<<" "<<newX2<<" "<<newY2<<endl;

    getch();
    closegraph();
    return 0;
}
