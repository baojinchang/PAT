#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Out
{
    int id;
    int num;
    double sets;
    double area;
};

vector<int> family(10000);

int find(int v)
{
    while (v != family[v])
    {
        v = family[v];
    }
    return v;
}

void Union(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x > y)
    {
        family[x] = y;
    }
    else
    {
        family[y] = x;
    }
}

vector<int> num(10000);
vector<int> sets(10000);
vector<int> area(10000);

bool cmp(Out a, Out b)
{
    if (a.area == b.area)
    {
        return a.id < b.id;
    }
    return a.area > b.area;
}

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        family[i] = i;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        int father, mother;
        cin >> father >> mother;
        if (father != -1)
            Union(temp, father);
        if (mother != -1)
            Union(temp, mother);
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            Union(temp, a);
        }
        int x, y;
        cin >> x >> y;
        sets[temp] = x;
        area[temp] = y;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (find(i) != i)
        {
            sets[find(i)] += sets[i];
            area[find(i)] += area[i];
        }
        num[find(i)]++;
    }
    vector<Out> out;
    for (int i = 0; i < 10000; i++)
    {
        if (find(i) == i && sets[find(i)] != 0)
        {
            Out temp;
            temp.id = i;
            temp.num = num[i];
            temp.sets = double(sets[i]) / num[i];
            temp.area = double(area[i]) / num[i];
            out.push_back(temp);
        }
    }
    sort(out.begin(), out.end(), cmp);
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); i++)
    {
        printf("%04d %d %0.3f %0.3f\n", out[i].id, out[i].num, out[i].sets, out[i].area);
    }

    return 0;
}