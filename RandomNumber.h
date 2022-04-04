#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdio>
using namespace std;

class RandomIntergerGenerator;

class RandomIntergerGenerator
{
public:
     RandomIntergerGenerator();

public:
     int next();
     int next(int, int);
     int next(int);
};
#endif