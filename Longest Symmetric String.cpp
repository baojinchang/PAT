#include<iostream>

using namespace std;

int main()
{
    int dp[1010][1010] = {{0}};
    string str;
    getline(cin, str);
    int ans = 1;
    for (int i = 0; i < str.size(); i++)
    {
        dp[i][i] = 1;
        if (i>0)
        {
            if (str[i]==str[i-1])
            {
                dp[i - 1][i] = 1;
                ans = 2;
            }
        }
    }
    for (int i = 3; i <= str.size(); i++)
    {
        for (int j = 0; j+i-1 < str.size(); j++)
        {
            if (str[j]==str[i+j-1]&&dp[j+1][i+j-2]==1)
            {
                dp[j][i + j - 1] = 1;
                ans = i;
            }
        }
    }
    cout << ans;

    return 0;
}