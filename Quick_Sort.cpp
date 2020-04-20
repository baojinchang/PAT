#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int num1[100000], num2[100000], flag[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
        num2[i] = num1[i];
    }
    sort(num2, num2 + n);
    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (num1[i]==num2[i])
        {
            if (num1[i]>max)
            {
                flag[count++] = num1[i];
                max = num1[i];
            }
        }
        if (num1[i]>max)
        {
            max = num1[i];
        } 
    }
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << flag[i];
        if (i!=count-1)
        {
            cout << " ";
        }
    }
    if (count==0)
    {
        cout << endl;
    }
    

    return 0;
}