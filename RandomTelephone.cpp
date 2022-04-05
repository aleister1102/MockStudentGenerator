#include "include/RandomTelephone.h"
#include "include/Random.h"

string RandomTelephone()
{
     Random rng;
     stringstream builder;
     builder << "09";
     for (int i = 0; i < 7; i++)
     {
          int x = rng.next(10);
          builder << x;
          if (i == 1 || i == 4)
          {
               builder << "-";
          }
     }
     string result = builder.str();
     return result;
}
