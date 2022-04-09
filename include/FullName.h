#pragma once
#include "lib.h"
#include "String.h"

class FullName;

class FullName
{
private:
	string _first;
	string _middle;
	string _last;
public:
	string First() { return _first; }
	string Middle() { return _middle; }
	string Last() { return _last; }
	void setFirst(string value) { _first = value; }
	void setMiddle(string value) { _middle = value; }
	void setLast(string value) { _last = value; }
public:
	FullName();
	FullName(string, string, string);

public:
	string toString();
	static vector<string> parseFirstNames(vector<vector<string>>, vector<float>&);
	static FullName parseFullName(string);
public:
	bool operator==(const FullName&);
};

vector<tuple<string, string>> parseFirstNames(vector<vector<string>> collections);