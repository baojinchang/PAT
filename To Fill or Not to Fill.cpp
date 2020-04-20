#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Station
{
    int dis;
    double price;
};

bool cmp(Station a, Station b)
{
    return a.dis < b.dis;
}

int main()
{
    int cap, distance, unit, n;
    cin >> cap >> distance >> unit >> n;
    vector<Station> station(n);
    for (int i = 0; i < n; i++)
    {
        cin >> station[i].price >> station[i].dis;
    }
    sort(station.begin(), station.end(), cmp);
    double start = 0;
    int flag = 0;
    double left = 0;
    double price = 0;
    int befor = 0;
    if(station[0].dis!=0)
    {
        cout << "The maximum travel distance = ";
        cout << 0.00;
        return 0;
    }
    while (true)
    {
        int temp = start + cap * unit;
        int i;
        for (i = flag + 1; i < n; i++)
        {
            if (station[i].dis > temp)
            {
                break;
            }
        }
        if (i == flag + 1)
        {
            if (temp < distance)
            {
                start = temp;
                price += (cap - left) * station[flag].price;
                left = 0;
                break;
            }
            else
            {
                if ((distance - start) / unit - left < 0)
                {
                    price += ((distance - start) / unit - left) * station[befor].price;
                }
                else
                {
                    price += ((distance - start) / unit - left) * station[flag].price;
                }
                start = distance;
                break;
            }
        }
        else
        {
            int v = flag;
            for (int j = flag + 1; j < i; j++)
            {
                if (station[j].price < station[flag].price)
                {
                    v = j;
                    break;
                }
            }
            if (v != flag)
            {
                if ((station[v].dis - start) / unit - left < 0)
                {
                    price += ((station[v].dis - start) / unit - left) * station[befor].price;
                }
                else
                {
                    price += ((station[v].dis - start) / unit - left) * station[flag].price;
                }
                start = station[v].dis;
                left = 0;
                befor = flag;
                flag = v;
            }
            else
            {
                double min = station[flag + 1].price;
                int v = flag + 1;
                for (int j = flag + 2; j < i; j++)
                {
                    if (station[j].price < min)
                    {
                        min = station[j].price;
                        v = j;
                    }
                }
                price += (cap - left) * station[flag].price;
                left = cap - (station[v].dis - start) / unit;
                befor = flag;
                flag = v;
                start = station[v].dis;
            }
        }
    }
    if (start < distance)
    {
        cout << "The maximum travel distance = ";
        printf("%0.2f", start);
    }
    else
    {
        printf("%0.2f", price);
    }

    return 0;
}