#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int flag[100] = {0};
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        int sum = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            sum += (temp[i] - '0');
        }
        flag[sum] = 1;
    }
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (flag[i] == 1)
        {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < 100; i++)
    {
        if (flag[i] == 1)
        {
            cout << i;
            count--;
            if (count != 0)
            {
                cout << " ";
            }
        }
    }

    return 0;
}