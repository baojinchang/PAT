#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool palindromic(string str)
{
    int leng = str.size();
    int i;
    for (i = 0; i < leng; i++)
    {
        if (str[i] != str[leng - 1 - i])
        {
            break;
        }
    }
    if (i == leng)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long long number, n;
    cin >> number >> n;
    string str = to_string(number);
    int i;
    for (i = 0; i < n + 1; i++)
    {
        bool tar;
        tar = palindromic(str);
        if (tar)
        {
            cout << str << endl
                 << i;
            break;
        }
        else if (i == n)
        {
            cout << str << endl
                 << i;
        }
        else
        {
            string str1, str2;
            int leng = str.size();
            str1 = str2 = str;
            for (int i = 0; i < leng; i++)
            {
                str2[i] = str[leng - 1 - i];
            }
            int targ = 0;
            for (int i = leng - 1; i >= 0; i--)
            {
                if ((str[i] - '0') + (str2[i] - '0') + targ < 10)
                {
                    str[i] = ((str[i] - '0') + (str2[i] - '0') + targ) + '0';
                    targ = 0;
                }
                else
                {
                    str[i] = ((str[i] - '0') + (str2[i] - '0') + targ - 10) + '0';
                    targ = 1;
                }
            }
            if (targ == 1)
            {
                str = '1' + str;
            }
        }
    }

    return 0;
}