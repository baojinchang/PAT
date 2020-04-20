#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int target;

int prime(int number)
{
    int i;
    for (i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            break;
        }
    }
    if (i == number)
    {
        target++;
    }
    return 0;
}

int main()
{
    int n, d;
    cin >> n;
    while (n >= 0)
    {
        cin >> d;
        string str1;
        str1 = to_string(n);
        int leng = str1.size();
        target = 0;
        prime(n);
        int number2 = 0;
        string str2;
        while (n > 0)
        {
            str2 = str2 + to_string(n % d);
            n = n / d;
        }
        leng = str2.size();
        for (int i = leng - 1; i >= 0; i--)
        {
            number2 = number2 + pow(d, leng - 1 - i) * (str2[i] - '0');
        }
        prime(number2);
        if (target == 2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        cin >> n;
    }

    return 0;
}