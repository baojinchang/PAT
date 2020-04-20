#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string *str = new string[n];
    getline(cin, str[0]);
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < str[i].size()/2; j++)
        {
            char q = str[i][j];
            str[i][j] = str[i][str[i].size() - 1 - j];
            str[i][str[i].size() - 1 - j] = q;
        }
    }
    int min = str[0].size();
    for (int i = 0; i < n; i++)
    {
        if (str[i].size()<min)
        {
            min = str[i].size();
        }
    }
    int i;
    for ( i = 0; i < min; i++)
    {
        char a = str[0][i];
        int j = 1;
        for ( j ; j < n; j++)
        {
            if (str[j][i]!=a)
            {
                break;
            }
        }
        if (j!=n)
        {
            break;
        }
    }
    if (i==0)
    {
        cout << "nai";
    }
    else
    {
        min = i-1;
        for ( min; min >= 0; min--)
        {
            cout << str[0][min];
        }
    }
    
    return 0;
}