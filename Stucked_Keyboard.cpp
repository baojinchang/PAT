#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int k;
    cin >> k;
    string str;
    cin >> str;
    map<char, int> target;
    for (int i = 0; i < str.size(); i++)
    {
        if (target[str[i]]==-1)
        {
            continue;
        }
        int j;
        for ( j = i+1; j < i+k; j++)
        {
            if (str[j]!=str[i])
            {
                break;
            }
        }
        if (j==i+k)
        {
            target[str[i]] = 1;
        }
        else
        {
            target[str[i]] = -1;
        }
        i = j - 1;
    }
    string str2;
    string str3;
    for (int i = 0; i < str.size(); i++)
    {
        if (target[str[i]]==1)
        {
            str2 += str[i];
            i = i + k - 1;
            str3 += str[i];
            target[str[i]] = 0;
        }
        else if (target[str[i]]==0)
        {
            str2 += str[i];
            i = i + k - 1;
        }
        else
        {
            str2 += str[i];
        }
    }
    cout << str3 << endl;
    cout << str2;

    return 0;
}