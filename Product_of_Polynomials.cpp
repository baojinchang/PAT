#include <iomanip>
#include <iostream>
using namespace std;

double a[1001] = {0}, b[1001] = {0}, k[2], c[2001] = {0};

int main()
{
    cin >> k[0];
    for (int i = 0; i < k[0]; i++)
    {
        int temp;
        cin >> temp;
        cin >> a[temp];
    }
    cin >> k[1];
    for (int i = 0; i < k[1]; i++)
    {
        int temp;
        cin >> temp;
        cin >> b[temp];
    }
    int k = 0;
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            c[i + j] = c[i + j] + a[i] * b[j];
        }
    }
    for (int i = 0; i < 2001; i++)
    {
        if (c[i] != 0)
        {
            k++;
        }
    }

    if (k != 0)
    {
        cout << k << " ";
    }
    else
    {
        cout << k;
    }
    for (int i = 2000; i >= 0; i--)
    {
        if (c[i] != 0)
        {
            k--;
            if (k > 0)
            {

                cout << i << " " << setiosflags(ios::fixed) << setprecision(1) << c[i] << " ";
            }
            else
            {

                cout << i << " " << setiosflags(ios::fixed) << setprecision(1) << c[i];
            }
        }
    }
    return 0;
}