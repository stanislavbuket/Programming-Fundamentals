/**
 * Done by:
 * Student Name: Stanislav Buket
 * Vatiant: 4
 * Student Group: 121
 * Lab 1.5
 */

#include <iostream>

using namespace std;

class Lab1_5 {
public:
    // Конструктор
    Lab1_5() {
        part1();
        part2();
    }

private:
    // Частина 1
    void part1() {
        // Набір 1
        int A1 = 66;
        double B1 = 12.9;
        int C1 = 62;
        int D1 = 59;

        // Обчислення виразу для набору 1
        bool result1 = !(!(A1 != B1) && (C1 < D1));
        cout << "Результат для набору 1: " << boolalpha << result1 << endl;

        // Набір 2
        double A2 = 3.56;
        double B2 = 89.45;
        int C2 = 15;
        double D2 = 56.2;

        // Обчислення виразу для набору 2
        bool result2 = !(!(A2 != B2) && (C2 < D2));
        cout << "Результат для набору 2: " << boolalpha << result2 << endl;
    }

    // Частина 2
    void part2() {
        // Значення змінних для варіанту 4
        int A = 593;
        int B = -145;
        float C = 9.23;
        int D = 43;
        int E = 891;
        short F = sizeof(short);

        // Вираз з використанням операцій, заданих у таблицях
        int L_result = (((A ^ (B >> 1)) / C) * (-D) * sizeof(E)) < F;

        cout << "Результат обчислення для Частини 2: " << L_result << endl;
    }
};

int main() {
    // Створення об'єкта класу для виконання обох частин
    Lab1_5 lab;
    return 0;
}
