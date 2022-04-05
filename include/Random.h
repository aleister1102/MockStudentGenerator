#pragma once
#include "File.h"
#include "FullName.h"
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

class RandomFullName
{
private:
     vector<string> _firstNames;
     vector<float> _frequencies;
     vector<string> _middleNames;
     vector<string> _lastNames;
     Random _rng;

public:
     RandomFullName();

public:
    FullName next();
};