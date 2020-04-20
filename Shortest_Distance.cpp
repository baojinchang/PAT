#include<iostream>

using namespace std;

struct Exit
{
    int i;
    int j;
};

int main()
{
    int n;
    cin >> n;
    int *path = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> path[i];
    }
    int m;
    cin >> m;
    Exit *exit = new Exit[m];
    for (int i = 0; i < m; i++)
    {
        cin >> exit[i].i >> exit[i].j;
    }
    for (int i = 0; i < m; i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        if (exit[i].i<exit[i].j)
        {
            for (int j = exit[i].i-1; j < exit[i].j-1; j++)
            {
                sum1 = sum1 + path[j];
            }
            for (int j = exit[i].j-1; j < exit[i].i-1+n; j++)
            {
                sum2 = sum2 + path[j%n];
            }
            if (sum1<sum2)
            {
                cout << sum1 << endl;
            }
            else
            {
                cout << sum2 << endl;
            }
        }
        else
        {
            for (int j = exit[i].j-1; j < exit[i].i-1; j++)
            {
                sum1 = sum1 + path[j];
            }
            for (int j = exit[i].i-1; j < exit[i].j-1+n; j++)
            {
                sum2 = sum2 + path[j%n];
            }
            if (sum1<sum2)
            {
                cout << sum1 << endl;
            }
            else
            {
                cout << sum2 << endl;
            }
        }
    }
    delete[] path;
    delete[] exit;

    return 0;
}