#include<iostream>

using namespace std;

bool prime(int number)
{
    int i=2;
    for ( i = 2; i < number; i++)
    {
        if (number%i==0)
        {
            break;
        }
    }
    if (i==number)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << n << "=";
    if (n==1)
    {
        cout << 1;
    }
    int flag = 0;
    for (int i = 2; i < n+1; i++)
    {
        if (prime(i))
        {
            int count = 0;
            while (n%i==0&&n!=1)
            {
                n = n / i;
                count++;
            }
            if (count!=0)
            {
                if (flag==1)
                {
                    if (count>1)
                    {
                        cout << "*" << i << "^" << count;
                    }
                    else
                    {
                        cout << "*" << i;
                    }
                }
                else
                {
                    if (count>1)
                    {
                        cout << i << "^" << count;
                    }
                    else
                    {
                        cout << i;
                    }
                }
                flag = 1;
            }
        }
    }

    return 0;
}