#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<vector<string>, int> edage;
map<string, int> vist;
set<string> name;
vector<string> id;
map<string, int> wegt;

struct Out
{
    int flag;
    string name;
};

void dfs(string v)
{
    id.push_back(v);
    vist[v] = 1;
    for (set<string>::iterator it = name.begin(); it != name.end(); it++)
    {
        if (vist[*it] == 0 && edage[{v, *it}] != 0)
        {
            dfs(*it);
        }
    }
}

bool cmp(Out a, Out b)
{
    return a.name < b.name;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<Out> flag;
    for (int i = 0; i < n; i++)
    {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        cin >> edage[{temp1, temp2}];
        name.insert(temp1);
        name.insert(temp2);
    }
    for (set<string>::iterator i = name.begin(); i != name.end(); i++)
    {
        if (vist[*i] == 0)
        {
            dfs(*i);
            if (id.size() > 2)
            {
                int max = 0;
                int v;
                int sum = 0;
                for (int i = 0; i < id.size(); i++)
                {
                    for (int j = 0; j < id.size(); j++)
                    {
                        wegt[id[i]] += edage[{id[i], id[j]}];
                        wegt[id[i]] += edage[{id[j], id[i]}];
                    }
                }
                for (int i = 0; i < id.size(); i++)
                {
                    sum += wegt[id[i]];
                    if (wegt[id[i]]>max)
                    {
                        max = wegt[id[i]];
                        v = i;
                    }
                }
                if (sum/2>k)
                {
                    Out temp;
                    temp.flag = id.size();
                    temp.name = id[v];
                    flag.push_back(temp);
                }
            }
            id.clear();
        }
    }
    sort(flag.begin(), flag.end(), cmp);
    cout << flag.size() << endl;
    for (int i = 0; i < flag.size(); i++)
    {
        cout << flag[i].name << " " << flag[i].flag << endl;
    }

    return 0;
}