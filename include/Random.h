#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

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
#endif