#pragma once
#include "date.h"

#include <memory>

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	And,
	Or,
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
	EmptyNode() {}
	bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date){}
	bool Evaluate(const Date& date, const std::string& event) const override;
private:
	const Comparison cmp_;
	const Date date_;
}; 

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const std::string& event) : cmp_(cmp), event_(event){}
	bool Evaluate(const Date& date, const std::string& event) const override;
private:
	const Comparison cmp_;
	const std::string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& lo, const std::shared_ptr<Node> left, const std::shared_ptr<Node> no_left)
		: lo_(lo), left_(left), no_left_(no_left) {}
	bool Evaluate(const Date& date, const std::string& event) const override;
private:
	const LogicalOperation lo_;
	const std::shared_ptr<const Node> left_;
	const std::shared_ptr<const Node> no_left_;
};