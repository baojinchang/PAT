#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct  Student
{
    string id;
    double grade;
};


struct Rank
{
    string name;
    double total = 0;
    int num = 1;
};

bool cmp(Rank a, Rank b)
{
    if (a.total != b.total)
    {
        return a.total > b.total;
    }
    else if (a.num != b.num)
    {
        return a.num < b.num;
    }
    else
    {
        a.name < b.name;
    }
}

bool cmp1(Student a,Student b)
{
    return a.id < b.id;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Rank *rank=new Rank[n];
    Student *student=new Student[n];
    for (int i = 0; i < n; i++)
    {
        string id;
        double grade;
        string school;
        cin >> id >> grade >> school;
        for (int i = 0; i < school.size(); i++)
        {
            if (school[i] <= 'Z' && school[i] >= 'A')
            {
                school[i] = school[i] + 32;
            }
        }
        if (id[0] == 'B')
            grade = grade / 1.5;
        else if (id[0] == 'A')
            grade = grade;
        else
            grade = grade * 1.5;
        student[i].id = school;
        student[i].grade = grade;
    }
    sort(student, student + n, cmp1);
    rank[0].name = student[0].id;
    rank[0].total = student[0].grade;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (rank[count-1].name==student[i].id)
        {
            rank[count-1].num++;
            rank[count-1].total += student[i].grade;
        }
        else
        {
            rank[count].name = student[i].id;
            rank[count].total = student[i].grade;
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        rank[i].total = int(rank[i].total);
    }
    sort(rank, rank + count, cmp);
    cout << count << endl;
    cout << "1 ";
    cout << rank[0].name << " " << rank[0].total << " " << rank[0].num << endl;
    int num = 1;
    for (int i = 1; i < count; i++)
    {
        if (rank[i].total == rank[i - 1].total)
        {
            cout << num << " ";
            cout << rank[i].name << " " << rank[i].total << " " << rank[i].num << endl;
        }
        else
        {
            num = i + 1;
            cout << num << " ";
            cout << rank[i].name << " " << rank[i].total << " " << rank[i].num << endl;
        }
    }

    return 0;
}