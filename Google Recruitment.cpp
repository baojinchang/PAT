#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool isprime(int num)
{
    if (num==1)
    {
        return false;
    }
    for (int i = 2; i*i <= num; i++)
    {
        if (num%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string num;
    cin >> num;
    int flag = 0;
    for (int i = 0; i <= n-m; i++)
    {
        int sum = 0;
        for (int j = i; j < i+m; j++)
        {
            sum += (num[j] - '0') * pow(10, m - 1 - j + i);
        }
        if (isprime(sum))
        {
            flag = sum;
            break;
        }
    }
    if (flag)
    {
        string str = to_string(flag);
        for (int i = 0; i < m-str.size(); i++)
        {
            cout << "0";
        }
        cout << flag;
    }
    else
    {
        cout << "404";
    }

    return 0;
}