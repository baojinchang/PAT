#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *p = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int sum, temp, node = 0;
    int i1 = 0, i2 = 0;
    temp = 0, sum = -1;
    for (int i = node; i < n; i++)
    {
        temp = temp + p[i];
        if (temp < 0)
        {
            temp = 0;
            node = i + 1;
            continue;
        }
        if (temp > sum)
        {
            sum = temp;
            i1 = node, i2 = i;
        }
    }
    if (sum < 0)
    {
        cout << 0 << " " << p[0] << " " << p[n - 1];
    }
    else
    {
        cout << sum << " " << p[i1] << " " << p[i2];
    }

    return 0;
}