#include <algorithm>
#include <iostream>

using namespace std;

struct Student
{
    int id;
    int gi;
    int ge;
    int choice[5];
};

struct School
{
    int max;
    int stu[10000];
    int count = 0;
};

bool cmp1(Student a, Student b)
{
    if (a.ge == b.ge && a.gi == b.gi)
    {
        return a.ge > b.ge;
    }
    else
    {
        return a.ge + a.gi > b.ge + b.gi;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    School school[100];
    for (int i = 0; i < m; i++)
    {
        cin >> school[i].max;
    }
    Student student[40000];
    for (int i = 0; i < n; i++)
    {
        student[i].id = i;
        cin >> student[i].ge >> student[i].gi;
        for (int j = 0; j < k; j++)
        {
            cin >> student[i].choice[j];
        }
    }
    sort(student, student + n, cmp1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int choice = student[i].choice[j];
            if (school[choice].count < school[choice].max)
            {
                school[choice].stu[school[choice].count] = student[i].id;
                school[choice].count++;
                break;
            }
            else if (student[i].ge == student[school[choice].stu[school[choice].count - 1]].ge && student[i].gi == student[school[choice].stu[school[choice].count - 1]].gi)
            {
                school[choice].stu[school[choice].count] = student[i].id;
                school[choice].count++;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (school[i].count > 0)
        {
            sort(school[i].stu, school[i].stu + school[i].count);
            for (int j = 0; j < school[i].count; j++)
            {
                if (j != school[i].count - 1)
                {
                    cout << school[i].stu[j] << " ";
                }
                else
                {
                    cout << school[i].stu[j] << endl;
                }
            }
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}