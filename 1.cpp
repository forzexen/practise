#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int number;
    cout << "Введите четырёхзначное число: ";
    cin >> number;

    int d1 = number / 1000;
    int d2 = (number / 100) % 10;
    int d3 = (number / 10) % 10;
    int d4 = number % 10;

    int sum = d1 + d2 + d3 + d4;
    cout << "Сумма цифр: " << sum << endl;

    return 0;
}
