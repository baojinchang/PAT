#include<iostream>

using namespace std;

struct COlor
{
    int color;
    int count = 0;
};


int main()
{
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    COlor *color = new COlor[m * n];
    int count = 0;
    for (int i = 0; i < n*m; i++)
    {
        int temp;
        cin >> temp;
        int j;
        for ( j = 0; j < count; j++)
        {
            if (temp==color[j].color)
            {
                break;
            }
        }
        if (j<count)
        {
            color[j].count++;
        }
        else
        {
            color[count].color = temp;
            color[count].count++;
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (color[i].count>m*n/2)
        {
            cout << color[i].color;
            break;
        }
    }

    return 0;
}