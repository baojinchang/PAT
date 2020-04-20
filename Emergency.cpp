#include<iostream>
#include<vector>

using namespace std;

const int INF = 10000;

int edage[500][500];

int main()
{
    int n, m, start, des;
    cin >> n >> m >> start >> des;
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            edage[i][j] = INF;
        }
    }
    vector<int> team(n);
    for (int i = 0; i < n; i++)
    {
        cin >> team[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, temp;
        cin >> x >> y >> temp;
        edage[x][y] = edage[y][x] = temp;
    }
    vector<int> vist(n);       
    vector<int> destance(n);
    vector<int> num(n);
    vector<int> load(n);
    for (int i = 0; i < n; i++)
    {
        destance[i] = edage[start][i];
        if (edage[start][i]!=INF)
        {
            num[i] = team[start] + team[i];
            load[i]++;
        }
    }
    vist[start] = 1;
    for (int i = 0; i < n; i++)
    {
        int min, v;
        min = INF;
        for (int i = 0; i < n; i++)
        {
            if (vist[i]==0&&destance[i]<min)
            {
                v = i;
                min = destance[i];
            }
        }
        vist[v] = 1;
        for (int i = 0; i < n; i++)
        {
            if (vist[i]==0)
            {
                if (destance[i]>destance[v]+edage[v][i])
                {
                    destance[i] = destance[v] + edage[v][i];
                    num[i] = num[v] + team[i];
                    load[i] = load[v];
                }
                else if (destance[i]==destance[v]+edage[v][i])
                {
                    load[i] = load[v] + load[i];
                    if (num[i]<num[v]+team[i])
                    {
                        num[i] = num[v] + team[i];
                    }
                }
            }
        }
    }
    cout << load[des] << " " << num[des];


    return 0;
}