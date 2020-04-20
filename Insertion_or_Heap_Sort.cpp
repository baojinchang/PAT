#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num1(n);
    vector<int> num2(n);
    vector<int> num3(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
        num3[i] = num1[i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num2[i] = temp;
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
    cout << "Heap Sort" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 2) / 2; j >= i; j--)
        {
            int a = num3[j * 2 + 1] > num3[j * 2 + 2] ? j * 2 + 1 : j * 2 + 2;
            if (num3[j] < num3[a])
            {
                int temp = num3[j];
                num3[j] = num3[a];
                num3[a] = temp;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (num3[j] != num2[j])
            {
                break;
            }
        }
        int temp = num3[i];
        num3[i] = num3[0];
        num3[0] = temp;
        if (j == n)
        {
            i--;
            int p = 0;
            while (p * 2 + 1 <= i)
            {
                int temp;
                if (p * 2 + 2 <= i)
                {
                    temp = num3[p * 2 + 1] > num3[p * 2 + 2] ? p * 2 + 1 : p * 2 + 2;
                }
                else
                {
                    temp = p * 2 + 1;
                }
                if (num3[temp] > num3[p])
                {
                    int a = num3[p];
                    num3[p] = num3[temp];
                    num3[temp] = a;
                    p = temp;
                }
                else
                {
                    break;
                }
            }
            for (int j = 0; j < n; j++)
            {
                cout << num3[j];
                if (j != n - 1)
                {
                    cout << " ";
                }
            }

            return 0;
        }
        int p = 0;
        int k = i - 1;
        while (p * 2 + 1 <= k)
        {
            int temp;
            if (p * 2 + 2 <= k)
            {
                temp = num3[p * 2 + 1] > num3[p * 2 + 2] ? p * 2 + 1 : p * 2 + 2;
            }
            else
            {
                temp = p * 2 + 1;
            }
            if (num3[temp] > num3[p])
            {
                int a = num3[p];
                num3[p] = num3[temp];
                num3[temp] = a;
                p = temp;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}