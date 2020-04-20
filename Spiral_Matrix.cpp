#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int k;
    scanf("%d", &k);
    vector<int> num(k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &num[i]);
    }
    int n = sqrt(k);
    while (k % n != 0)
    {
        n--;
    }
    int m = k / n;
    sort(num.begin(), num.end(), cmp);
    int matrix[100][100];
    int count = 0;
    int level = m / 2 + m % 2;
    for (int p = 0; p < level; p++)
    {
        for (int i = p; i < n - p&&count<k; i++)
        {
            matrix[p][i] = num[count++];
        }
        for (int i = p+1; i < m - 1 - p&&count<k; i++)
        {
            matrix[i][n - 1 - p] = num[count++];
        }
        for (int i = n-1-p; i >= p &&count<k; i--)
        {
            matrix[m - 1 - p][i] = num[count++];
        }
        for (int i = m-2-p ; i >= p+1 &&count<k; i--)
        {
            matrix[i][p] = num[count++];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if (j != n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}