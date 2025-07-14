#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    do {
        int N;
        cout << "Введите натуральное число N: ";
        cin >> N;

        bool found = false;
        for (int x = 1; x * x < N; x++) {
            for (int y = 1; y * y < N; y++) {
                if (x * x + y * y == N) {
                    cout << "Найдено: x = " << x << ", y = " << y << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "Нет таких натуральных x и y, чтобы x² + y² = " << N << endl;
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
