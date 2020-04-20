#include<iostream>
#include<vector>

using namespace std;

struct Flag
{
    vector<int> num;
};


int main()
{
    int n, m;
    cin >> n >> m;
    Flag flag[100000];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        flag[x].num.push_back(y);
        flag[y].num.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        vector<int> num(k);
        for (int i = 0; i < k; i++)
        {
            cin >> num[i];
        }
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            int temp = num[i];
            if (flag[temp].num.size()!=0)
            {
                for (int j = i+1; j < k; j++)
                {
                    for (int p = 0; p < flag[temp].num.size(); p++)
                    {
                        if (num[j]==flag[temp].num[p])
                        {
                            count = 1;
                            break;
                        }
                    }
                    if (count==1)
                    {
                        break;
                    }
                }
            }
            if (count==1)
            {
                break;
            }
        }
        if (count==0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}