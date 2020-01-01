#pragma once
#include "date.h"
#include <string>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
//#include <functional>

class Database {
public:
	void Add(const Date& date, const std::string& event);
	std::pair<Date, std::string> Last(const Date& date) const;
	void Print(std::ostream& os) const;
	//int RemoveIf(const std::function<bool(const Date &, const std::string &)>&);
	template <class Func>
	int RemoveIf(Func predicate) {
		int count = 0;
		for (auto & item : Base) {
			auto border = std::stable_partition(item.second.begin(), item.second.end(),
				[=](const std::string& event) {return !predicate(item.first, event); });
			count += item.second.end() - border;
			if (border != item.second.end()) {
				item.second.erase(border, item.second.end());
				Base_set[item.first].clear();
				Base_set[item.first].insert(item.second.begin(), item.second.end());
			}
		}
		for (auto it = Base.begin(); it != Base.end();) {
			if (it->second.empty()) {
				Base.erase(it++);
			}
			else { ++it; }
		}
		
		return count;
	}
	template <class Func>
	std::vector<std::pair<Date, std::string>> FindIf(Func predicate) const {
		std::vector<std::pair<Date, std::string>> result;
		for (auto & item : Base) {
			std::vector<std::string> events;
			copy_if(item.second.begin(), item.second.end(), back_inserter(events), 
				[=](const std::string& event) {return predicate(item.first, event); });
			for (auto item1 : events) {
				result.push_back(make_pair(item.first, item1));
			}
		}
		
		return result;
	}
private:
	std::map<Date, std::vector<std::string>> Base;
	std::map<Date, std::set<std::string>> Base_set;
};

std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::string>&);

//std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::vector<std::string>>&);