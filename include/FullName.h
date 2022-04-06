#pragma once
#include "lib.h"

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
public:
    FullName();
    FullName(string, string, string);

public:
    string toString();
    static vector<string> parseFirstNames(vector<vector<string>>, vector<float> &);
};
