#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *number = new int[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        number[temp] = i;
    }
    int count = 0;
    while (number[0] != 0)
    {
        int temp;
        temp = number[0];
        number[0] = number[temp];
        number[temp] = temp;
        count++;
    }
    for (int i = 1; i < n; i++)
    {
        if (number[i] != i)
        {
            number[0] = number[i];
            number[i] = 0;
            count++;
            while (number[0] != 0)
            {
                int temp;
                temp = number[0];
                number[0] = number[temp];
                number[temp] = temp;
                count++;
            }
        }
    }
    cout << count;

    return 0;
}
