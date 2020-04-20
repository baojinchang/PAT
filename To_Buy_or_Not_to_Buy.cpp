#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int flag[1000] = {0};
    int sum = 0;
    for (int i = 0; i < str2.size(); i++)
    {
        int j;
        for ( j = 0; j < str1.size(); j++)
        {
            if (str2[i]==str1[j]&&flag[j]==0)
            {
                flag[j] = 1;
                break;
            }
        }
        if (j==str1.size())
        {
            sum++;
        }
    }
    if (sum==0)
    {
        cout << "Yes"
             << " " << str1.size() - str2.size();
    }
    else
    {
        cout << "No"
             << " " << sum;
    }
    

    return 0;
}