#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int edage[210][210] = {{0}};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        v.push_back(temp1);
        v.push_back(temp2);
        edage[temp1][temp2] = edage[temp2][temp1] = 1;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i]==v[i-1])
        {
            v.erase(v.begin() + i);
            i--;
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        vector<int> num;
        for (int i = 0; i < temp; i++)
        {
            int a;
            cin>>a;
            num.push_back(a);
        }
        int flag = 0;
        for (int i = 0; i < num.size(); i++)
        {
            for (int j = i+1; j < num.size(); j++)
            {
                if (edage[num[i]][num[j]]==0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==1)
            {
                break;
            }
        }
        if (flag==1)
        {
            cout << "Not a Clique" << endl;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < v.size(); i++)
            {
                int j;
                for ( j = 0; j < num.size(); j++)
                {

                    if (v[i]==num[j]||edage[v[i]][num[j]]==0)
                    {
                        break;
                    }
                }
                if (j==num.size())
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==1)
            {
                cout << "Not Maximal" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    

    return 0;
}