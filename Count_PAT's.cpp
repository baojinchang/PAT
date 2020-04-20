#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int count = 0;
    int p = 0;
    int a = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'P')
        {
            p++;
        }
        else if (str[i]=='A')
        {
            a = p + a;
        }
        else
        {
            count = (count + a)%1000000007;
        }
    }
    cout << count ;

    return 0;
}