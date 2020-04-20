#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Test
{
    string name;
    int loc;
    int grade;
};

struct Rank
{
    int num = 0;
    int loc = 1;
    int grade;
};


bool cmp(Test a,Test b)
{
    if (a.grade==b.grade)
    {
        return a.name < b.name;
    }
    return a.grade > b.grade;
}

int main()
{
    int n;
    cin >> n;
    vector<Test> test;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            Test temp;
            cin >> temp.name >> temp.grade;
            temp.loc = i + 1;
            test.push_back(temp);
        }
    }
    sort(test.begin(), test.end(), cmp);
    cout << test.size() << endl;
    vector<Rank> rank(n + 1);
    int count = 1;
    for (int i = 0; i < test.size(); i++)
    {
        int temp = test[i].loc;
        cout << test[i].name << " ";
        if (i==0)
        {
            cout << count << " ";
        }
        else
        {
            if (test[i].grade==test[i-1].grade)
            {
                cout << count << " ";
            }
            else
            {
                cout << i + 1 << " ";
                count = i + 1;
            }
        }
        cout << temp << " ";
        if (rank[temp].num==0)
        {
            cout << rank[temp].num + 1 << endl;
            rank[temp].num++;
            rank[temp].loc = 1;
            rank[temp].grade = test[i].grade;
        }
        else if (rank[temp].grade==test[i].grade)
        {
            cout << rank[temp].loc << endl;
            rank[temp].num++;
        }
        else
        {
            cout << rank[temp].num + 1 << endl;
            rank[temp].num++;
            rank[temp].loc = rank[temp].num;
            rank[temp].grade = test[i].grade;
        }
    }
    

    return 0;
}