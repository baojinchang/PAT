#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int *favorite = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> favorite[i];
    }
    int k;
    cin >> k;
    int *order = new int[k];
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        for ( int j = 0; j < m; j++)
        {
            if (temp==favorite[j])
            {
                order[count++] = j;
                break;
            }
        }
    }
    delete[] favorite;
    int *dp = new int[count];
    for (int i = 0; i < count; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (order[i]>=order[j]&&1+dp[j]>dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
    }
    delete[] order;
    int max = 0;
    for (int i = 0; i < count; i++)
    {
        if (dp[i]>max)
        {
            max = dp[i];
        }
    }
    delete[] dp;
    cout << max;

    return 0;
}