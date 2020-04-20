#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    vector<int> child;
};

Node node[100000];

int mi = 100000;
int fla = 0;

int dfs(int deep, int flag)
{
    for (int i = 0; i < node[flag].child.size(); i++)
    {
        dfs(deep + 1, node[flag].child[i]);
    }
    if (node[flag].child.size() == 0)
    {
        if (mi > deep)
        {
            mi = deep;
            fla = 0;
        }
        if (mi == deep)
        {
            fla++;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    double p, r;
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int a;
            cin >> a;
            node[i].child.push_back(a);
        }
        
    }
    dfs(0, 0);

    cout << setiosflags(ios::fixed) << setprecision(4) << p * pow((1 + r / 100), mi) << " " << setiosflags(ios::fixed) << setprecision(0) << fla;

    return 0;
}