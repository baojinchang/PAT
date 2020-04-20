#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int data;
    int l;
    int r;
} node[100];

int order(int number[],int v,int &i)
{
    if (node[v].l!=-1)
    {
        order(number, node[v].l,i);
    }
    node[v].data = number[i++];
    if (node[v].r!=-1)
    {
        order(number, node[v].r, i);
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].l >> node[i].r;
    }
    int number[100];
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    sort(number, number + n);
    int count = 0;
    order(number, 0, count);
    int que[100];
    int f, r;
    f = r = 0;
    que[0] = 0;
    r++;
    while (r!=f)
    {
        int temp = que[f++];
        cout << node[temp].data;
        if (f!=n)
        {
            cout << " ";
        }
        if (node[temp].l!=-1)
        {
            que[r++] = node[temp].l;
        }
        if (node[temp].r!=-1)
        {
            que[r++] = node[temp].r;
        }
        
    }

    return 0;
}

