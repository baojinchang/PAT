#include <iostream>
using namespace std;

int road[1000][1000];
int dfs(int v, int vist[], int n)
{
    vist[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (vist[i] == 0 && road[v][i] == 1)
        {
            dfs(i, vist, n);
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            road[i][j] = 0;
        }
    }

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1;
        cin >> temp2;
        road[temp1 - 1][temp2 - 1] = road[temp2 - 1][temp1 - 1] = 1;
    }
    int *search = new int(k);
    for (int i = 0; i < k; i++)
    {
        cin >> search[i];
    }
    int *vist = new int(n);
    for (int i = 0; i < n; i++)
    {
        vist[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        vist[search[i] - 1] = 1;
        int sum;
        sum = -1;
        for (int i = 0; i < n; i++)
        {
            if (vist[i] == 0)
            {
                dfs(i, vist, n);
                sum++;
            }
        }
        cout << sum << endl;
        for (int i = 0; i < n; i++)
        {
            vist[i] = 0;
        }
    }

    return 0;
}