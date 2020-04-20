#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

struct Mooncake
{
    int amount;
    double price;
    double ave;
};

bool cmp(Mooncake a,Mooncake b)
{
    return a.ave > b.ave;
}

int main()
{
    int n, demand;
    cin >> n >> demand;
    Mooncake mooncake[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> mooncake[i].amount;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mooncake[i].price;
        mooncake[i].ave = mooncake[i].price / mooncake[i].amount;
    }
    sort(mooncake, mooncake + n, cmp);
    int count = 0;
    double sum = 0;
    while (demand>0&&count<n)
    {
        if (demand>=mooncake[count].amount)
        {
            sum = sum + mooncake[count].price;
            demand = demand - mooncake[count].amount;
            count++;
        }
        else
        {
            sum = sum + mooncake[count].price * demand / mooncake[count].amount;
            demand = 0;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sum;

    return 0;
}