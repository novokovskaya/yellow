#pragma once

#include <ostream>
#include <string>

class Date {
public:
	Date(int Y, int M, int D);
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }
private:
	int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& r);

Date ParseDate(std::istream& date);
