#include <iostream>

using namespace std;

int net[1001][1001] = {{0}};
int l, n;

int dfs(int vist[], int v,int deep)
{
    vist[v] = 1;
    if (deep==l)
    {
        return 0;
    }
    for (int i = 1; i < n+1; i++)
    {
        if (net[v][i]==1&&vist[i]==0)
        {
            dfs(vist, i, deep + 1);
        }
    }

    return 0;
}

int main()
{
    cin >> n >> l;
    for (int i = 1; i < n + 1; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int temp;
            cin >> temp;
            net[temp][i] = 1;
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int v;
        cin >> v;
        int vist[1001] = {0};
        dfs(vist, v, 0);
        int count = 0;
        for (int i = 1; i < n+1; i++)
        {
            if (vist[i]==1)
            {
                count++;
            }
        }
        cout << count - 1 << endl;

    }

    return 0;
}
