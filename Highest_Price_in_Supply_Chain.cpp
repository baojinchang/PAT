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

int ma = 0;
int fla = 0;

int dfs(int deep,int flag)
{
    for (int i = 0; i < node[flag].child.size(); i++)
    {
        dfs(deep + 1, node[flag].child[i]);
    }
    if (ma<deep)
    {
        ma = deep;
        fla = 0;
    }
    if (ma==deep)
    {
        fla++;
    }
    

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    double p, r;
    cin >> n >> p >> r;
    int flag;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == -1)
        {
            flag = i;
        }
        else
        {
            node[temp].child.push_back(i);
        }
    }
    dfs(0, flag);

    cout << setiosflags(ios::fixed) << setprecision(2) << p * pow((1 + r / 100), ma) << " " << setiosflags(ios::fixed) << setprecision(0) << fla;

    return 0;
}