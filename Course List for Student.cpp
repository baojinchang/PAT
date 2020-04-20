#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<string, vector<int>> num;
    for (int i = 0; i < m; i++)
    {
        int course, temp;
        cin >> course >> temp;
        for (int i = 0; i < temp; i++)
        {
            string x;
            cin >> x;
            num[x].push_back(course);
        }
    }
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        cout << temp << " ";
        sort(num[temp].begin(), num[temp].end());
        cout << num[temp].size();
        for (int i = 0; i < num[temp].size(); i++)
        {
            cout << " " << num[temp][i];
        }
        cout << endl;
    }
    

    return 0;
}