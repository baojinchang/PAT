#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    set<int> num[60];
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int temp;
            scanf("%d", &temp);
            num[i + 1].insert(temp);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        set<int> temp;
        temp = num[x];
        for (set<int>::iterator it = num[y].begin(); it != num[y].end();it++)
        {
            temp.insert(*it);
        }
        double a = temp.size();
        double b = (num[x].size() + num[y].size()) - temp.size();
        printf("%0.1f\%\n", b / a*100);
    }

    return 0;
}