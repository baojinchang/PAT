#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    int num[100010];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num+n, cmp);
    int i;
    for ( i = 0; i < n; i++)
    {
        if (num[i]<=i+1)
        {
            break;
        }
    }
    cout << i;

    return 0;
}