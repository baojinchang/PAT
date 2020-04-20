#include <iostream>
#include<cmath>

int main()
{
    int n;
    scanf("%d", &n);
    int ans, leng = 0;
    int length = 0;
    int j, temp;
    int m = sqrt(n);
    for (int i = 2; i <= m; i++)
    {
        j = i;
        temp = j;
        while (n % temp == 0)
        {
            j++;
            temp = temp * j;
            length++;
        }
        if (length > leng)
        {
            ans = i;
            leng = length;
        }
        length = 0;
    }
    if (leng != 0)
    {
        printf("%d\n", leng);
        for (int i = 0; i < leng; i++)
        {
            printf("%d", i + ans);
            if (i != leng - 1)
            {
                printf("*");
            }
        }
    }
    else
    {
        printf("%d\n%d", 1, n);
    }

    return 0;
}