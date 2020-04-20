#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int flag[50001] = {0};

bool cmp(int a, int b)
{
    if (flag[a] == flag[b])
    {
        return a < b;
    }
    return flag[a] > flag[b];
}

int main()
{
    int k;
    cin >> n >> k;
    int dp[k] = {0};
    int count = 0;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i < n; i++)
    {
        cout << num[i] << ": ";
        flag[num[i - 1]]++;
        int j;
        for (j = 0; j < count; j++)
        {
            if (num[i-1] == dp[j])
            {
                break;
            }
        }
        if (j == count)
        {
            if (count != k)
            {
                dp[count++] = num[i - 1];
            }
            else
            {
                if (flag[dp[k - 1]] == flag[num[i - 1]])
                {
                    if (dp[k - 1] > num[i - 1])
                    {
                        dp[k - 1] = num[i - 1];
                    }
                }
                else if (flag[dp[k - 1]] < flag[num[i - 1]])
                {
                    dp[k - 1] = num[i - 1];
                }
            }
        }
        sort(dp, dp + count, cmp);
        for (int j = 0; j < count; j++)
        {
            cout << dp[j];
            if (j != count - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}