#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *floor = new int(n + 1);
    floor[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> floor[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (floor[i + 1] > floor[i])
        {
            sum = sum + (floor[i + 1] - floor[i]) * 6;
        }
        else if (floor[i + 1] < floor[i])
        {
            sum = sum + (floor[i] - floor[i + 1]) * 4;
        }
        sum = sum + 5;
    }
    cout << sum;

    return 0;
}