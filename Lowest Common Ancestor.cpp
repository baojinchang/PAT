#include <iostream>
#include <map>
#include <vector>

using namespace std;

int m;
vector<int> pre;
map<int, int> target;

int main()
{
    int n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        pre.push_back(temp);
        target[temp] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int p, q;
        p = target[x] - 1;
        q = target[y] - 1;
        if (p == -1 && q != -1)
        {
            cout << "ERROR: " << x << " is not found." << endl;
        }
        else if (p != -1 && q == -1)
        {
            cout << "ERROR: " << y << " is not found." << endl;
        }
        else if (p == -1 && q == -1)
        {
            cout << "ERROR: " << x << " and " << y << " are not found." << endl;
        }
        else
        {
            int i;
            for ( i = 0; i < q && i < p; i++)
            {
                if ((pre[i]-x)*(pre[i]-y)<0)
                {
                    cout << "LCA of " << pre[p] << " and " << pre[q] << " is " << pre[i] << "." << endl;
                    break;
                }
            }
            if (i==p)
            {
                cout << pre[i] << " is an ancestor of " << pre[q] << "." << endl;
            }
            else if(i==q)
            {
                cout << pre[i] << " is an ancestor of " << pre[p] << "." << endl;
            }
        }
    }

    return 0;
}