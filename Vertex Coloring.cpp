#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edage
{
    int x;
    int y;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edage> edage(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edage[i].x = x;
        edage[i].y = y;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            if (num[edage[i].x]==num[edage[i].y])
            {
                flag = 1;
                break;
            }
        }
        if (flag==1)
        {
            cout << "No" << endl;
        }
        else
        {
            sort(num.begin(), num.end());
            int count = 1;
            for (int i = 1; i < n; i++)
            {
                if (num[i]!=num[i-1])
                {
                    count++;
                }
            }
            cout << count << "-coloring" << endl;
        }
    }
    

    return 0;
}