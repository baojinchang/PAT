#include<iostream>
#include<queue>

using namespace std;

int flag[70][1290][130];

struct Node
{
    int l, m, n;
};

int main()
{
    int m, n, l, t;
    cin >> m >> n >> l >> t;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> flag[i][j][k];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (flag[i][j][k]==1)
                {
                    int count = 0;
                    queue<Node> que;
                    que.push({i, j, k});
                    flag[i][j][k] = 0;
                    while (!que.empty())
                    {
                        Node temp = que.front();
                        que.pop();
                        count++;
                        if (temp.l-1>=0&&flag[temp.l-1][temp.m][temp.n]==1)
                        {
                            que.push({temp.l - 1, temp.m, temp.n});
                            flag[temp.l - 1][temp.m][temp.n] = 0;
                        }
                        if (temp.l+1<l&&flag[temp.l+1][temp.m][temp.n]==1)
                        {
                            que.push({temp.l + 1, temp.m, temp.n});
                            flag[temp.l + 1][temp.m][temp.n] = 0;
                        }
                        if (temp.m-1>=0&&flag[temp.l][temp.m-1][temp.n]==1)
                        {
                            que.push({temp.l, temp.m - 1, temp.n});
                            flag[temp.l][temp.m - 1][temp.n] = 0;
                        }
                        if (temp.m+1<m&&flag[temp.l][temp.m+1][temp.n]==1)
                        {
                            que.push({temp.l, temp.m + 1, temp.n});
                            flag[temp.l][temp.m + 1][temp.n] = 0;
                        }
                        if (temp.n-1>=0&&flag[temp.l][temp.m][temp.n-1]==1)
                        {
                            que.push({temp.l, temp.m, temp.n - 1});
                            flag[temp.l][temp.m][temp.n - 1] = 0;
                        }
                        if (temp.n+1<n&&flag[temp.l][temp.m][temp.n+1]==1)
                        {
                            que.push({temp.l, temp.m, temp.n + 1});
                            flag[temp.l][temp.m][temp.n + 1] = 0;
                        }
                    }
                    if (count>=t)
                    {
                        ans += count;
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}