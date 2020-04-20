#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int people[100010];
    for (int i = 0; i < 100010; i++)
    {
        people[i] = -1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        people[temp1] = temp2;
        people[temp2] = temp1;
    }
    int k;
    cin >> k;
    vector<int> num;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    for (int i = 0; i < k; i++)
    {
        if (people[num[i]] != -1)
        {
            int temp = people[num[i]];
            for (int j = 0; j < k; j++)
            {
                if (num[j] == temp)
                {
                    num.erase(num.begin() + i);
                    i--;
                    if (j<i)
                    {
                        num.erase(num.begin() + j);
                        i--;
                    }
                    else
                    {
                        num.erase(num.begin() + j - 1);
                    }
                    break;
                }
            }
        }
    }
    cout << num.size() << endl;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        printf("%05d", num[i]);
        if (i != num.size() - 1)
        {
            cout << " ";
        }
    }

    return 0;
}