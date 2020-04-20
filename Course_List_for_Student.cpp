#include <iostream>
#include <string>

using namespace std;

int n, k;

struct Course
{
    string *name = new string[n];
};

int main()
{
    cin >> n >> k;
    Course *course = new Course[k + 1];
    for (int i = 0; i < k; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        for (int i = 0; i < temp2; i++)
        {
            cin >> course[temp1].name[i];
        }
    }
    string *search = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> search[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << search[i] << " ";
        int *number = new int[k];
        int count = 0;
        for (int j = 1; j < k + 1; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (search[i] == course[j].name[l])
                {
                    number[count] = j;
                    count++;
                }
            }
        }
        if (count == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << count << " ";
            for (int i = 0; i < count - 1; i++)
            {
                cout << number[i] << " ";
            }
            cout << number[count - 1] << endl;
        }
        delete[] number;
    }

    delete[] search;
    delete[] course;

    return 0;
}