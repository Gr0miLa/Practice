#include <iostream>
#include <clocale>
#include <cmath>
#include <string>
#include <windows.h>
#include "TBitField.h"
#include "TSet.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int maxPower;
    cout << "Введите размер универса: ";
    cin >> maxPower;

    TBitField A(maxPower);
    TBitField B(maxPower);
    TBitField C = A;

    int sizeSet;

    cout << "Введите количество элементов в первом множестве: ";
    cin >> sizeSet;

    cout << "Введите элементы множества: " << endl;

    for (int i = 0; i < sizeSet; i++)
    {
        int it;
        cin >> it;

        A.Add(it, maxPower);
    }

    cout << "Множество: " << endl;
    cout << A.TBitFieldToString(maxPower);



    /*cout << "Введите количество элементов во втором множестве: ";
    cin >> sizeSet;

    for (int i = 0; i < sizeSet; i++)
    {
        int it;
        cin >> it;

        B.Add(it, maxPower);
    }*/



    return 0;
}
