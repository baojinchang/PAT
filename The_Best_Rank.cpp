#include <iostream>
#include <string>
struct grade
{
    std::string name;
    int c, m, e, a;
    int tag;
};
grade g[2000];
int c[2000], math[2000], e[2000], a[2000];
std::string str[2000];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> g[i].name >> g[i].c >> g[i].m >> g[i].e;
        g[i].a = (g[i].c + g[i].m + g[i].e) / 3;
        g[i].tag = 0;
    }

    for (int k = 0; k < n; k++)
    {
        int max = -1, j;
        for (int i = 0; i < n; i++)
        {
            if (g[i].tag == 0 && g[i].c > max)
                max = g[i].c, j = i;
        }
        g[j].tag = 1;
        c[j] = k + 1;
    }
    for (int i = 0; i < n; i++)
    {
        g[i].tag = 0;
    }

    for (int k = 0; k < n; k++)
    {
        int max = -1, j;
        for (int i = 0; i < n; i++)
        {
            if (g[i].tag == 0 && g[i].m > max)
                max = g[i].m, j = i;
        }
        g[j].tag = 1;
        math[j] = k + 1;
    }
    for (int i = 0; i < n; i++)
    {
        g[i].tag = 0;
    }

    for (int k = 0; k < n; k++)
    {
        int max = -1, j;
        for (int i = 0; i < n; i++)
        {
            if (g[i].tag == 0 && g[i].e > max)
                max = g[i].e, j = i;
        }
        g[j].tag = 1;
        e[j] = k + 1;
    }
    for (int i = 0; i < n; i++)
    {
        g[i].tag = 0;
    }

    for (int k = 0; k < n; k++)
    {
        int max = -1, j;
        for (int i = 0; i < n; i++)
        {
            if (g[i].tag == 0 && g[i].a > max)
                max = g[i].a, j = i;
        }
        g[j].tag = 1;
        a[j] = k + 1;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> str[i];
    }

    for (int i = 0; i < m; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (g[j].name == str[i])
                break;
        }
        if (j == n)
            std::cout << "N/A" << std::endl;
        else
        {
            if (e[j] < math[j] && e[j] < c[j] && e[j] < a[j])
                std::cout << e[j] << " " << 'E' << std::endl;
            else if (math[j] < c[j] && math[j] < a[j])
                std::cout << math[j] << " " << 'M' << std::endl;
            else if (c[j] < a[j])
                std::cout << c[j] << " " << 'C' << std::endl;
            else
                std::cout << a[j] << " " << 'A' << std::endl;
        }
    }

    return 0;
}