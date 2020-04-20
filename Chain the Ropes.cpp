#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    double sum = num[0];
    for (int i = 1; i < n; i++)
    {
        sum = sum / 2 + num[i] / 2;
    }
    cout << int(sum);

    return 0;
}