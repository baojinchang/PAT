#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    int number;
    cin >> number;
    string str = to_string(number);
    if (str.size() == 3)
        {
            str = "0" + str;
        }
        if (str.size() == 2)
        {
            str = "00" + str;
        }
        if (str.size() == 1)
        {
            str = "000" + str;
        }
    int count = 0;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != str[0])
        {
            break;
        }
        count++;
    }
    if (count == str.size() - 1)
    {
        cout << str << " "
             << "-"
             << " ";
        cout << str << " "
             << "="
             << " "
             << "0000";
    }
    else
    {
        int number[4];
        for (int i = 0; i < 4; i++)
        {
            if (i < str.size())
            {
                number[i] = str[i] - '0';
            }
            else
            {
                number[i] = 0;
            }
        }
        sort(number, number + 4);
        int a, b;
        a = b = 0;
        for (int i = 0; i < 4; i++)
        {
            a = a + number[i] * pow(10, i);
            b = b + number[i] * pow(10, 3 - i);
        }
        int c = a - b;
        cout << a << " "
             << "-"
             << " ";
        if (b < 1000 && b >= 100)
        {
            cout << 0;
        }
        if (b < 100 && b >= 10)
        {
            cout << "00";
        }
        if (b < 10)
        {
            cout << "000";
        }
        cout << b;
        cout << " "
             << "="
             << " ";
        if (c < 1000 && c >= 100)
        {
            cout << 0;
        }
        if (c < 100 && c >= 10)
        {
            cout << "00";
        }
        if (c < 10)
        {
            cout << "000";
        }
        cout << c << endl;
        while (c != 6174)
        {
            str = to_string(c);
            for (int i = 0; i < 4; i++)
            {
                if (i < str.size())
                {
                    number[i] = str[i] - '0';
                }
                else
                {
                    number[i] = 0;
                }
            }
            sort(number, number + 4);
            a = b = 0;
            for (int i = 0; i < 4; i++)
            {
                a = a + number[i] * pow(10, i);
                b = b + number[i] * pow(10, 3 - i);
            }
            c = a - b;
            cout << a << " "
                 << "-"
                 << " ";
            if (b < 1000 && b >= 100)
            {
                cout << 0;
            }
            if (b < 100 && b >= 10)
            {
                cout << "00";
            }
            if (b < 10)
            {
                cout << "000";
            }
            cout << b;
            cout << " "
                 << "="
                 << " ";
            if (c < 1000 && c >= 100)
            {
                cout << 0;
            }
            if (c < 100 && c >= 10)
            {
                cout << "00";
            }
            if (c < 10)
            {
                cout << "000";
            }
            cout << c << endl;
        }
    }

    return 0;
}