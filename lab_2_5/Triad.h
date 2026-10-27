#pragma once
#include <string>
#include <iostream>

class Triad
{
private:
	int first;
	int second;
	int third;
public:

	Triad();
	Triad(int f, int s, int t);
	Triad(const Triad& other);

	int GetFirst() const { return first; }
	int GetSecond() const { return second; }
	int GetThird() const { return third; }

	void SetFirst(int value) { first = value; }
	void SetSecond(int value) { second = value; }
	void SetThird(int value) { third = value; }

	Triad& operator=(const Triad& other);
	
	operator std::string() const;

	Triad& operator++();
	Triad operator++(int);
	Triad& operator--();
	Triad operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const Triad& t);
	friend std::istream& operator>>(std::istream& in, Triad& t);
	
};

