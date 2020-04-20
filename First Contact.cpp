#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Out
{
    string a, b;
};

bool cmp(Out a, Out b)
{
    if (a.a == b.a)
    {
        return a.b < b.b;
    }
    return a.a < b.a;
}

int main()
{
    map<vector<string>, bool> target;
    map<string, vector<string>> fri;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        target[{temp1, temp2}] = true;
        target[{temp2, temp1}] = true;
        if (temp1.size() == temp2.size())
        {
            fri[temp1].push_back(temp2);
            fri[temp2].push_back(temp1);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string x, y;
        cin >> x >> y;
        vector<Out> out;
        for (int i = 0; i < fri[x].size(); i++)
        {
            if (fri[x][i] != y)
            {
                for (int j = 0; j < fri[y].size(); j++)
                {
                    if (fri[y][j] != x)
                    {
                        if (target[{fri[x][i], fri[y][j]}])
                        {
                            Out temp;
                            temp.a = fri[x][i];
                            temp.b = fri[y][j];
                            if (temp.a.size() == 5)
                            {
                                temp.a.erase(temp.a.begin());
                            }
                            if (temp.b.size() == 5)
                            {
                                temp.b.erase(temp.b.begin());
                            }
                            out.push_back(temp);
                        }
                    }
                }
            }
        }
        printf("%d\n", out.size());
        sort(out.begin(), out.end(), cmp);
        for (int i = 0; i < out.size(); i++)
        {
            printf("%s %s\n", out[i].a.c_str(), out[i].b.c_str());
        }
    }

    return 0;
}