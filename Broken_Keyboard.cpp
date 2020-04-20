#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    char str3[80];
    int leng = 0;
    cin >> str1 >> str2;
    int count = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (count < str2.size())
        {
            if (str2[count] != str1[i])
            {
                if (str1[i] <= 'z' && str1[i] >= 'a')
                {
                    str1[i] = str1[i] - 32;
                }
                str3[leng] = str1[i];
                leng++;
            }
            else
            {
                count++;
            }
        }
        else
        {
            if (str1[i] <= 'z' && str1[i] >= 'a')
            {
                str1[i] = str1[i] - 32;
            }
            str3[leng] = str1[i];
            leng++;
        }
    }
    cout << str3[0];
    for (int i = 1; i < leng; i++)
    {
        int j;
        for ( j = 0; j < i; j++)
        {
            if (str3[j]==str3[i])
            {
                break;
            }
        }
        if (j==i)
        {
            cout << str3[i];
        }
        
    }

    return 0;
}