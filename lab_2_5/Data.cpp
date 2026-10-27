#include "Data.h"
#include <iostream>

using namespace std;

bool Data::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Data::DaysInMonth(int year, int month)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

Data::Data()
{
    SetYear(2000);
    SetMonth(1);
    SetDay(1); // Виправлено: тепер тут SetDay
}

Data::Data(int year, int month, int day)
{
    triad = Triad(2000, 1, 1);
    if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= DaysInMonth(year, month))
    {
        triad = Triad(year, month, day);
    }
}

Data::Data(const Triad& t)
{
    SetTriad(t);
}

Data::Data(const Data& other)
{
    SetTriad(other.triad);
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        SetTriad(other.triad);
    }
    return *this;
}

void Data::SetTriad(const Triad& t)
{
    if (t.GetSecond() >= 1 && t.GetSecond() <= 12 && t.GetThird() >= 1 && t.GetThird() <= DaysInMonth(t.GetFirst(), t.GetSecond()))
    {
        triad = t;
    }
    else
    {
        triad = Triad(2000, 1, 1);
    }
}

bool Data::SetYear(int y)
{
    int m = triad.GetSecond();
    int d = triad.GetThird();
    if (m < 1 || m > 12) m = 1;
    if (d < 1) d = 1;

    if (y > 0 && d <= DaysInMonth(y, m))
    {
        triad = Triad(y, m, d);
        return true;
    }
    return false;
}

bool Data::SetMonth(int m)
{
    int y = triad.GetFirst();
    int d = triad.GetThird();
    if (y <= 0) y = 2000;
    if (d < 1) d = 1;

    if (m >= 1 && m <= 12 && d <= DaysInMonth(y, m))
    {
        triad = Triad(y, m, d);
        return true;
    }
    return false;
}

bool Data::SetDay(int d)
{
    int y = triad.GetFirst();
    int m = triad.GetSecond();
    if (y <= 0) y = 2000;
    if (m < 1 || m > 12) m = 1;

    if (d >= 1 && d <= DaysInMonth(y, m))
    {
        triad = Triad(y, m, d);
        return true;
    }
    return false;
}

Data::operator std::string() const
{
    int y = triad.GetFirst();
    int m = triad.GetSecond();
    int d = triad.GetThird();

    std::string mStr = (m < 10 ? "0" : "") + std::to_string(m);
    std::string dStr = (d < 10 ? "0" : "") + std::to_string(d);
    return dStr + "." + mStr + "." + std::to_string(y);
}

Data& Data::operator++() // Префіксний інкремент (+1 день)
{
    int d = triad.GetThird() + 1; // Збільшуємо день
    int m = triad.GetSecond();
    int y = triad.GetFirst();

    if (d > DaysInMonth(y, m))
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    triad = Triad(y, m, d);
    return *this;
}

Data Data::operator++(int)
{
    Data temp(*this);
    ++(*this);
    return temp;
}

Data& Data::operator--() // Префіксний декремент (-1 день)
{
    int d = triad.GetThird() - 1; // Зменшуємо день
    int m = triad.GetSecond();
    int y = triad.GetFirst();

    if (d < 1)
    {
        m--;
        if (m < 1)
        {
            m = 12;
            y--;
            if (y < 1) y = 1;
        }
        d = DaysInMonth(y, m);
    }
    triad = Triad(y, m, d);
    return *this;
}

Data Data::operator--(int)
{
    Data temp(*this);
    --(*this);
    return temp;
}

Data& Data::operator+=(int n)
{
    for (int i = 0; i < n; i++)
    {
        ++(*this);
    }
    return *this;
}

Data& Data::operator-=(int n)
{
    for (int i = 0; i < n; i++)
    {
        --(*this);
    }
    return *this;
}

ostream& operator<<(ostream& out, const Data& d)
{
    out << string(d);
    return out;
}


istream& operator>>(istream& in, Data& d)
{
    int y, m, day;
    do
    {
        cout << "Введіть рік: "; in >> y;
        cout << "Введіть місяць: "; in >> m;
        cout << "Введіть день: "; in >> day;

        if (y > 0 && m >= 1 && m <= 12 && day >= 1 && day <= Data::DaysInMonth(y, m))
        {
            d.SetYear(y);
            d.SetMonth(m);
            d.SetDay(day);
            break;
        }
        else
        {
            cout << "Невірна дата. Спробуйте ще раз.\n";
        }
    } while (true);

    return in;
}