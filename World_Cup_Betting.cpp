#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    double game[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> game[i][j];
        }
    }
    double sum = 1;
    for (int i = 0; i < 3; i++)
    {
        double temp = 0;
        int target = 0;
        for (int j = 0; j < 3; j++)
        {
            if (game[i][j] > temp)
            {
                temp = game[i][j];
                target = j;
            }
        }
        sum = sum * temp;
        if (target == 0)
        {
            cout << "W ";
        }
        if (target == 1)
        {
            cout << "T ";
        }
        if (target == 2)
        {
            cout << "L ";
        }
    }
    sum = (sum * 0.65 - 1) * 2;
    cout << setiosflags(ios::fixed) << setprecision(2) << sum;

    return 0;
}