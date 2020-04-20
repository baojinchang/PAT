#include <iostream>
#include <vector>

using namespace std;

bool isprime(int v)
{
    if (v == 1)
    {
        return false;
    }
    for (int i = 2; i*i <= v; i++)
    {
        if (v % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    while (!isprime(m))
    {
        m++;
    }
    vector<int> hash(m);
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j  < m; j++)
        {
            int temp = (num[i] + j * j) % m;
            if (hash[temp] == 0)
            {
                hash[temp] = num[i];
                break;
            }
        }
        if (j == m)
        {
            cout << num[i] << " cannot be inserted." << endl;
        }
    }
    double sum = 0, count = 0;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        int j;
        for ( j = 0; j < m; j++)
        {
            if (hash[(temp+j*j)%m]==temp||hash[(temp+j*j)%m]==0)
            {
                count++;
                sum += j + 1;
                break;
            }
        }
        if (j==m)
        {
            sum += j + 1;
            count++;
        }
        
    }
    printf("%0.1f", sum / count);

    return 0;
}