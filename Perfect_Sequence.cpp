#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    long long p;
    cin >> n >> p;
    long long *number = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    sort(number, number + n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+m; j < n; j++)
        {
            if (number[i]*p>=number[j]&&j-i+1>m)
            {
                m = j - i + 1;
            }
            if (number[i]*p<number[j])
            {
                break;
            }
        }
    }
    cout << m;

    return 0;
}