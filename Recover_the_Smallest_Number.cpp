#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(string str1, string str2)
{
    return str1 + str2 < str2 + str1;
}

int main()
{
    int n;
    cin >> n;
    string *str = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string str1;
    for (int i = 0; i < n; i++)
    {
        str1 = str1 + str[i];
    }
    int i;
    for (i = 0; i < str1.size(); i++)
    {
        if (str1[i] != '0')
        {
            break;
        }
    }
    if (i == str1.size())
    {
        cout << 0;
    }
    else
    {
        for (i; i < str1.size(); i++)
        {
            cout << str1[i];
        }
    }

    return 0;
}