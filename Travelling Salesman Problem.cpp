#include <iostream>
#include <vector>

using namespace std;

int edage[210][210] = {{0}};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int temp;
        cin >> temp;
        edage[x][y] = edage[y][x] = temp;
    }
    int k;
    cin >> k;
    int min = 10000;
    int v = 0;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        vector<int> num(temp);
        vector<int> tar(n + 1);
        for (int i = 0; i < temp; i++)
        {
            cin >> num[i];
            tar[num[i]]++;
        }
        int sum = 0;
        int flag = 0;
        for (int i = 1; i < temp; i++)
        {
            if (edage[num[i]][num[i - 1]] == 0)
            {
                flag = -1;
                break;
            }
            else
            {
                sum += edage[num[i]][num[i - 1]];
            }
        }
        if (flag == -1)
        {
            cout << "Path " << i + 1 << ": NA (Not a TS cycle)" << endl;
        }
        else
        {
            for (int i = 1; i < n + 1; i++)
            {
                if (tar[i]==0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0 && num[0] == num[temp - 1]&&temp==n+1)
            {
                if (sum < min)
                {
                    min = sum;
                    v = i + 1;
                }
                cout << "Path " << i + 1 << ": " << sum << " (TS simple cycle)" << endl;
            }
            else if (flag==0&&temp>n+1&&num[0]==num[temp-1])
            {
                if (sum < min)
                {
                    min = sum;
                    v = i + 1;
                }
                cout << "Path " << i + 1 << ": " << sum << " (TS cycle)" << endl;
            }
            else
            {
                cout << "Path " << i + 1 << ": " << sum << " (Not a TS cycle)" << endl;
            }
        }
    }
    cout << "Shortest Dist(" << v << ") = " << min << endl;

    return 0;
}