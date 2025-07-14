#include <iostream>
#include <windows.h> // Для SetConsoleOutputCP
using namespace std;

const int N = 3;
const int M = 5;

int findMinIndex(int row[], int m) {
    int minIdx = 0;
    for (int j = 1; j < m; ++j)
        if (row[j] < row[minIdx])
            minIdx = j;
    return minIdx;
}

int findMaxIndex(int row[], int m) {
    int maxIdx = 0;
    for (int j = 1; j < m; ++j)
        if (row[j] > row[maxIdx])
            maxIdx = j;
    return maxIdx;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printMatrix(int matrix[N][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для отображения русского языка в консоли

    int matrix[N][M] = {
        {7, 2, 9, 4, 6},
        {3, 8, 1, 5, 0},
        {9, 6, 4, 3, 7}
    };

    cout << "Исходная матрица:\n";
    printMatrix(matrix);

    for (int i = 0; i < N; ++i) {
        int minIdx = findMinIndex(matrix[i], M);
        swap(matrix[i][0], matrix[i][minIdx]);

        int maxIdx = findMaxIndex(matrix[i], M);
        swap(matrix[i][M - 1], matrix[i][maxIdx]);
    }

    cout << "\nПреобразованная матрица:\n";
    printMatrix(matrix);

    return 0;
}
