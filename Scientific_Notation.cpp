#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string str[3];
    int count = 0;
    char word;
    word = getchar();
    while (word != '\n')
    {
        if (word != '.' && word != 'E')
        {
            str[count] = str[count] + word;
        }
        else
        {
            count++;
        }
        word = getchar();
    }
    if (str[0][0] == '+')
    {
        str[0].erase(str[0].begin());
    }
    else
    {
        str[0].erase(str[0].begin());
        cout << "-";
    }
    if (str[2][0] == '-')
    {
        cout << "0.";
        str[2].erase(str[2].begin());
        int a = 0;
        for (int i = 0; i < str[2].size(); i++)
        {
            a = a + (str[2][i] - '0') * pow(10, str[2].size() - 1 - i);
        }
        a = a - 1;
        for (int i = 0; i < a; i++)
        {
            cout << 0;
        }
        cout << str[0] << str[1];
    }
    else
    {
        str[2].erase(str[2].begin());
        int a = 0;
        for (int i = 0; i < str[2].size(); i++)
        {
            a = a + (str[2][i] - '0') * pow(10, str[2].size() - 1 - i);
        }
        if (a >= str[1].size())
        {
            cout << str[0] << str[1];
            for (int i = 0; i < a - str[1].size(); i++)
            {
                cout << 0;
            }
        }
        else
        {
            cout << str[0];
            for (int i = 0; i < a; i++)
            {
                cout << str[1][i];
            }
            cout << '.';
            for (int i = a; i < str[1].size(); i++)
            {
                cout << str[1][i];
            }
        }
    }

    return 0;
}