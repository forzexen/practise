#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct Employee {
    string lastName;
    string firstName;
    string middleName;
    string position;
    string phone;
};

void addEmployee(vector<Employee>& employees) {
    Employee emp;
    cout << "Фамилия: ";
    cin >> emp.lastName;
    cout << "Имя: ";
    cin >> emp.firstName;
    cout << "Отчество: ";
    cin >> emp.middleName;
    cout << "Должность: ";
    cin.ignore();
    getline(cin, emp.position);
    cout << "Телефон: ";
    getline(cin, emp.phone);
    employees.push_back(emp);
}

void printEmployee(const Employee& emp) {
    cout << "ФИО: " << emp.lastName << " " << emp.firstName << " " << emp.middleName << endl;
    cout << "Должность: " << emp.position << endl;
    cout << "Телефон: " << emp.phone << endl;
    cout << "----------------------\n";
}

void printAll(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "Список сотрудников пуст.\n";
        return;
    }
    for (const auto& emp : employees) {
        printEmployee(emp);
    }
}

void findByLastName(const vector<Employee>& employees, const string& lastName) {
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.lastName == lastName) {
            printEmployee(emp);
            found = true;
        }
    }
    if (!found)
        cout << "Сотрудники с фамилией " << lastName << " не найдены.\n";
}

void findByPosition(const vector<Employee>& employees, const string& position) {
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.position == position) {
            printEmployee(emp);
            found = true;
        }
    }
    if (!found)
        cout << "Сотрудники с должностью \"" << position << "\" не найдены.\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    vector<Employee> employees;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить сотрудника\n";
        cout << "2. Вывести информацию о всех сотрудниках\n";
        cout << "3. Поиск по фамилии\n";
        cout << "4. Поиск по должности\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                printAll(employees);
                break;
            case 3: {
                string lname;
                cout << "Введите фамилию: ";
                cin >> lname;
                findByLastName(employees, lname);
                break;
            }
            case 4: {
                string pos;
                cout << "Введите должность: ";
                cin.ignore();
                getline(cin, pos);
                findByPosition(employees, pos);
                break;
            }
            case 0:
                cout << "Выход.\n";
                break;
            default:
                cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}
