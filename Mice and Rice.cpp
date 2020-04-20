#include <iostream>
#include <vector>

using namespace std;

struct Rank
{
    int grade;
    int rank;
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<Rank> rank(n);
    for (int i = 0; i < n; i++)
    {
        cin >> rank[i].grade;
    }
    vector<int> order;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        order.push_back(temp);
    }
    while (order.size() != 1)
    {
        int level;
        if (order.size() % k == 0)
        {
            level = order.size()/k + 1;
        }
        else
        {
            level = order.size()/k + 2;
        }
        for (int i = 0; i < order.size(); i++)
        {
            int max = 0;
            int v;
            for (int j = i; j < order.size() && j < i + k; j++)
            {
                if (rank[order[j]].grade > max)
                {
                    max = rank[order[j]].grade;
                    v = j;
                }
            }
            for (int j = i; j < order.size() && j < i + k; j++)
            {
                if (j != v)
                {
                    rank[order[j]].rank = level;
                }
            }
            int cns = 0;
            int count = order.size() - i;
            int j = i;
            while (cns < k-1 && cns < count-1)
            {
                if (j < v)
                {
                    order.erase(order.begin() + j);
                    j--;
                    cns++;
                }
                else if (j > v)
                {
                    order.erase(order.begin() + j);
                    j--;
                    cns++;
                }
                j++;
            }
        }
    }
    rank[order[0]].rank = 1;
    for (int i = 0; i < n; i++)
    {
        cout << rank[i].rank;
        if (i != n - 1)
        {
            cout << " ";
        }
    }

    return 0;
}