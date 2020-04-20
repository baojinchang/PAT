#include <iostream>

using namespace std;

bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int order[10000] = {0};
    int flag[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        order[temp] = i + 1;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        printf("%04d", temp);
        if (order[temp] == 0)
        {
            cout  << ": Are you kidding?" << endl;
        }
        else if (flag[temp] == 1)
        {
            cout  << ": Checked" << endl;
        }
        else
        {
            flag[temp] = 1;
            if (order[temp] == 1)
            {
                cout  << ": Mystery Award" << endl;
            }
            else
            {
                if (isprime(order[temp]))
                {
                    cout  << ": Minion" << endl;
                }
                else
                {
                    cout  << ": Chocolate" << endl;
                }
            }
        }
    }

    return 0;
}