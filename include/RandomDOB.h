#pragma once
#include "DOB.h"
#include "Random.h"

class RandomDOB
{
private:
     Random _rng;

public:
     Date next();
};