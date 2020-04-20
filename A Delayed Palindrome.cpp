#include<iostream>
#include<string>

using namespace std;

int main()
{
    string num;
    cin >> num;
    int count = 0;
    while (1)
    {
        string num1;
        for (int i = 0; i < num.size(); i++)
        {
            num1 = num[i] + num1;
        }
        if (count>=10)
        {
            cout << "Not found in 10 iterations.";
            break;
        }
        if (num1==num)
        {
            cout << num << " is a palindromic number.";
            break;
        }
        cout << num << " + " << num1 << " = ";
        int flag = 0;
        string num2;
        for (int i = num.size()-1; i >= 0; i--)
        {
            int a = (num[i] - '0' + num1[i] - '0' + flag) % 10;
            flag=(num[i] - '0' + num1[i] - '0' + flag) / 10;
            num2 = to_string(a) + num2;
        }
        if (flag==1)
        {
            num2 = to_string(flag) + num2;
        }
        num = num2;
        cout << num << endl;
        count++;
    }

    return 0;
}