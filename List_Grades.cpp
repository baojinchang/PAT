#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct Student
{
    string name;
    string id;
    int grade;
};

bool cmp(Student a,Student b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    cin >> n;
    Student *student = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> student[i].name >> student[i].id >> student[i].grade;
    }
    int min, max;
    cin >> min >> max;
    sort(student, student + n, cmp);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (student[i].grade<=max&&student[i].grade>=min)
        {
            cout << student[i].name << " " << student[i].id << endl;
            flag = 1;
        }
    }
    if (flag==0)
    {
        cout << "NONE";
    }

    return 0;
}