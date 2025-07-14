#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

void СлучайныйМассив(int* arr, int size, int min, int max) {
    for (int i = 0; i < size; ++i)
        *(arr + i) = min + rand() % (max - min + 1);
}

int* ПослеПервогоОтрицательного(int* arr, int size, int& newSize) {
    int* p = arr;
    while (p < arr + size && *p >= 0)
        ++p;
    ++p;
    newSize = arr + size - p;
    int* newArr = new int[newSize];
    for (int i = 0; i < newSize; ++i)
        *(newArr + i) = *(p + i);
    return newArr;
}

void Печать(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << *(arr + i) << " ";
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];
    СлучайныйМассив(a, n, -10, 10);
    cout << "Исходный массив:\n";
    Печать(a, n);

    int newSize;
    int* b = ПослеПервогоОтрицательного(a, n, newSize);

    cout << "Новый массив:\n";
    Печать(b, newSize);

    delete[] a;
    delete[] b;
    return 0;
}
