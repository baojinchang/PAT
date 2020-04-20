#include <iostream>
#include <vector>
#include<map>

using namespace std;

int m;
vector<int> in;
vector<int> pre;
map<int, int> target;

void find(int x,int y,int p,int q,int root)
{
    int temp = target[pre[root]] - 1;
    if (temp==x)
    {
        cout << in[x] << " is an ancestor of " << in[y] << "." << endl;
        return;
    }
    if (temp==y)
    {
        cout << in[y] << " is an ancestor of " << in[x] << "." << endl;
        return;
    }
    if ((temp-x)*(temp-y)<0)
    {
        cout << "LCA of " << in[x] << " and " << in[y] << " is " << in[temp] << "." << endl;
        return;
    }
    if (temp>y&&temp>x)
    {
        find(x, y, p, temp, root + 1);
    }
    else
    {
        find(x, y, temp + 1, q, temp - p + root + 1);
    }
}


int main()
{
    int n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        in.push_back(temp);
        target[temp] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        pre.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int p, q;
        p = target[x] - 1;
        q = target[y] - 1;
        if (p == -1 && q!=-1)
        {
            cout << "ERROR: " << x <<" is not found."<< endl;
        }
        else if (p!=-1&&q==-1)
        {
            cout << "ERROR: " << y <<" is not found."<< endl;
        }
        else if (p==-1&&q==-1)
        {
            cout << "ERROR: " << x << " and " << y << " are not found." << endl;
        }
        else
        {
            find(p, q, 0, m, 0);
        }
    }

    return 0;
}