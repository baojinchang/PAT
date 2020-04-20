#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int k=0;
    int w;
    int child [110];
};

int n, w;

Node node[101];

bool cmp(int a,int b)
{
    return node[a].w > node[b].w;
}

int path [110];

int dfs(int sum,int deep,int v)
{
    sum = sum + node[v].w;
    path[deep] = node[v].w;
    if (node[v].k==0)
    {
        if (sum==w)
        {
            for (int i = 0; i < deep; i++)
            {
                cout << path[i] << " ";
            }
            cout << path[deep] << endl;
            return 0;
        }
        else
        {
            return 0;
        } 
    }
    else
    {
        for (int i = 0; i < node[v].k; i++)
        {
            dfs(sum, deep + 1, node[v].child[i]);
        }
    }

    return 0;
}

int main()
{
    int m;
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].w;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cin >> node[temp].k;
        for (int j = 0; j < node[temp].k; j++)
        {
            cin >> node[temp].child[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sort(node[i].child, node[i].child + node[i].k, cmp);
    }
    dfs(0, 0, 0);

    return 0;
}