#include "include/FullName.h"

FullName::FullName()
{
	_first = "NULL";
	_middle = "NULL";
	_last = "NULL";
}

FullName::FullName(string first, string middle, string last)
{
	_first = first;
	_middle = middle;
	_last = last;
}

string FullName::toString()
{
	stringstream builder;

	builder << _first << " " << _middle << " " << _last;
	return builder.str();
}

FullName FullName::parseFullName(string str)
{
	auto names = String::split(str);

	FullName result;

	result.setFirst(names[0]);
	result.setMiddle(names[1]);
	result.setLast(names[2]);

	return result;
}

bool FullName::operator==(const FullName& other)
{
	return _first == other._first && _middle == other._middle && _last == other._last;
}