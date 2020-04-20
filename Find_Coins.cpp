#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coin(1000);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp<m)
        {
            coin[temp]++;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (coin[i]!=0)
        {
            if (m-i!=i)
            {
                if (coin[m-i]!=0)
                {
                    cout << i << " " << m - i;
                    return 0;
                }
            }
            if (m-i==i)
            {
                if (coin[i]>1)
                {
                    cout << i << " " << i;
                    return 0;
                }
            }
        }
    }
    cout << "No Solution";

    return 0;
}