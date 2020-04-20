#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const int INF = 1000000;

int n;

int revese(string str)
{
    if (str[0] == 'G')
    {
        str.erase(str.begin());
        int a = 0;
        for (int i = 0; i < str.size(); i++)
        {
            a = a + (str[i] - '0') * pow(10, str.size() - 1);
            return a + n;
        }
    }
    else
    {
        int a = 0;
        for (int i = 0; i < str.size(); i++)
        {
            a = a + (str[i] - '0') * pow(10, str.size() - 1);
            return a;
        }
    }
}

int edage[1100][1100];

int main()
{
    int m, k, ds;
    cin >> n >> m >> k >> ds;
    for (int i = 0; i < 1100; i++)
    {
        for (int j = 0; j < 1100; j++)
        {
            edage[i][j] = INF;
        }
    }
    for (int i = 0; i < k; i++)
    {
        string temp1, temp2;
        int a;
        cin >> temp1 >> temp2 >> a;
        edage[revese(temp1)][revese(temp2)] = a;
        edage[revese(temp2)][revese(temp1)] = a;
    }
    int vist[1100] = {0};
    int distance[1100];
    int number[11];
    double ave[11];
    for (int i = n + 1; i < n + m + 1; i++)
    {
        for (int j = 1; j < n + m + 1; j++)
        {
            distance[j] = edage[j][i];
        }
        vist[i] = 1;
        for (int j = 0; j < n + m; j++)
        {
            int min = INF;
            int v = 0;
            for (int k = 1; k < m + n + 1; k++)
            {
                if (distance[k] < min && vist[k] == 0)
                {
                    v = k;
                    min = distance[k];
                }
            }
            vist[v] = 1;
            for (int k = 1; k < m + n + 1; k++)
            {
                if (distance[k] > distance[v] + edage[v][k] && vist[k] == 0)
                {
                    distance[k] = distance[v] + edage[v][k];
                }
            }
        }
        int min = INF;
        int j;
        double sum=0;
        for (j = 1; j < n + 1; j++)
        {
            if (distance[j] > ds)
            {
                break;
            }
            if (min > distance[j])
            {
                min = distance[j];
            }
            sum = sum + distance[j];
        }
        if (j == n + 1)
        {
            number[i - n] = min;
            ave[i - n] = sum / n;
        }
        else
        {

            number[i - n] = INF;
            ave[i - n] = INF;
        }
        for (int i = 0; i < 1100; i++)
        {
            vist[i] = 0;
        }
    }
    int max = 0;
    int flag = 1;
    for (int i = 1; i < m + 1; i++)
    {
        if (number[i] != INF && number[i] > max)
        {
            max = number[i];
            flag = i;
        }
        else if (number[i] == max && ave[i] < ave[flag])
        {
            flag = i;
        }
    }
    if (max == 0)
    {
        cout << "No Solution";
    }
    else
    {
        cout << "G" << flag << endl;
        cout << number[flag] << ".0"
             << " " << setiosflags(ios::fixed) << setprecision(1) << ave[flag];
    }

    return 0;
}