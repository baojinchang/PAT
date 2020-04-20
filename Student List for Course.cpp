#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<int, vector<string>> num;
    for (int i = 0; i < n; i++)
    {
        string name;
        int k;
        cin >> name >> k;
        for (int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            num[temp].push_back(name);
        }
    }
    for (int i = 1; i < m+1; i++)
    {
        printf("%d %d\n", i, num[i].size());
        sort(num[i].begin(), num[i].end());
        for (int j = 0; j < num[i].size(); j++)
        {
            printf("%s\n", num[i][j].c_str());
        }
    }

    return 0;
}