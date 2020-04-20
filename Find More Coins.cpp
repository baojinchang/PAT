#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;
vector<int> ans;
int temp[10000];
int n, m;

int dfs(int v, int deep, int sum)
{
    sum += coin[v];
    temp[deep] = coin[v];
    if (sum == m)
    {
        if (deep + 1 > ans.size())
        {
            for (int i = 0; i < deep + 1; i++)
            {
                ans.push_back(temp[i]);
            }
        }
        return 1;
    }
    for (int i = v + 1; i < coin.size(); i++)
    {
        if (sum + coin[v] <= m)
        {
            int a = dfs(i, deep + 1, sum);
            if (a == 1)
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp <= m)
        {
            coin.push_back(temp);
        }
    }
    sort(coin.begin(), coin.end());
    for (int i = 0; i < coin.size(); i++)
    {
        dfs(i, 0, 0);
        if (ans.size() != 0)
        {
            break;
        }
    }
    if (ans.size() == 0)
    {
        printf("No Solution");
        return 0;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d", ans[i]);
        if (i != ans.size() - 1)
        {
            printf(" ");
        }
    }

    return 0;
}