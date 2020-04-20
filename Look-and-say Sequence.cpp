#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    int count;
    cin >> str >> count;
    for (int i = 1; i < count; i++)
    {
        string temp;
        temp += str[0];
        int cns = 1;
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i]!=temp[temp.size()-1])
            {
                temp += to_string(cns);
                temp += str[i];
                cns = 1;
            }
            else
            {
                cns++;
            }
        }
        temp += to_string(cns);
        str = temp;
    }
    cout << str;

    return 0;
}