#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin,str1);
    getline(cin, str2);
    for (int i = 0; i < str1.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i]==str2[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag==0)
        {
            cout << str1[i];
        }
    }

    return 0;
}