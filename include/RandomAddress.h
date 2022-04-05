#pragma once
#include "Address.h"
#include "Random.h"

class RandomAddress
{
private:
     vector<string> _numbers;
     vector<string> _streets;
     vector<string> _wards;
     vector<string> _districts;
     vector<string> _citys;

     Random _rng;

public:
     RandomAddress();

public:
     string randomNumber();
     Address next();
};