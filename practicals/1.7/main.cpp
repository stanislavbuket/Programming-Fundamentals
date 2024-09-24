/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Practice 1.7
 */

#include <iostream>
using namespace std;

// Глобальні змінні та статичні змінні поза блоком main
static int globalStaticVar = 0;
int globalVar = 100;

void testMemory() {
    static int staticVar = 0;  // Статична змінна
    int dynamicVar = 0;        // Динамічна змінна (стекова пам'ять)
    staticVar++;
    dynamicVar++;

    cout << "Inside function testMemory - Static variable: " << staticVar << ", Dynamic variable: " << dynamicVar << endl;
}

int main() {
    // Основний блок main
    cout << "Global Static Variable: " << globalStaticVar << endl;
    cout << "Global Variable: " << globalVar << endl;

    // Вкладений блок 1
    {
        int block1Var = 10;
        cout << "Inside block 1 - block1Var: " << block1Var << endl;

        // Вкладений блок 2 всередині блок 1
        {
            static int block2StaticVar = 20;  // Статична змінна у вкладеному блоці
            int block2Var = 30;               // Динамічна змінна у вкладеному блоці
            block2StaticVar++;
            block2Var++;
            cout << "Inside block 2 - Static block2StaticVar: " << block2StaticVar << ", Dynamic block2Var: " << block2Var << endl;

            // Тестування мембранного ефекту
            int globalVar = 50;  // Локальна змінна з тим самим іменем
            cout << "Inside block 2 - Local globalVar: " << globalVar << endl;
            cout << "Inside block 2 - Original globalVar (using ::): " << ::globalVar << endl;  // Доступ до глобальної змінної через ::
        }
    }

    // Виклик функції для тестування статичних і динамічних змінних
    for (int i = 0; i < 3; i++) {
        testMemory();  // Вхід у функцію кілька разів для демонстрації накопичення значення статичної змінної
    }

    // Динамічна пам'ять у "кучі"
    int* pA = new int;  // Виділення пам'яті у купі
    *pA = 25;
    cout << "Value stored in heap: " << *pA << endl;
    delete pA;  // Звільнення пам'яті

    // Демонстрація неправильної роботи з вказівниками ("сміття")
    int* pB = new int(10);
    int* pC = new int(20);
    pB = pC;  // Втрата вказівника на пам'ять, яка містила значення 10 (утворення "сміття")
    delete pC;  // Звільнення пам'яті
    // Тут pB тепер вказує на ту ж пам'ять, що й pC, але та пам'ять звільнена

    return 0;
}
