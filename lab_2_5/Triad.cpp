#include "Triad.h"

Triad::Triad()
{
	SetFirst(0);
	SetSecond(0);
	SetThird(0);
}

Triad::Triad(int f, int s, int t)
{
	SetFirst(f);
	SetSecond(s);
	SetThird(t);
}

Triad::Triad(const Triad& other)
{
	SetFirst(other.first);
	SetSecond(other.second);
	SetThird(other.third);
}

Triad& Triad::operator=(const Triad& other)
{
	if (this != &other)
	{
		SetFirst(other.first);
		SetSecond(other.second);
		SetThird(other.third);
	}
	return *this;
}

Triad::operator std::string() const
{
	return "(" + std::to_string(first) + ", " + std::to_string(second) + ", " + std::to_string(third) + ")";
}

Triad& Triad::operator++()
{
	SetFirst(first + 1);
	SetSecond(second + 1);
	SetThird(third + 1);
	return *this;
}

Triad Triad::operator++(int)
{
	Triad temp(*this);
	++(*this);
	return temp;
}

Triad& Triad::operator--()
{
	SetFirst(first - 1);
	SetSecond(second - 1);
	SetThird(third - 1);
	return *this;
}

Triad Triad::operator--(int)
{
	Triad temp(*this);
	--(*this);
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Triad& t)
{
	out << std::string(t);
	return out;
}

std::istream& operator>>(std::istream& in, Triad& t)
{
	int f, s, th;
	std::cout << "¬вед≥ть перше число: ";
	in >> f;
	std::cout << "¬вед≥ть друге число: ";
	in >> s;
	std::cout << "¬вед≥ть третЇ число: ";
	in >> th;
	t.SetFirst(f);
	t.SetSecond(s);
	t.SetThird(th);
	return in;
}
