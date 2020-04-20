#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> flag(n+1);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp>0&&temp<=n)
        {
            flag[temp] = 1;
        }
    }
    int i;
    for ( i = 1; i < n+1; i++)
    {
        if (flag[i]==0)
        {
            cout << i;
            break;
        }
    }
    if (i==n+1)
    {
        cout << i;
    }

    return 0;
}