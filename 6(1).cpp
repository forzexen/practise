#include <iostream>
#include <windows.h>

using namespace std;

int countBeforeNegative(const int arr[], int size) {
    int count = 0;
    while (count < size && arr[count] >= 0) count++;
    return count;
}

int sumAfterNegative(const int arr[], int size) {
    int i = 0;
    while (i < size && arr[i] >= 0) i++;
    int sum = 0;
    for (int j = i + 1; j < size; j++) sum += arr[j];
    return sum;
}

void processArray(const int arr[], int size) {
    int count = countBeforeNegative(arr, size);
    int sum = sumAfterNegative(arr, size);
    cout << "Количество до первого отрицательного: " << count << endl;
    cout << "Сумма после первого отрицательного: " << sum << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const int size = 10;
    int arr[size] = {3, 7, 1, 0, -5, 2, 4, -1, 6, 8};

    processArray(arr, size);

    return 0;
}
