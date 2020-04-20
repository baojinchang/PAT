#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i + 1 << ": ";
        long long sum = a + b;
        if (a > 0 && b > 0&&sum<0)
        {
            cout << "true" << endl;
        }
        else if (a<0&&b<0&&sum>0)
        {
            cout << "false" << endl;
        }
        else if (sum>c)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}
