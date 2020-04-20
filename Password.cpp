#include <iostream>
#include <string>

using namespace std;

struct Account
{
    string name;
    string password;
};

int main()
{
    int n;
    cin >> n;
    Account *account = new Account[n];
    for (int i = 0; i < n; i++)
    {
        cin >> account[i].name >> account[i].password;
    }
    string str;
    for (int i = 0; i < n; i++)
    {
        int j, count = 0;
        for (j = 0; j < account[i].password.size(); j++)
        {
            if (account[i].password[j] == '1')
            {
                account[i].password[j] = '@';
                count = 1;
            }
            else if (account[i].password[j] == '0')
            {
                account[i].password[j] = '%';
                count = 1;
            }
            else if (account[i].password[j] == 'l')
            {
                account[i].password[j] = 'L';
                count = 1;
            }
            else if (account[i].password[j] == 'O')
            {
                account[i].password[j] = 'o';
                count = 1;
            }
        }
        if (count != 0)
        {
            str = str + to_string(i);
        }
    }
    if (str.size() == 0)
    {
        if (n == 1)
        {
            cout << "There is " << n << " account and no account is modified";
        }
        else
        {
            cout << "There are " << n << " accounts and no account is modified";
        }
    }
    else
    {
        cout << str.size() << endl;
        for (int i = 0; i < str.size(); i++)
        {
            cout << account[str[i] - '0'].name << " " << account[str[i] - '0'].password << endl;
        }
    }
    delete[] account;
    return 0;
}