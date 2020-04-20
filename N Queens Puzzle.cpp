#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> num(k);
        for (int i = 0; i < k; i++)
        {
            cin >> num[i];
        }
        int l;
        for ( l = 1; l < k; l++)
        {
            int j;
            for ( j = 0; j < l; j++)
            {
                if (num[j]==num[l]||num[l]-num[j]==l-j||num[l]-num[j]==j-l)
                {
                    break;
                }
            }
            if (j!=l)
            {
                break;
            }
        }
        if (l==k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}