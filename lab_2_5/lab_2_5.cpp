#include <iostream>
#include <Windows.h>
#include "Triad.h"
#include "Data.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "1. Розмір класів (з #pragma pack(1) та без нього)\n";
	cout << "Розмір Triad (звичайний): " << sizeof(Triad) << " байт\n";
	cout << "Розмір Data (звичайний): " << sizeof(Data) << " байт\n";

#pragma pack(push, 1)
	class TriadPacked { int f, s, t; };
	class DataPacked { TriadPacked t; };
	cout << "Розмір Triad з #pragma pack(1): " << sizeof(TriadPacked) << " байт\n";
	cout << "Розмір Data з #pragma pack(1): " << sizeof(DataPacked) << " байт\n";
#pragma pack(pop)
	cout << "(Оскільки поля класів складаються лише з цілих чисел (int), вирівнювання не додає паддінгу).\n\n";

	cout << "2. Перевірка класу Triad та операцій" << endl;
	Triad t1;
	Triad t2(1, 2, 3);
	Triad t3 = t2;

	cout << "t1: " << t1 << endl;
	cout << "t2: " << t2 << endl;
	cout << "t3 (копія t2): " << t3 << endl;

	t1 = t2;
	cout << "t1 після присвоєння t1 = t2: " << t1 << endl;

	cout << "Префіксний інкремент (++t2): " << ++t2 << endl;
	cout << "Постфіксний інкремент (t2++): " << t2++ << endl;
	cout << "Після постфіксу t2: " << t2 << endl;

	cout << "Префіксний декремент (--t2): " << --t2 << endl;
	cout << "Постфіксний декремент (t2--): " << t2-- << endl;
	cout << "Після постфіксу t2: " << t2 << endl << endl;

	cout << "3. Перевірка класу Data та Календарних операцій" << endl;
    Data d1; // Конструктор за замовчуванням
    Data d2(2024, 2, 28); // Високосний рік
    Data d3 = d2; // Конструктор копіювання

    cout << "d1 (за замовчуванням): " << d1 << endl;
    cout << "d2 (ініціалізація): " << d2 << endl;
    cout << "d3 (копія d2): " << d3 << endl;

    cout << "Префіксний інкремент дня (++d2 - 29 лютого): " << ++d2 << endl;
    ++d2;
    cout << "Ще один інкремент (++d2 - 1 березня): " << d2 << endl;

    d2 += 30;
    cout << "Після d2 += 30 днів: " << d2 << endl;

    d2 -= 30;
    cout << "Після d2 -= 30 днів: " << d2 << endl << endl;

    cout << "4. СТВОРЕННЯ ОБ'ЄКТІВ ТА МАСИВІВ (СТАТИЧНІ ТА ДИНАМІЧНІ)" << endl;
    // Динамічний об'єкт через вказівник
    Data* ptrData = new Data(2023, 12, 31);
    cout << "Дата через вказівник: " << *ptrData << endl;
    cout << "Перехід на новий рік (++(*ptrData)): " << ++(*ptrData) << endl;
    delete ptrData;

    // Динамічний масив об'єктів (використовує конструктор за замовчуванням, а потім присвоєння)
    int n = 3;
    Data* arr = new Data[n];
    arr[0] = Data(2025, 1, 15);
    arr[1] = Data(2025, 6, 20);
    arr[2] = Data(2025, 9, 1);

    cout << "Динамічний масив об'єктів Data:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    delete[] arr;
    cout << endl;

    cout << "5. ІНТЕРАКТИВНЕ ВВЕДЕННЯ ТА ВИВІД (operator>> / operator<<) " << endl;
    Data userDate;
    cin >> userDate;
    cout << "Ви ввели дату: " << userDate << endl;

    int daysToAdd;
    cout << "Скільки днів додати до дати? ";
    cin >> daysToAdd;
    userDate += daysToAdd;
    cout << "Оновлена дата: " << userDate << endl;

    return 0;


	
}