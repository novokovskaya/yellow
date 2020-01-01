#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const{
	switch (cmp_) {
	case Comparison::Less:
		return date < date_;
	case Comparison::LessOrEqual:
		return date <= date_;
	case Comparison::Greater:
		return date > date_;
	case Comparison::GreaterOrEqual:
		return date >= date_;
	case Comparison::Equal:
		return date == date_;
	case Comparison::NotEqual:
		return date != date_;
	}
}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const {
	switch (cmp_) {
	case Comparison::Equal:
		return event == event_;
	case Comparison::NotEqual:
		return event != event_;
	case Comparison::Less:
		return event < event_;
	case Comparison::LessOrEqual:
		return event <= event_;
	case Comparison::Greater:
		return event > event_;
	case Comparison::GreaterOrEqual:
		return event >= event_;
	}
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {
	switch (lo_) {
	case LogicalOperation::And:
		return left_->Evaluate(date,event) && no_left_->Evaluate(date, event);
	case LogicalOperation::Or:
		return left_->Evaluate(date, event) || no_left_->Evaluate(date, event);
	}
}