#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    do {
        double k, b;
        cout << "Введите коэффициенты k и b для прямой y = kx + b:\n";
        cout << "k = ";
        cin >> k;
        cout << "b = ";
        cin >> b;

        double distance = abs(b) / sqrt(k * k + 1);

        cout << "Расстояние от начала координат до прямой: " << distance << endl;

        if (distance < 1) {
            cout << "Прямая пересекает окружность.\n";
        } else if (distance == 1) {
            cout << "Прямая касается окружности.\n";
        } else {
            cout << "Прямая не пересекает и не касается окружности.\n";
        }

        cout << "\nХотите попробовать снова?\n";
        cout << "1 - Да\n2 - Нет\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                break;
            case 2:
                cout << "Завершение программы.\n";
                break;
            default:
                cout << "Неверный ввод. Завершение.\n";
                choice = 2;
        }

    } while (choice == 1);

    return 0;
}
