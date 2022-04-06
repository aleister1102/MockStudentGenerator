#include "include/Random.h"

/**
 * @brief Khởi tạo hạt giống thời gian
 */
Random::Random()
{
     srand(time(NULL));
}

/**
 * @brief Tạo ra một số ngẫu nhiên
 *
 * @return Số vừa tạo
 */
int Random::next()
{
     int num = rand();
     return num;
}

/**
 * @brief Tạo ra một số ngẫu nhiên trong đoạn [min, max]
 *
 * @param min cận dưới
 * @param max cận trên
 * @return Số vừa tạo
 */
int Random::next(int min, int max)
{
     int num = rand() % (max - min + 1) + min;
     return num;
}

/**
 * @brief Tạo một số ngẫu nhiên trong nửa khoảng [0, ceiling)
 *
 * @param ceiling khoảng tạo số ngẫu nhiên mong muốn
 * @return Số vừa tạo
 */
int Random::next(int ceiling)
{
     int num = rand() % ceiling;
     return num;
}


/**
 * Reads in the first names, middle names, and last names from the data files and stores them in the
 * appropriate member variables
 */
RandomFullName::RandomFullName()
{
     File file;
     _middleNames = file.readTXT(MIDDLENAMES);
     _lastNames = file.readTXT(LASTNAMES);
}

/**
 * Return a random FullName
 * 
 * @return A random FullName.
 */
FullName RandomFullName::next(Random rng)
{
    string firstName = RandomFirstName().next(rng);
    string middleName = _middleNames[rng.next() % _middleNames.size()];
    string lastName = _lastNames[rng.next() % _lastNames.size()];
    
    FullName result(firstName, middleName, lastName);

    return result;
}

RandomFirstName::RandomFirstName()
{
    File file;

    vector<vector<string>> firstNamesData = file.readCSV(FIRSTNAMES);
    _firstNames = FullName::parseFirstNames(firstNamesData, _frequencies);
}

string RandomFirstName::next(Random rng)
{
    float u = rng.next() % 100 / 100.0;
    float sp = 0;
    int result = 0;

    for (int i = 0; i < _frequencies.size(); i++)
    {
        sp += _frequencies[i]/100;
        if (sp >= u)
        {
            result = i;
            break;
        }
    }

    return _firstNames[result];
}