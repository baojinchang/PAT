#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    char gender;
    string id;
    int grade;
};

int main()
{
    int n;
    cin >> n;
    Student *student = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> student[i].name >> student[i].gender >> student[i].id >> student[i].grade;
    }
    int count1, count2;
    count1 = count2 = 0;
    Student max, min;
    max.grade = -1;
    min.grade = 101;
    for (int i = 0; i < n; i++)
    {
        if (student[i].gender == 'F')
        {
            if (student[i].grade > max.grade)
            {
                max = student[i];
                count2 = 1;
            }
        }
        else if (student[i].gender == 'M')
        {
            if (student[i].grade < min.grade)
            {
                min = student[i];
                count1 = 1;
            }
        }
    }
    if (count1 == 1 && count2 == 1)
    {
        cout << max.name << " " << max.id << endl;
        cout << min.name << " " << min.id << endl;
        cout << max.grade - min.grade;
    }
    else if (count1 == 1 && count2 == 0)
    {
        cout << "Absent" << endl;
        cout << min.name << " " << min.id << endl;
        cout << "NA";
    }
    else
    {
        cout << max.name << " " << max.id << endl;
        cout << "Absent" << endl;
        cout << "NA";
    }

    return 0;
}