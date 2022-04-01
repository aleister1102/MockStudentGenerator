#include "./include/header.h"

int main()
{
    fstream f("./data/sample.txt", ios::in);
    if (f)
    {
        string reader;
        f >> reader;
        cout << reader << "\n";
    }

    system("pause");
    return 1;
}