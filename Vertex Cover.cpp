#include <iostream>
#include <vector>

using namespace std;

struct Edage
{
    vector<int> v;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edage> edage(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edage[x].v.push_back(i);
        edage[y].v.push_back(i);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int flag[10000] = {0};
        int temp;
        cin >> temp;
        for (int i = 0; i < temp; i++)
        {
            int x;
            cin >> x;
            for (int i = 0; i < edage[x].v.size(); i++)
            {
                flag[edage[x].v[i]] = 1;
            }
        }
        int j;
        for ( j = 0; j < m; j++)
        {
            if (flag[j]==0)
            {
                break;
            }
        }
        if(j==m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}