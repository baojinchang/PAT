#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << '#';
    string str1, str2, str3;
    for (int i = 0; i < 2; i++)
    {
        int number = n % 13;
        if (number == 10)
        {
            str1 = "A" + str1;
        }
        if (number == 11)
        {
            str1 = "B" + str1;
        }
        if (number == 12)
        {
            str1 = "C" + str1;
        }
        if (number < 10)
        {
            str1 = to_string(number) + str1;
        }
        n = n / 13;
    }
    for (int i = 0; i < 2; i++)
    {
        int number = m % 13;
        if (number == 10)
        {
            str2 = "A" + str2;
        }
        if (number == 11)
        {
            str2 = "B" + str2;
        }
        if (number == 12)
        {
            str2 = "C" + str2;
        }
        if (number < 10)
        {
            str2 = to_string(number) + str2;
        }
        m = m / 13;
    }
    for (int i = 0; i < 2; i++)
    {
        int number = k % 13;
        if (number == 10)
        {
            str3 = "A" + str3;
        }
        if (number == 11)
        {
            str3 = "B" + str3;
        }
        if (number == 12)
        {
            str3 = "C" + str3;
        }
        if (number < 10)
        {
            str3 = to_string(number) + str3;
        }
        k = k / 13;
    }
    cout << str1 << str2 << str3;

    return 0;
}