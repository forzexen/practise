#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double R(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double x, y, side;
    cin >> x >> y >> side;

    double x1 = x,         y1 = y;
    double x2 = x + side,  y2 = y;
    double x3 = x,         y3 = y - side;
    double x4 = x + side,  y4 = y - side;

    cout << R(0, 0, x1, y1) << endl;
    cout << R(0, 0, x2, y2) << endl;
    cout << R(0, 0, x3, y3) << endl;
    cout << R(0, 0, x4, y4) << endl;

    return 0;
}
