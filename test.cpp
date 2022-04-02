#include "include/header.h"

int main()
{
    fstream f("./data/sample.txt", ios::in);
    if (f)
    {
        string reader;
        f >> reader;
        cout << reader << "\n";
    }

    int a = 1;
    int b = 2;
    cout << sum(a, b) <<endl;

    system("pause");
    return 1;
}