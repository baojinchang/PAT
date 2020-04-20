#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num1(n);
    vector<int> num2(n);
    int num3[100];
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
        num3[i] = num1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num2[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (num1[j] < num1[j - 1])
            {
                int temp = num1[j];
                num1[j] = num1[j - 1];
                num1[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
        int j;
        for (j = 0; j < n; j++)
        {
            if (num1[j] != num2[j])
            {
                break;
            }
        }
        if (j == n)
        {
            cout << "Insertion Sort" << endl;
            i++;
            for (int j = i; j > 0; j--)
            {
                if (num1[j] < num1[j - 1])
                {
                    int temp = num1[j];
                    num1[j] = num1[j - 1];
                    num1[j - 1] = temp;
                }
                else
                {
                    break;
                }
            }
            for (int j = 0; j < n; j++)
            {
                cout << num1[j];
                if (j != n - 1)
                {
                    cout << " ";
                }
            }
            return 0;
        }
    }
    cout << "Merge Sort" << endl;
    int keep = 2;
    while (keep <= n)
    {
        for (int i = 0; i < n; i = i + keep)
        {
            if (i + keep <= n)
            {
                sort(num3 + i, num3 + i + keep);
            }
            else
            {
                sort(num3 + i, num3 + n);
            }
        }
        int j;
        for (j = 0; j < n; j++)
        {
            if (num2[j] != num3[j])
            {
                break;
            }
        }
        if (j == n)
        {
            keep = keep * 2;
            for (int i = 0; i < n; i = i + keep)
            {
                if (i + keep <= n)
                {
                    sort(num3 + i, num3 + i + keep);
                }
                else
                {
                    sort(num3 + i, num3 + n);
                }
            }
            for (int i = 0; i < n; i++)
            {
                cout << num3[i];
                if (i != n - 1)
                {
                    cout << " ";
                }
            }
            return 0;
        }
        keep = keep * 2;
    }

    return 0;
}