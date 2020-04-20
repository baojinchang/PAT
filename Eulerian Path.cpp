#include <iostream>
#include <vector>

using namespace std;

int edage[510][510] = {{0}};
int vist[510] = {0};
int n;

int dfs(int v)
{
    vist[v] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (vist[i] == 0 && edage[v][i] == 1)
        {
            dfs(i);
        }
    }

    return 0;
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        edage[temp1][temp2] = edage[temp2][temp1] = 1;
    }
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (vist[i] == 0)
        {
            dfs(i);
            sum++;
        }
    }
    vector<int> disgree(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        disgree[i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (edage[i][j] == 1)
            {
                disgree[i]++;
            }
        }
        cout << disgree[i];
        if (i != n)
        {
            cout << " ";
        }
    }
    cout << endl;
    if (sum == 1)
    {
        int count = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (disgree[i] % 2 != 0)
            {
                count++;
            }
        }
        if (count == 0)
        {
            cout << "Eulerian";
        }
        else if (count == 2)
        {
            cout << "Semi-Eulerian";
        }
        else
        {
            cout << "Non-Eulerian";
        }
    }
    else
    {
        cout << "Non-Eulerian";
    }

    return 0;
}