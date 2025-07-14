#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

string transformLine(const string& line) {
    string result;
    for (char c : line) {
        result += c;
        if (c == ' ') result += '!';
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    ifstream fin("F1.txt");
    ofstream fout("F2.txt");

    string line;
    while (getline(fin, line)) {
        fout << transformLine(line) << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
