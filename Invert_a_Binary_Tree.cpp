#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int l = -1;
    int r = -1;
} node[10];

int inorder(int &count, int v)
{
    if (node[v].l != -1)
    {
        inorder(count, node[v].l);
    }
    count++;
    if (node[v].r != -1)
    {
        inorder(count, node[v].r);
    }

    return 0;
}

int n;

int order(int &count, int v)
{
    if (node[v].r != -1)
    {
        order(count, node[v].r);
    }
    count++;
    cout << v;
    if (count != n)
    {
        cout << " ";
    }
    if (node[v].l != -1)
    {
        order(count, node[v].l);
    }

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1[0] != '-')
        {
            node[i].l = str1[0] - '0';
        }
        if (str2[0] != '-')
        {
            node[i].r = str2[0] - '0';
        }
    }
    int v;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        inorder(count, i);
        if (count == n)
        {
            v = i;
            break;
        }
    }
    int que[10];
    int f, r;
    int count = 1;
    f = r = 0;
    que[r++] = v;
    while (f != r)
    {
        int temp = que[f++];
        cout << temp;
        if (count != n)
        {
            cout << " ";
        }
        count++;
        if (node[temp].r != -1)
        {
            que[r++] = node[temp].r;
        }
        if (node[temp].l != -1)
        {
            que[r++] = node[temp].l;
        }
    }
    cout << endl;
    count = 0;
    order(count, v);

    return 0;
}