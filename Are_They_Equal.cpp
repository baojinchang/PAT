#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    double number1, number2;
    cin >> n >> number1 >> number2;
    int count1, count2;
    count1 = count2 = 0;
    if (number1 >= 1)
    {
        while (number1 >= 1)
        {
            number1 = number1 / 10;
            count1++;
        }
    }
    else if (number1 < 1 && number1 > 0.1)
    {
        count1 = 0;
    }
    else
    {
        while (number1 < 0.1)
        {
            number1 = number1 * 10;
            count1--;
        }
    }
    if (number2 >= 1)
    {
        while (number2 >= 1)
        {
            number2 = number2 / 10;
            count2++;
        }
    }
    else if (number2 < 1 && number2 > 0.1)
    {
        count2 = 0;
    }
    else
    {
        while (number2 < 0.1)
        {
            number2 = number2 * 10;
            count2--;
        }
    }
    string str1, str2;
    str1 = to_string(number1);
    str2 = to_string(number2);
    if (count1 != count2)
    {
        cout << "NO"
             << " ";
        for (int i = 0; i < n + 2; i++)
        {
            cout << str1[i];
        }
        if (count1 != 0)
        {
            cout << "*"
                 << "10^" << count1 << " ";
        }
        for (int i = 0; i < n + 2; i++)
        {
            cout << str2[i];
        }
        if (count2 != 0)
        {
            cout << "*10^" << count2;
        }
    }
    else
    {
        int i;
        for (i = 0; i < n + 2; i++)
        {
            if (str1[i] != str2[i])
            {
                break;
            }
        }
        if (i == n + 2)
        {
            cout << "YES"
                 << " ";
            for (int i = 0; i < n + 2; i++)
            {
                cout << str1[i];
            }
            if (count1 != 0)
            {
                cout << "*10^" << count1;
            }
        }
        else
        {
            cout << "NO"
                 << " ";
            for (int i = 0; i < n + 2; i++)
            {
                cout << str1[i];
            }
            if (count1 != 0)
            {
                cout << "*"
                     << "10^" << count1 << " ";
            }
            for (int i = 0; i < n + 2; i++)
            {
                cout << str2[i];
            }
            if (count2 != 0)
            {
                cout << "*10^" << count2;
            }
        }
    }

    return 0;
}