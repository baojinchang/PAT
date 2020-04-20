#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Car
{
    string name;
    string time;
    bool flag;
};

int gettime(Car a,Car b)
{
    int hb, ha, mb, ma, sb, sa;
    hb = (b.time[0] - '0') * 10 + (b.time[1] - '0');
    ha = (a.time[0] - '0') * 10 + (a.time[1] - '0');
    mb = (b.time[3] - '0') * 10 + (b.time[4] - '0');
    ma = (a.time[3] - '0') * 10 + (a.time[4] - '0');
    sb = (b.time[6] - '0') * 10 + (b.time[7] - '0');
    sa = (a.time[6] - '0') * 10 + (a.time[7] - '0');
    return (hb * 3600 + mb * 60 + sb) - (ha * 3600 + ma * 60 + sa);
}

bool cmp(Car a, Car b)
{
    if (a.name == b.name)
    {
        return a.time < b.time;
    }
    return a.name < b.name;
}

bool cmp1(Car a, Car b)
{
    return a.time < b.time;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<Car> car(n);
    for (int i = 0; i < n; i++)
    {
        cin >> car[i].name >> car[i].time;
        string temp;
        cin >> temp;
        if (temp == "in")
        {
            car[i].flag = false;
        }
        else
        {
            car[i].flag = true;
        }
    }
    sort(car.begin(), car.end(), cmp);
    vector<Car> car1;
    for (int i = 0; i < car.size(); i++)
    {
        if (car[i].name == car[i + 1].name&&car[i].flag==false&&car[i+1].flag==true)
        {
            car1.push_back(car[i]);
            car1.push_back(car[i + 1]);
        }
    }
    vector<string> name;
    int max = -1;
    int temp = 0;
    for (int i = 0; i < car1.size(); i=i+2)
    {
        temp += gettime(car1[i], car1[i + 1]);
        if (i+2>=car1.size()||car1[i+2].name!=car1[i].name)
        {
            if (temp>max)
            {
                max = temp;
                name.clear();
                name.push_back(car1[i].name);
            }
            else if (temp==max)
            {
                name.push_back(car1[i].name);
            }
            temp = 0;
        }
    }
    sort(car1.begin(), car1.end(), cmp1);
    int j = 0;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        string temp;
        cin >> temp;
        for (j; j < car1.size(); j++)
        {
            if (car1[j].time<=temp)
            {
                if (car1[j].flag==false)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            else
            {
                break;
            }
        }
        cout << count << endl;
    }
    for (int i = 0; i < name.size(); i++)
    {
        cout << name[i] << " ";
    }
    printf("%02d:", max / 3600);
    max = max % 3600;
    printf("%02d:", max / 60);
    printf("%02d", max % 60);

    return 0;
}