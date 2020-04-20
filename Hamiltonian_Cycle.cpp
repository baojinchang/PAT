#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int edage[210][201] = {{0}};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        edage[temp1][temp2] = edage[temp2][temp1] = 1;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        vector<int> num(temp);
        for (int i = 0; i < temp; i++)
        {
            cin >> num[i];
        }
        int flag = 0;
        for (int i = 0; i < temp-1; i++)
        {
            int j;
            for ( j = 0; j < i; j++)
            {
                if (num[i]==num[j])
                {
                    break;
                }
            }
            if (j!=i)
            {
                flag = 1;
                break;
            }
        }
        if (num[0] != num[temp - 1] || temp != n + 1 || flag==1)
        {
            cout << "NO" << endl;
        }
        else 
        {
            int j;
            for (j = 0; j < temp-1; j++)
            {
                if (edage[num[j]][num[j+1]]==0)
                {
                    break;
                }
            }
            if (j==temp-1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    

    return 0;
}