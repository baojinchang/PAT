#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int left, right, now;
    int a = 1;
    while (n/a)
    {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if (now==0)
        {
            sum += left * a;
        }
        else if (now==1)
        {
            sum += left * a + right + 1;
        }
        else
        {
            sum += (left + 1) * a;
        }
        a = a * 10;
    }
    cout << sum;

    return 0;
}