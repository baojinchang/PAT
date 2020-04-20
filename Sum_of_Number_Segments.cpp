#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        double temp;
        cin >> temp;
        sum += temp * i * (n + 1 - i);
    }
    printf("%0.2f", sum);

    return 0;
}