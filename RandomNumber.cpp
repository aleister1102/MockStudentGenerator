#include "RandomNumber.h"

/**
 * @brief Khởi tạo hạt giống thời gian
 */
RandomIntergerGenerator::RandomIntergerGenerator()
{
     srand(time(NULL));
}

/**
 * @brief Tạo ra một số ngẫu nhiên
 *
 * @return Số vừa tạo
 */
int RandomIntergerGenerator::next()
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
int RandomIntergerGenerator::next(int min, int max)
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
int RandomIntergerGenerator::next(int ceiling)
{
     int num = rand() % ceiling;
     return num;
}