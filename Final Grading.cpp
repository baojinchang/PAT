#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include<string>

using namespace std;

struct Grade
{
    string name;
    int gp = -1;
    int gm = -1;
    int gf = -1;
    int ave = 0;
};

bool cmp(Grade a, Grade b)
{
    if (a.ave == b.ave)
    {
        return a.name < b.name;
    }
    return a.ave > b.ave;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<string, Grade> target;
    for (int i = 0; i < n; i++)
    {
        string temp;
        int a;
        cin >> temp >> a;
        target[temp].name = temp;
        target[temp].gp = a;
    }
    for (int i = 0; i < m; i++)
    {
        string temp;
        int a;
        cin >> temp >> a;
        target[temp].name = temp;
        target[temp].gm = a;
    }
    for (int i = 0; i < k; i++)
    {
        string temp;
        int a;
        cin >> temp >> a;
        target[temp].name = temp;
        target[temp].gf = a;
    }
    vector<Grade> grade;
    for (map<string, Grade>::iterator it = target.begin(); it != target.end(); it++)
    {
        if (it->second.gp >= 200 && it->second.gf >= 60)
        {
            grade.push_back(it->second);
        }
    }
    for (int i = 0; i < grade.size(); i++)
    {
        if (grade[i].gm > grade[i].gf)
        {
            double temp = double(0.4 * grade[i].gm) + double(0.6 * grade[i].gf);
            grade[i].ave = int(round(temp));
        }
        else
        {
            grade[i].ave = grade[i].gf;
        }
    }
    sort(grade.begin(), grade.end(), cmp);
    for (int i = 0; i < grade.size(); i++)
    {
        cout << grade[i].name << " " << grade[i].gp << " " << grade[i].gm << " " << grade[i].gf << " " << grade[i].ave << endl;
    }

    return 0;
}