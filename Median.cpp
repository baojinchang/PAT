#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    int median = (n + m + 1) / 2;
    int j = 0, count = 0;
    long b;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        while (a[j] < b && j < n)
        {
            count++;
            if (count == median)
            {
                cout << a[j];

                return 0;
            }
            j++;
        }
        count++;
        if (median == count)
        {
            cout << b;

            return 0;
        }
    }
    while (1)
    {
        count++;
        if (count == median)
        {
            cout << a[j];

            return 0;
        }
        j++;
    }

    return 0;
}