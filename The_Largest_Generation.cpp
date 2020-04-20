#include<iostream>
#include<vector>

using namespace std;

struct Tree
{
    vector<int> child;
} tree[101];


int count[110] = {0};

int dfs(int v,int deep)
{

    count[deep]++;
    if (tree[v].child.size()!=0)
    {
        for (int i = 0; i < tree[v].child.size(); i++)
        {
            dfs(tree[v].child[i], deep + 1);
        }
    }

    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int temp, m;
        cin >> temp >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            tree[temp].child.push_back(a);
        }
    }
    dfs(1, 1);
    int max = 0;
    int flag;
    for (int i = 1; i < n+1; i++)
    {
        if (count[i]>max)
        {
            max = count[i];
            flag = i;
        }
        
    }
    cout << max << " " << flag;

    return 0;
}