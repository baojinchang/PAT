#include <algorithm>
#include <iostream>

using namespace std;

int l, h;

struct People
{
    int id;
    int Virtue;
    int Talent;
};

bool cmp(People a, People b)
{
    if (a.Talent >= h && a.Virtue >= h && b.Virtue >= h && b.Talent >= h)
    {
        if (a.Talent + a.Virtue == b.Virtue + b.Talent)
        {
            if (a.Talent == b.Talent)
            {
                return a.id < b.id;
            }
            else
            {
                return a.Virtue > b.Virtue;
            }
        }
        else
        {
            return a.Virtue + a.Talent > b.Talent + b.Virtue;
        }
    }
    if (a.Virtue >= h && a.Talent < h && b.Virtue >= h && b.Talent < h)
    {
        if (a.Talent + a.Virtue == b.Virtue + b.Talent)
        {
            if (a.Talent == b.Talent)
            {
                return a.id < b.id;
            }
            else
            {
                return a.Virtue > b.Virtue;
            }
        }
        else
        {
            return a.Virtue + a.Talent > b.Talent + b.Virtue;
        }
    }
    if (a.Virtue < h && b.Virtue < h)
    {
        if (a.Virtue >= a.Talent && b.Virtue >= b.Talent)
        {
            if (a.Talent + a.Virtue == b.Virtue + b.Talent)
            {
                if (a.Talent == b.Talent)
                {
                    return a.id < b.id;
                }
                else
                {
                    return a.Virtue > b.Virtue;
                }
            }
            else
            {
                return a.Virtue + a.Talent > b.Talent + b.Virtue;
            }
        }
        else if (a.Virtue >= a.Talent && b.Virtue < b.Talent)
        {
            return true;
        }
        else if (a.Virtue < a.Talent && b.Virtue >= b.Talent)
        {
            return false;
        }
        else
        {
            if (a.Talent + a.Virtue == b.Virtue + b.Talent)
            {
                if (a.Talent == b.Talent)
                {
                    return a.id < b.id;
                }
                else
                {
                    return a.Virtue > b.Virtue;
                }
            }
            else
            {
                return a.Virtue + a.Talent > b.Talent + b.Virtue;
            }
        }
    }
    if (a.Virtue >= h && a.Talent >= h && b.Virtue >= h && b.Talent < h)
    {
        return true;
    }
    if (a.Virtue >= h && a.Talent < h && b.Virtue >= h && b.Talent >= h)
    {
        return false;
    }
    if (a.Virtue >= h && a.Talent >= h && b.Virtue < h)
    {
        return true;
    }
    if (a.Virtue < h && b.Virtue >= h && b.Talent >= h)
    {
        return false;
    }
    if (a.Virtue >= h && a.Talent < h && b.Virtue < h)
    {
        return true;
    }
    if (a.Virtue < h && b.Virtue >= h && b.Talent < h)
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> l >> h;
    int count = 0;
    People people[100001];
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b >= l && c >= l)
        {
            people[count].id = a;
            people[count].Virtue = b;
            people[count].Talent = c;
            count++;
        }
    }
    sort(people, people + count, cmp);
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << people[i].id << " " << people[i].Virtue << " " << people[i].Talent << endl;
    }

    return 0;
}