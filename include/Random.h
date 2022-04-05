#pragma once
#include "lib.h"

class Random;

class Random
{
public:
     Random();

public:
     int next();
     int next(int, int);
     int next(int);
};

class Fullname
{
private:
     string _first;
     string _middlle;
     string _last;

public:
     Fullname();
     Fullname(string, string, string);

public:
     string toString();
};
