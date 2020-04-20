#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Record
{
    string id;
    string name;
    int grade;
};

int c;

bool cmp(Record a, Record b)
{
    if (c == 1)
    {
        return a.id < b.id;
    }
    else if (c == 2)
    {
        if (a.name == b.name)
        {
            return a.id < b.id;
        }
        else
        {
            return a.name < b.name;
        }
    }
    else
    {
        if (a.grade == b.grade)
        {
            return a.id < b.id;
        }
        else
        {
            return a.grade < b.grade;
        }
    }
}

int main()
{
    int n;
    Record record[100000];
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        cin >> record[i].id >> record[i].name >> record[i].grade;
    }
    sort(record, record+n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %d\n", record[i].id.c_str(), record[i].name.c_str(), record[i].grade);
    }

    return 0;
}