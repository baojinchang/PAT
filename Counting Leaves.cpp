#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    vector<int> child;
    int deep = 1;
} node[100];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp, k;
        cin >> temp >> k;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            node[temp].child.push_back(x);
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < node[i].child.size(); j++)
        {
            node[node[i].child[j]].deep = node[i].deep + 1;
        }
    }
    vector<int> out(n+1);
    int count = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (node[i].child.size()==0)
        {
            out[node[i].deep]++;
            if (node[i].deep>count)
            {
                count = node[i].deep;
            }
        }
    }
    for (int i = 1; i <= count; i++)
    {
        cout << out[i];
        if (i!=count)
        {
            cout << " ";
        }
    }
    

    return 0;
}