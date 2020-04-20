#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *number = new int[n];
    int count[10001] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
        count[number[i]]++;
    }
    int i;
    for ( i = 0; i < n; i++)
    {
        if (count[number[i]]==1)
        {
            cout << number[i];
            break;
        }
    }
    if (i==n)
    {
        cout << "None";
    }

    return 0;
}