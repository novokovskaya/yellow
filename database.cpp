#include "database.h"
#include <algorithm>
#include <iostream>
//#include <utility>

using namespace std;

void Database::Add(const Date& date, const string& event) {
	if (Base_set[date].count(event) == 0) {
		Base[date].push_back(event);
		Base_set[date].insert(event);
	}
	//if (!event.empty() && find(Base[date].begin(), Base[date].end(),event)==Base[date].end())
}
void Database::Print(ostream& os) const {
	for (auto& item : Base) {
		for (auto& item1 : item.second) {
			os << item.first << " " << item1 << endl;
		}
	}
}
//int Database::RemoveIf(const function<bool(const Date & date, const string & event)>& predicate) {
//	int count = 0;
//	return count;
//}
pair<Date, string> Database::Last(const Date& date) const {
	auto iter_after = Base.upper_bound(date);
	if (iter_after != Base.begin()) {
		auto it = --iter_after;
		return make_pair(it->first, (it->second).back());
	}
	else throw invalid_argument("");
}

std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::string>& r) {
	os << r.first << " " << r.second;
	return os;
}
