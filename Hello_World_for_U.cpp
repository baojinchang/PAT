#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int leng = str.size();
    int n1, n2;
    n1 = (leng + 2) / 3;
    n2 = leng + 2 - n1 * 2;
    int i = 0;
    for (i = 0; i < n1 - 1; i++)
    {
        cout << str[i];
        for (int i = 0; i < n2 - 2; i++)
        {
            cout << " ";
        }
        cout << str[leng - 1 - i];
        cout << endl;
    }
    int m = i;
    for (i; i < leng - m; i++)
    {
        cout << str[i];
    }

    return 0;
}