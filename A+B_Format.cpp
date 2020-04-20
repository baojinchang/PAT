#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int number = num1 + num2;
    if (number < 0)
    {
        number = -number;
        cout << "-";
    }

    string str;
    str = to_string(number);
    int leng;
    leng = str.size();
    int len = leng % 3;
    if (len != 0)
    {
        for (int i = 0; i < len; i++)
        {
            cout << str[i];
        }
        if (len != leng)
        {
            cout << ",";
        }
    }
    int j = 0;
    for (int i = len; i < leng; i++)
    {
        cout << str[i];
        j++;
        if (j % 3 == 0 && j != leng - len)
        {
            cout << ",";
        }
    }

    return 0;
}