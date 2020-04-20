#include <iostream>

using namespace std;

bool prime(int m)
{
    if (m == 1)
    {
        return false;
    }
    int i;
    for (i = 2; i < m + 1; i++)
    {
        if (m % i == 0)
        {
            break;
        }
    }
    if (i == m)
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
    int n, m;
    cin >> m >> n;
    if (prime(m))
    {
        int *flag = new int[m];
        for (int i = 0; i < m; i++)
        {
            flag[i] = 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int number;
            cin >> number;
            int j;
            for (j = 0; j < m; j++)
            {
                if (flag[(number + j * j) % m] == 0)
                {
                    flag[(number + j * j) % m] = 1;
                    number = (number + j * j) % m;
                    break;
                }
            }
            if (j == m)
            {
                cout << "-"
                     << " ";
            }
            else
            {
                cout << number << " ";
            }
        }
        int number;
        cin >> number;
        int j;
        for (j = 0; j < m; j++)
        {
            if (flag[(number + j * j) % m] == 0)
            {
                flag[(number + j * j) % m] = 1;
                number = (number + j * j) % m;
                break;
            }
        }
        if (j == m)
        {
            cout << "-";
        }
        else
        {
            cout << number;
        }
        delete[] flag;
    }
    else
    {
        for (int i = m + 1; 1; i++)
        {
            if (prime(i))
            {
                m = i;
                break;
            }
        }
        int *flag = new int[m];
        for (int i = 0; i < m; i++)
        {
            flag[i] = 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int number;
            cin >> number;
            int j;
            for (j = 0; j < m; j++)
            {
                if (flag[(number + j * j) % m] == 0)
                {
                    flag[(number + j * j) % m] = 1;
                    number = (number + j * j) % m;
                    break;
                }
            }
            if (j == m)
            {
                cout << "-"
                     << " ";
            }
            else
            {
                cout << number << " ";
            }
        }
        int number;
        cin >> number;
        int j;
        for (j = 0; j < m; j++)
        {
            if (flag[(number + j * j) % m] == 0)
            {
                flag[(number + j * j) % m] = 1;
                number = (number + j * j) % m;
                break;
            }
        }
        if (j == m)
        {
            cout << "-";
        }
        else
        {
            cout << number;
        }
        delete[] flag;
    }

    return 0;
}