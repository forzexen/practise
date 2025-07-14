#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

char* findSubstringInBrackets(char* str) {
    char* start = strchr(str, '(');
    char* end = strchr(str, ')');

    if (start && end && end > start) {
        *end = '\0';
        return start + 1;
    }

    return nullptr;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char text[] = "Текст до (подстрока) и после.";

    char* result = findSubstringInBrackets(text);

    if (result)
        cout << "Подстрока в скобках: " << result << endl;
    else
        cout << "Подстрока в скобках не найдена." << endl;

    return 0;
}
