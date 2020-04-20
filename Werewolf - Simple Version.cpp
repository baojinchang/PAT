#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n + 1);
    vector<int> flag;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i + 1];
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = i+1; j < n+1; j++)
        {
            for (int k = 1; k < n+1; k++)
            {
                if (k==i||k==j)
                {
                    if (num[k]>0)
                    {
                        flag.push_back(num[k]);
                    }
                }
                else
                {
                    if (num[k]<0)
                    {
                        flag.push_back(-num[k]);
                    }
                }
            }
            if (flag.size() == 2 && ((i == flag[0] && j != flag[1]) || (i == flag[1] && j != flag[0])||(j == flag[0] && i != flag[1]) || (j == flag[1] && i != flag[0])))
            {
                count = 1;
                break;
            }
            flag.clear();
        }
        if (count==1)
        {
            break;
        }
    }
    if (count==1)
    {
        if (flag[0]>flag[1])
        {
            cout << flag[0] << " " << flag[1];
        }
        else
        {
            cout << flag[1] << " " << flag[0];
        }
    }
    else
    {
        cout << "No Solution";
    }

    return 0;
}