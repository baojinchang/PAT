#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string id;
    string in;
    string out;
};

int main()
{
    int studnet_number;
    cin >> studnet_number;
    Student student[studnet_number];
    for (int i = 0; i < studnet_number; i++)
    {
        cin >> student[i].id >> student[i].in >> student[i].out;
    }
    int min, max;
    min = 0, max = studnet_number - 1;
    for (int i = 0; i < studnet_number; i++)
    {
        if (student[i].in < student[min].in)
        {
            min = i;
        }
        if (student[i].out > student[max].out)
        {
            max = i;
        }
    }
    cout << student[min].id << " " << student[max].id;

    return 0;
}