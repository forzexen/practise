#include <iostream>
#include <windows.h>
#include <iomanip> 

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double N;
    const double MARATHON = 42.195;
    int day = 1;
    double total = 0;

    cout << "Введите начальную дистанцию (в км): ";
    cin >> N;

    cout << fixed << setprecision(3);
    cout << "\nДень\tПробег (км)\n";
    cout << "---------------------\n";

    while (total < MARATHON) {
        cout << day << "\t" << N << "\n";
        total += N;
        N *= 1.2;
        day++;
    }

    cout << "\nСпортсмен пробежит марафонскую дистанцию за " << day - 1 << " дней.\n";
    return 0;
}
