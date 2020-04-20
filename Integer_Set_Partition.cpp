#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> number(n);
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    sort(number.begin(), number.end());
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i<n/2)
        {
            s1 += number[i];
        }
        else
        {
            s2 += number[i];
        }
    }
    if (n%2==0)
    {
        cout << 0 << " ";
    }
    else
    {
        cout << 1 << " ";
    }
    cout << s2 - s1;

    return 0;
}