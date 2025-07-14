Код:
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <algorithm>
using namespace std;

void processDay(int n, int t, const vector<vector<int>>& harvest, const vector<int>& prices, ofstream& resultFile) {
    vector<double> average(t, 0);
    vector<int> totalEarned(n, 0);

    
    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n; i++) {
            average[j] += harvest[i][j];
        }
        average[j] /= n;
    }

    
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < t; j++) {
            int count = harvest[i][j];
            if (count > average[j]) {
                int over = count - static_cast<int>(average[j]);
                total += static_cast<int>(average[j]) * prices[j] + over * prices[j] * 2;
            } else {
                total += count * prices[j];
            }
        }
        totalEarned[i] = total;
    }

    
    int maxIndex = max_element(totalEarned.begin(), totalEarned.end()) - totalEarned.begin();
    int maxPrice = *max_element(prices.begin(), prices.end());
    totalEarned[maxIndex] += 3 * maxPrice;

    
    resultFile << "Результаты за день:\n";
    for (int i = 0; i < n; i++) {
        resultFile << "Коротышка #" << i + 1 << ": " << totalEarned[i] << " монет\n";
    }
    resultFile << "-------------------------\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n, t;
    cout << "Введите количество коротышек (n): ";
    cin >> n;
    cout << "Введите количество видов овощей (t): ";
    cin >> t;

    vector<vector<int>> harvest(n, vector<int>(t));
    vector<int> prices(t);

    cout << "\nВведите цены за каждый вид овощей:\n";
    for (int j = 0; j < t; j++) {
        cout << "Цена овоща #" << j + 1 << ": ";
        cin >> prices[j];
    }

    cout << "\nВведите количество собранных овощей каждым коротышкой:\n";
    for (int i = 0; i < n; i++) {
        cout << "Коротышка #" << i + 1 << ":\n";
        for (int j = 0; j < t; j++) {
            cout << "  Овощ #" << j + 1 << ": ";
            cin >> harvest[i][j];
        }
    }

    ofstream resultFile("itog.txt", ios::app);
    if (!resultFile) {
        cerr << "Не удалось открыть файл для записи.\n";
        return 1;
    }

    processDay(n, t, harvest, prices, resultFile);
    resultFile.close();

    cout << "\nРезультаты записаны в файл itog.txt\n";

    return 0;
}
