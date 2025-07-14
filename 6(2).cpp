#include <iostream>
#include <windows.h>
using namespace std;

void ВводКоординат(float x[], float y[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Точка #" << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
}

void ВыводКоординат(const float x[], const float y[], int n) {
    cout << "Оставшиеся точки:\n";
    for (int i = 0; i < n; ++i)
        cout << "(" << x[i] << ", " << y[i] << ")\n";
}

int УдалитьВнеПолосы(float x[], float y[], int n) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (y[i] >= -1 && y[i] <= 1) {
            x[k] = x[i];
            y[k] = y[i];
            ++k;
        }
    }
    return k;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    cout << "Введите количество точек: ";
    cin >> n;

    float* x = new float[n];
    float* y = new float[n];

    ВводКоординат(x, y, n);
    n = УдалитьВнеПолосы(x, y, n);
    ВыводКоординат(x, y, n);

    delete[] x;
    delete[] y;
    return 0;
}
