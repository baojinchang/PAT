#include <iostream>
#include <string>

using namespace std;

const int INF = 10000;

struct City
{
    string name;
    int happy = 0;
};

int show(int path[],int flag,City city[])
{
    if (path[flag]!=0)
    {
        show(path, path[flag],city);
    }
    cout << "->" << city[flag].name;

    return 0;
}

int main()
{
    int n, route;
    cin >> n >> route;
    City city[200];
    cin >> city[0].name;
    for (int i = 1; i < n; i++)
    {
        cin >> city[i].name >> city[i].happy;
    }
    int load[200][200];
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            load[i][j] = INF;
        }
    }
    for (int i = 0; i < route; i++)
    {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        int flag1, flag2;
        for (int j = 0; j < n; j++)
        {
            if (city[j].name == temp1)
            {
                flag1 = j;
            }
            if (city[j].name == temp2)
            {
                flag2 = j;
            }
        }
        cin >> load[flag1][flag2];
        load[flag2][flag1] = load[flag1][flag2];
    }
    int path[200];
    int vist[200] = {0};
    int distance[200] = {0};
    distance[0] = INF;
    vist[0] = 1;
    int number[200] = {0};
    int cost[200] = {0};
    int count[200] = {0};
    int v = 0;
    for (int j = 0; j < n; j++)
    {
        if (vist[j] == 0 && load[0][j] != INF)
        {
            distance[j] = load[0][j];
            cost[j] = city[j].happy;
            number[j]++;
            count[j]++;
            path[j] = 0;
        }
        else if (load[0][j] == INF)
        {
            distance[j] = load[0][j];
            path[j] = -1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int min = INF;
        for (int j = 0; j < n; j++)
        {
            if (distance[j] < min && vist[j] == 0)
            {
                min = distance[j];
                v = j;
            }
        }
        vist[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (distance[j] > distance[v] + load[j][v] && vist[j] == 0)
            {
                distance[j] = distance[v] + load[j][v];
                cost[j] = cost[v] + city[j].happy;
                count[j] = count[v];
                number[j] = number[v] + 1;
                path[j] = v;
            }
            else if (distance[j] == distance[v] + load[j][v] && vist[j] == 0)
            {
                count[j] = count[v] + count[j];
                if (cost[j] < cost[v] + city[j].happy)
                {
                    distance[j] = distance[v] + load[j][v];
                    cost[j] = cost[v] + city[j].happy;
                    number[j] = number[v] + 1;
                    path[v] = j;
                }
                else if (cost[j] >= cost[v] + city[j].happy && cost[j] * (number[v] + 1) < (cost[v] + city[j].happy) * number[j])
                {
                    distance[j] = distance[v] + load[j][v];
                    cost[j] = cost[v] + city[j].happy;
                    number[j] = number[v] + 1;
                    path[v] = j;
                }
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (city[i].name == "ROM")
        {
            flag = i;
            break;
        }
    }
    cout << count[flag] << " " << distance[flag] << " " << cost[flag] << " " << cost[flag] / number[flag] << endl;
    cout << city[0].name;
    show(path, flag, city);

    return 0;
}