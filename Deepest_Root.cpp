#include <iostream>

using namespace std;

struct arcnode
{
    int data;
    arcnode *next;
};

struct headnode
{
    arcnode *firstarc;
};

struct graph
{
    headnode node[10001];
    int n;
};

graph g;

int dfs(int target[], int v)
{
    arcnode *p;
    target[v - 1] = 1;
    p = g.node[v].firstarc;
    while (p != NULL)
    {
        if (target[p->data - 1] == 0)
        {
            dfs(target, p->data);
        }
        p = p->next;
    }

    return 0;
}

int deep = 0;

int search_root(int target[], int temp, int v)
{
    arcnode *p;
    target[v - 1] = 1;
    if (temp > deep)
    {
        deep = temp;
    }

    p = g.node[v].firstarc;
    while (p != NULL)
    {
        if (target[p->data - 1] == 0)
        {
            search_root(target, temp + 1, p->data);
        }
        p = p->next;
    }

    return 0;
}

int main()
{
    cin >> g.n;
    for (int i = 0; i < g.n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        arcnode *p = new arcnode;
        p->data = y;
        p->next = g.node[x].firstarc;
        g.node[x].firstarc = p;
        arcnode *q = new arcnode;
        q->data = x;
        q->next = g.node[y].firstarc;
        g.node[y].firstarc = q;
    }
    int taregt[10001] = {0};
    int sum = 0;
    for (int i = 1; i < g.n + 1; i++)
    {
        if (taregt[i - 1] == 0)
        {
            dfs(taregt, i);
            sum++;
        }
    }
    if (sum > 1)
    {
        cout << "Error: " << sum << " components";
    }
    else
    {
        int MAX = 0;
        for (int i = 1; i < g.n + 1; i++)
        {
            for (int i = 0; i < g.n; i++)
            {
                taregt[i] = 0;
            }
            search_root(taregt, 0, i);
            if (deep > MAX)
            {
                MAX = deep;
            }
            deep = 0;
        }
        for (int i = 1; i < g.n + 1; i++)
        {
            for (int i = 0; i < g.n; i++)
            {
                taregt[i] = 0;
            }
            search_root(taregt, 0, i);
            if (deep == MAX)
            {
                cout << i << endl;
            }
            deep = 0;
        }
    }

    return 0;
}