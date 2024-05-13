#include <bits/stdc++.h>
using namespace std;

// Function to perform translation
void translateLine(int x1, int y1, int x2, int y2, int tx, int ty) {
    // Translate the coordinates
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;

    // Display the translated line
    cout << "Translated line: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
}

int main()
{
    int x1, y1, x2, y2, tx, ty;

    // Input coordinates of the line and translation factors
    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the translation factors (tx ty): ";
    cin >> tx >> ty;

    // Call the translation function
    translateLine(x1, y1, x2, y2, tx, ty);

    return 0;
}
