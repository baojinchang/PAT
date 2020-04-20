#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct List
{
    int key;
    string now;
    string next;
};

bool cmp(List list1,List list2)
{
    if (list1.key<list2.key)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, start;
    cin >> n >> start;
    List *list = new List[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].now >> list[i].key >> list[i].next;
    }
    sort(list, list + n, cmp);
    cout << n << " " << list[0].now << endl;
    for (int i = 0; i < n-1; i++)
    {
        cout << list[i].now << " " << list[i].key << " " << list[i + 1].now << endl;
    }
    cout << list[n - 1].now << " " << list[n - 1].key << " " << -1;
    delete[] list;

    return 0;
}