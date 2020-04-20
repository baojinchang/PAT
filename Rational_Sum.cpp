#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long sum1, sum2;
    sum2 = 1, sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        long a, b;
        scanf("%d/%d", &a, &b);
        int c, d;
        c = sum1;
        d = sum2;
        sum1 = a * d + b * c;
        sum2 = b * d;
    }
    if (sum1 >= sum2)
    {
        cout << sum1 / sum2;
        sum1 = sum1 % sum2;
        if (sum1>0)
        {
            cout << " ";
        }
    }
    int i = 2;
    while (i<=sum1)
    {
        if (sum1%i==0&&sum2%i==0)
        {
            sum1 = sum1 / i;
            sum2 = sum2 / i;
            i = 1;
        }
        i++;
    }
    
    if (sum1!=0)
    {
        cout << sum1 << "/" << sum2;
    }

    return 0;
}