#include <iostream>

using namespace std;

const int INF = 10000;

struct Edage
{
    int length = INF;
    int time = INF;
} edage[510][510];

int start, dest;

int show(int path[], int v)
{
    if (path[v] != start)
    {
        show(path, path[v]);
    }
    cout << path[v] << " -> ";

    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, tag;
        cin >> v1 >> v2 >> tag;
        cin >> edage[v1][v2].length >> edage[v1][v2].time;
        if (tag == 0)
        {
            edage[v2][v1] = edage[v1][v2];
        }
    }
    cin >> start >> dest;
    int distance[520];
    int time[510];
    int path1[510], path2[510];
    int vist[510] = {0};
    int num[510] = {0}, ti[510];
    for (int i = 0; i < n; i++)
    {
        if (edage[start][i].length != INF)
        {
            distance[i] = edage[start][i].length;
            path1[i] = start;
            ti[i] = edage[start][i].time;
        }
        else
        {
            distance[i] = INF;
            ti[i] = INF;
        }
        if (edage[start][i].time != INF)
        {
            time[i] = edage[start][i].time;
            path2[i] = start;
            num[i] = 1;
        }
        else
        {
            time[i] = INF;
            num[i] = 0;
        }
    }
    vist[start] = 1;
    for (int i = 0; i < n; i++)
    {
        int min = INF;
        int v;
        for (int j = 0; j < n; j++)
        {
            if (distance[j] < min && vist[j] == 0)
            {
                min = distance[i];
                v = j;
            }
        }
        vist[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (distance[j] > distance[v] + edage[v][j].length && vist[j] == 0)
            {
                distance[j] = distance[v] + edage[v][j].length;
                path1[j] = v;
                ti[j] = ti[v] + edage[v][j].time;
            }
            else if (distance[j] == distance[v] + edage[v][j].length && vist[j] == 0)
            {
                if (ti[j] > ti[v] + edage[v][j].time)
                {
                    path1[j] = v;
                    ti[j] = ti[v] + edage[v][j].time;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        vist[i] = 0;
    }
    vist[start] = 1;
    for (int i = 0; i < n; i++)
    {
        int min = INF;
        int v;
        for (int j = 0; j < n; j++)
        {
            if (time[j] < min && vist[j] == 0)
            {
                min = time[i];
                v = j;
            }
        }
        vist[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (time[j] > time[v] + edage[v][j].time && vist[j] == 0)
            {
                time[j] = time[v] + edage[v][j].time;
                path2[j] = v;
                num[j] = num[v] + 1;
            }
            else if (time[j] == time[v] + edage[v][j].time && vist[j] == 0 && num[j] > num[v] + 1)
            {
                path2[j] = v;
                num[j] = num[v] + 1;
            }
        }
    }
    int p = dest;
    while (path1[p] == path2[p])
    {
        p = path1[p];
        if (p == start)
        {
            break;
        }
    }
    if (p == start)
    {
        cout << "Distance = " << distance[dest];
        cout << "; Time = " << time[dest];
        cout << ": ";
        show(path1, dest);
        cout << dest;
    }
    else
    {
        cout << "Distance = ";
        cout << distance[dest];
        cout << ": ";
        show(path1, dest);
        cout << dest << endl;
        cout << "Time = ";
        cout << time[dest];
        cout << ": ";
        show(path2, dest);
        cout << dest;
    }

    return 0;
}
