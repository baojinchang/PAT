#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

struct Sale
{
    int deep = 0;
    int k;
    int number = 0;
    int *chile = new int[k];
};

int dfs(Sale sale[],int v)
{
    if (sale[v].k!=0)
    {
        for (int i = 0; i < sale[v].k; i++)
        {
            sale[sale[v].chile[i]].deep = sale[v].deep + 1;
            dfs(sale, sale[v].chile[i]);
        }
    }

    return 0;
}

int main()
{
    int n;
    double p, r;
    cin >> n >> p >> r;
    Sale sale[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> sale[i].k;
        for (int j = 0; j < sale[i].k; j++)
        {
            int a;
            cin >> a;
            sale[i].chile[j] = a;
        }
        if (sale[i].k==0)
        {
            cin >> sale[i].number;
        }
    }
    dfs(sale, 0);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sale[i].k==0)
        {
            sum = sum + sale[i].number * p * pow((1 + r / 100), sale[i].deep);
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << sum;

    return 0;
}