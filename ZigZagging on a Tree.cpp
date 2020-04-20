#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    int deep;
} node[50];

int n;
int in[50];
int post[50];
int count = 0;

int build(int p, int q, int deep)
{
    if (p + 1 == q)
    {
        node[count].data = in[p];
        node[count].deep = deep;
        count++;
        return 0;
    }
    int temp = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = p; j < q; j++)
        {
            if (post[i] == in[j])
            {
                temp = j;
                break;
            }
        }
        if (post[i] == in[temp]&&temp!=-1)
        {
            break;
        }
    }
    node[count].data = in[temp];
    node[count].deep = deep;
    count++;
    if (p < temp)
    {
        build(p, temp, deep + 1);
    }
    if (temp + 1 < q)
    {
        build(temp + 1, q, deep + 1);
    }

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    build(0, n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j>i; j--)
        {
            if (node[j].deep < node[j-1].deep)
            {
                Node temp = node[j-1];
                node[j-1] = node[j];
                node[j] = temp;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        for (j; j < n; j++)
        {
            if (node[j].deep != node[i].deep)
            {
                break;
            }
        }
        int temp = j - 1;
        if (node[i].deep % 2 == 0)
        {
            for (j=j-1; j >= i; j--)
            {
                cout << node[j].data;
                sum++;
                if (sum != n)
                {
                    cout << " ";
                }
            }
        }
        else
        {
            for (i; i < j; i++)
            {
                cout << node[i].data;
                sum++;
                if (sum != n)
                {
                    cout << " ";
                }
            }
        }
        i = temp;
    }

    return 0;
}