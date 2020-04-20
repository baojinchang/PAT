#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    int l = -1;
    int r = -1;
} node[21];

int order(int v, int &sum)
{
    sum++;
    if (node[v].l != -1)
    {
        order(node[v].l, sum);
    }
    if (node[v].r != -1)
    {
        order(node[v].r, sum);
    }

    return 0;
}

int flag;

int inorder(int v)
{
    if (node[v].l == -1 && node[v].r != -1)
    {
        if (v != flag)
        {
            cout << "(";
        }
    }

    if (node[v].l != -1)
    {
        if (v != flag)
        {
            cout << "(";
        }
        inorder(node[v].l);
    }
    cout << node[v].data;
    if (node[v].r != -1)
    {
        inorder(node[v].r);
        if (v != flag)
        {
            cout << ")";
        }
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> node[i].data >> node[i].l >> node[i].r;
    }
    for (int i = 1; i < n + 1; i++)
    {
        int count = 0;
        order(i, count);
        if (count == n)
        {
            flag = i;
            break;
        }
    }
    inorder(flag);

    return 0;
}