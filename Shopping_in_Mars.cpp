#include<iostream>

using namespace std;

int main()
{
    int n, account;
    cin >> n >> account;
    int *vaule = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vaule[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int j;
        for ( j = 0; j < n-i; j++)
        {
            sum = sum + vaule[(i + j) % n];
            if (sum==account)
            {
                break;
            }
        }
        if (sum==account)
        {
            count = 1;
            cout << i+1 << "-" << (i + j) % n+1
            << endl;
        }
    }
    if (count==0)
    {
        int min = account * 2;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int j;
            for ( j = 0; j < n-i; j++)
            {
                sum = sum + vaule[(i + j) % n];
                if (sum>account)
                {
                    break;
                }
            }
            if (sum<min&&sum>account)
            {
                min = sum;
            }   
        }
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int j;
            for ( j = 0; j < n-i; j++)
            {
                sum = sum + vaule[(i + j) % n];
                if (sum==min)
                {
                    break;
                }
            }
            if (sum==min)
            {
                cout << i + 1 << "-" << (i + j) % n + 1 << endl;
            }
        }
        
    }

    return 0;
}