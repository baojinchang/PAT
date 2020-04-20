#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Node
{
    int l = -1;
    int r = -1;
} node[20];

int order(int v,int &count)
{
    count++;
    if (node[v].l!=-1)
    {
        order(node[v].l, count);
    }
    if (node[v].r!=-1)
    {
        order(node[v].r, count);
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1[0]!='-')
        {
            int a=0;
            for (int i = 0; i < str1.size(); i++)
            {
                a += (str1[i] - '0') * pow(10, str1.size() - 1 - i);
            }
            node[i].l = a;
        }
        if (str2[0]!='-')
        {
            int a=0;
            for (int i = 0; i < str2.size(); i++)
            {
                a += (str2[i] - '0') * pow(10, str2.size() - 1 - i);
            }
            node[i].r = a;
        }
    }
    int flag;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        order(i, count);
        if (count==n)
        {
            flag = i;
            break;
        }
    }
    int f = 0, r = 0;
    int que[30];
    que[r++] = flag;
    while (r!=f)
    {
        int temp = que[f];
        if (f*2+1<n)
        {
            if (node[temp].l!=-1)
            {
                que[r++] = node[temp].l;
            }
            else
            {
                break;
            }
        }
        if (f*2+2<n)
        {
            if (node[temp].r!=-1)
            {
                que[r++] = node[temp].r;
            }
            else
            {
                break;
            }
        }
        f++;
    }
    if (r==f)
    {
        cout << "YES " << que[f - 1];
    }
    else
    {
        cout << "NO " << flag;
    }

    return 0;
}
