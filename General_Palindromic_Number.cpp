#include <iostream>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    int number[36], leng = 0;
    if (n == 0)
    {
        number[0] = 0;
        leng = 2;
    }
    else
    {
        while (n > 0)
        {
            number[leng] = n % b;
            n = n / b;
            leng++;
        }
    }
    int i;
    for (i = 0; i < leng; i++)
    {
        if (number[i] != number[leng - 1 - i])
        {
            break;
        }
    }
    if (i == leng)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    for (int j = leng - 1; j > 0; j--)
    {
        cout << number[j] << " ";
    }
    cout << number[0];

    return 0;
}