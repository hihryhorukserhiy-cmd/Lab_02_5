#pragma once
#include "Triad.h"
#include <string>

class Data
{
private:
    Triad triad;

public:
  
    static bool isLeapYear(int year);
    static int DaysInMonth(int year, int month);

    // Конструктори
    Data();
    Data(int year, int month, int day);
    Data(const Triad& t);
    Data(const Data& other);

    // Гетери та сетери
    Triad GetTriad() const { return triad; }
    void SetTriad(const Triad& t);

    int GetYear() const { return triad.GetFirst(); }
    int GetMonth() const { return triad.GetSecond(); }
    int GetDay() const { return triad.GetThird(); }

    bool SetYear(int y);
    bool SetMonth(int m);
    bool SetDay(int d);

    // Перевантаження операції присвоєння (метод класу)
    Data& operator=(const Data& other);

    // Операція приведення типу до string (метод класу)
    operator std::string() const;

    // Інкремент та декремент дати (методи класу)
    Data& operator++();    // префіксний (+1 день)
    Data operator++(int);  // постфіксний
    Data& operator--();    // префіксний (-1 день)
    Data operator--(int);  // постфіксний

    // Арифметичні операції присвоєння для додавання/віднімання днів
    Data& operator+=(int n);
    Data& operator-=(int n);

    // Дружні функції вводу/виводу потоків
    friend std::ostream& operator<<(std::ostream& out, const Data& d);
    friend std::istream& operator>>(std::istream& in, Data& d);
};