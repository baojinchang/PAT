#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    int p = 0, q = n;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = p; j < q; j++)
        {
            if (pre[i] == in[j])
            {
                break;
            }
        }
        if (j!=p)
        {
            q = j;
        }
        else
        {
            p++;
        }
        if (q-p==1)
        {
            cout << in[p];
            break;
        }
    }

    return 0;
}