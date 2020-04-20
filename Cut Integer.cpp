#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        long long num;
        cin >> num;
        string str = to_string(num);
        long long n = pow(10, str.size() / 2);
        long long a = num / n;
        long long b = num % n;
        if (b == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            if (num % (a * b) == 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}