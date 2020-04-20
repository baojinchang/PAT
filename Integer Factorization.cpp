#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int k;
int n, p;
vector<int> num;
vector<int> out;
int MAX = 0;

int ans[400] = {0};

int dfs(int v, int sum,int deep,int ssum)
{
    ans[deep] = num[v];
    sum += pow(num[v], p);
    if(sum>n)
        return 0;
    deep++;
    if(deep>k)
        return 0;
    ssum += num[v];
    if(sum==n&&deep==k)
    {
        if(ssum>MAX)
        {
            MAX = ssum;
            out.clear();
            for (int i = 0; i < k; i++)
            {
                out.push_back(ans[i]);
            }
        }
        return 0;
    }
    for (int i = v; i > -1; i--)
    {
        dfs(i, sum, deep, ssum);
    }
    
    return 0;
}

int main()
{
    cin >> n >> k >> p;
    for (int i = 1; pow(i, p) <= n; i++)
    {
        num.push_back(i);
    }
    for (int i = num.size()-1; i > -1; i--)
    {
        dfs(i, 0, 0, 0);
    }
    if (out.size() != k)
    {
        cout << "Impossible";
    }
    else
    {
        cout << n << " = ";
        for (int i = 0; i < out.size(); i++)
        {
            cout << out[i] << "^" << p;
            if (i != out.size() - 1)
            {
                cout << " + ";
            }
        }
    }

    return 0;
}