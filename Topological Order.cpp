#include<iostream>
#include<vector>

using namespace std;

int edage[1010][1010] = {{0}};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> out;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edage[x][y] = 1;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        vector<int> target(n + 1);
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (flag==0)
            {
                for (int i = 1; i < n+1; i++)
                {
                    if (target[i]==0&&edage[i][temp]==1)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            target[temp] = 1;
        }
        if (flag==1)
        {
            out.push_back(i);
        }
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i];
        if (i!=out.size()-1)
        {
            cout << " ";
        }
    }
    

    return 0;
}