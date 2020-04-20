#include<iostream>
#include<vector>

using namespace std;

const int INF = 10000;

struct Edage
{
    int load = INF;
    int cost = INF;
} edage[500][500];

int show(vector<int> path,int v)
{
    if (path[v]!=-1)
    {
        show(path, path[v]);
    }
    cout << v << " ";

    return 0;
}

int main()
{
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++)
    {
        int x, y, load, cost;
        cin >> x >> y >> load >> cost;
        edage[x][y].load = edage[y][x].load = load;
        edage[x][y].cost = edage[y][x].cost = cost;
    }
    vector<int> path(n);
    vector<int> vist(n);
    vector<int> distance(n);
    vector<int> sum(n);
    for (int i = 0; i < n; i++)
    {
        distance[i] = edage[s][i].load;
        sum[i] = edage[s][i].cost;
        if (distance[i]!=INF)
        {
            path[i] = s;
        }
        else
        {
            path[i] = -1;
        }
    }
    vist[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int min = INF, v;
        for (int i = 0; i < n; i++)
        {
            if (distance[i]<min&&vist[i]==0)
            {
                min = distance[i];
                v = i;
            }
        }
        vist[v] = 1;
        for (int i = 0; i < n; i++)
        {
            if (vist[i]==0)
            {
                if (distance[i]>distance[v]+edage[v][i].load)
                {
                    distance[i] = distance[v] + edage[v][i].load;
                    sum[i] = sum[v] + edage[v][i].cost;
                    path[i] = v;
                }
                else if (distance[i]==distance[v]+edage[v][i].load&&sum[i]>sum[v]+edage[v][i].cost)
                {
                    sum[i] = sum[v] + edage[v][i].cost;
                    path[i] = v;
                }
            }
        }
    }
    show(path, d);
    cout << distance[d] << " " << sum[d];

    return 0;
}