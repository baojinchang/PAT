#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct People
{
    string name;
    int age;
    int worth;
};

struct Query
{
    int m;
    int min;
    int max;
};

bool cmp(People a,People b)
{
    if (a.worth==b.worth)
    {
        if (a.age==b.age)
        {
            return a.name < b.name;
        }
        else
        {
            return a.age < b.age;
        }
    }
    else
    {
        return a.worth > b.worth;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    People people[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> people[i].name >> people[i].age >> people[i].worth;
    }
    Query query[1001];
    for (int i = 0; i < k; i++)
    {
        cin >> query[i].m >> query[i].min >> query[i].max;
    }
    sort(people, people + n, cmp);
    for (int i = 0; i < k; i++)
    {
        cout << "Case #" << i + 1 << ":" << endl;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (count<query[i].m&&people[j].age>=query[i].min&&people[j].age<=query[i].max)
            {
                cout << people[j].name << " " << people[j].age << " " << people[j].worth << endl;
                count++;
            }
        } 
        if (count==0)
        {
            cout << "None" << endl;
        }
    }

    return 0;
}