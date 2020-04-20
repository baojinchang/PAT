#include <iostream>

using namespace std;

struct Node
{
    int data;
    int address;
    int next;
} node[100000];

int main()
{
    int start, n, k;
    cin >> start >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cin >> node[temp].data >> node[temp].next;
    }
    int flag = 0;
    int p = start;
    while (p != -1)
    {
        if (node[p].data < 0 && flag == 0)
        {
            printf("%05d %d ", p, node[p].data);
            flag = 1;
        }
        else if (node[p].data < 0 && flag == 1)
        {
            printf("%05d\n%05d %d ", p, p, node[p].data);
        }
        p = node[p].next;
    }
    p = start;
    while (p != -1)
    {
        if (node[p].data >= 0 && node[p].data <= k && flag == 0)
        {
            printf("%05d %d ", p, node[p].data);
            flag = 1;
        }
        else if (node[p].data >= 0 && node[p].data <= k && flag == 1)
        {
            printf("%05d\n%05d %d ", p, p, node[p].data);
        }
        p = node[p].next;
    }
    p = start;
    while (p!=-1)
    {
        if (node[p].data>k && flag == 0)
        {
            printf("%05d %d ", p, node[p].data);
            flag = 1;
        }
        else if (node[p].data>k && flag == 1)
        {
            printf("%05d\n%05d %d ", p, p, node[p].data);
        }
        p = node[p].next;
    }
    cout << -1;

    return 0;
}