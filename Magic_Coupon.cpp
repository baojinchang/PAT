#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *number1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> number1[i];
    }
    int m;
    cin >> m;
    int *number2 = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> number2[i];
    }
    sort(number1, number1 + n);
    sort(number2, number2 + m);
    int sum = 0;
    int i = 0;
    while (number1[i] < 0 && number2[i] < 0)
    {
        sum = sum + number1[i] * number2[i];
        i++;
    }
    i = n - 1;
    int j = m - 1;
    while (number1[i] > 0 && number2[j] > 0)
    {
        sum = sum + number1[i] * number2[j];
        i--;
        j--;
    }

    cout << sum;

    return 0;
}