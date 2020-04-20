#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> num(1010);
vector<int> hobby(1010);

int find(int v)
{
    while (hobby[v]!=v)
    {
        v = hobby[v];
    }
    return v;
}

void Union(int x,int y)
{
    int a = find(x);
    int b = find(y);
    if (a!=b)
    {
        hobby[b] = a;
    }
}

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    for (int i = 0; i < 1010; i++)
    {
        hobby[i] = i;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, a;
        scanf("%d: %d", &k, &a);
        num[find(a)]++;
        for (int i = 1; i < k; i++)
        {
            int b;
            cin >> b;
            num[find(a)] += num[find(b)];
            Union(a, b);
        }
    }
    vector<int> flag;
    for (int i = 0; i < 1010; i++)
    {
        if (find(i)==i&&num[find(i)]!=0)
        {
            flag.push_back(num[find(i)]);
        }
    }
    cout << flag.size() << endl;
    sort(flag.begin(), flag.end(), cmp);
    for (int i = 0; i < flag.size(); i++)
    {
        cout << flag[i];
        if (i!=flag.size()-1)
        {
            cout << " ";
        }
        
    }
    

    return 0;
}