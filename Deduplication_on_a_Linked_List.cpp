#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    int next;
} node[100000];

int main()
{
    int n, start;
    cin >> start >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cin >> node[temp].data >> node[temp].next;
    }
    int list[100000];
    int a = start;
    int flag[100000] = {0};
    int count = 0;
    while (start != -1)
    {
        int temp = node[start].data;
        if (flag[abs(temp)] == 0)
        {
            if (start == a)
            {
                printf("%05d %d ", start, node[start].data);
            }
            else
            {
                printf("%05d\n%05d %d ", start, start, node[start].data);
            }
            flag[abs(temp)] = 1;
        }
        else
        {
            list[count++] = start;
        }
        start = node[start].next;
    }
    cout << -1 << endl;
    for (int i = 0; i < count; i++)
    {
        if (i==0)
        {
            printf("%05d %d ", list[i], node[list[i]].data);
        }
        else
        {
            printf("%05d\n%05d %d ", list[i], list[i], node[list[i]].data);
        }
    }
    if (count!=0)
    {
        cout << -1;
    }

    return 0;
}