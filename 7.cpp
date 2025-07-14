#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int n = 6;
    int веса[n] = {50, 80, 60, 100, 55, 70};
    int проблемный_стул = 2; // 0-based индекс

    int максВес = веса[0];
    for (int i = 1; i < n; ++i)
        if (веса[i] > максВес)
            максВес = веса[i];

    int часы = 0;
    while (true) {
        if (веса[проблемный_стул] == максВес)
            break;

        int последний = веса[n - 1];
        for (int i = n - 1; i > 0; --i)
            веса[i] = веса[i - 1];
        веса[0] = последний;

        часы++;
    }

    cout << "Через " << часы << " часов толстяк с максимальным весом сядет на слабый стул." << endl;
    return 0;
}
