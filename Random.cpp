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
     vector<vector<string>> firstNamesData = file.readCSV("data/firstNames.csv");
     _firstNames = FullName::parseFirstNames(firstNamesData, _frequencies);
     _middleNames = file.readTXT("data/middleNames.txt");
     _lastNames = file.readTXT("data/lastNames.txt");
}

/**
 * Return a random FullName
 * 
 * @return A random FullName.
 */
FullName RandomFullName::next()
{
    string firstName = _firstNames[_rng.next() % _firstNames.size()];
    string middleName = _middleNames[_rng.next() % _middleNames.size()];
    string lastName = _lastNames[_rng.next() % _lastNames.size()];
    
    FullName result(firstName, middleName, lastName);

    return result;
}

