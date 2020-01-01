#include<stdexcept>
#include<iomanip>
#include<vector>
#include<sstream>
#include"date.h"

using namespace std;

Date::Date(int Y, int M, int D) {
	if (M < 1 || M > 12) {
		throw logic_error("Month value is invalid: " + to_string(M));
	}
	if (D < 1 || D > 31) {
		throw logic_error("Day value is invalid: " + to_string(D));
	}
	year = Y;
	month = M;
	day = D;
}
bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator<=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator>(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator>=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator==(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator!=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
ostream& operator<<(ostream& os, const Date& date) {
	os << setfill('0')
		<< setw(4) << date.GetYear() << '-'
		<< setw(2) << date.GetMonth() << '-'
		<< setw(2) << date.GetDay();
	return os;
}
Date ParseDate(istream& is) {
	string date;
	is >> date;
	istringstream date_stream(date); 
	bool ok = true;

	int year;
	ok = ok && (date_stream >> year);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int month;
	ok = ok && (date_stream >> month);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int day;
	ok = ok && (date_stream >> day);
	ok = ok && date_stream.eof();
	
	if (!ok) {
		throw logic_error("Wrong date format: " + date);
	}
	return Date(year, month, day);
}