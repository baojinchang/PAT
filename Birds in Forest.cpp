#include <iostream>

using namespace std;

int brid[10001];

int findfather(int v)
{
    int a = v;
    while (v != brid[v])
    {
        v = brid[v];
    }
    while (a != brid[a])
    {
        int z = a;
        a = brid[a];
        brid[z] = v;
    }

    return v;
}

int Union(int a, int b)
{
    int x = findfather(a);
    int y = findfather(b);
    if (x != y)
    {
        brid[x] = y;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < 10002; i++)
    {
        brid[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int a;
        cin >> a;
        if (a > sum)
        {
            sum = a;
        }
        for (int i = 1; i < k; i++)
        {
            int temp;
            cin >> temp;
            if (temp > sum)
            {
                sum = temp;
            }
            Union(a, temp);
        }
    }
    int root = 0;
    for (int i = 1; i < sum + 1; i++)
    {
        if (brid[i] == i)
        {
            root++;
        }
    }
    cout << root << " " << sum << endl;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (findfather(a) == findfather(b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}