#include <iostream>
#include <string>

using namespace std;

int main()
{
    string number;
    int a[10] = {0}, b[10] = {0};
    cin >> number;
    int leng = number.size();
    for (int i = 0; i < leng; i++)
    {
        switch (number[i])
        {
        case '0':
            a[0]++;
            break;
        case '1':
            a[1]++;
            break;
        case '2':
            a[2]++;
            break;
        case '3':
            a[3]++;
            break;
        case '4':
            a[4]++;
            break;
        case '5':
            a[5]++;
            break;
        case '6':
            a[6]++;
            break;
        case '7':
            a[7]++;
            break;
        case '8':
            a[8]++;
            break;
        case '9':
            a[9]++;
            break;
        }
    }
    if (number[0] - '0' < 5)
    {
        int tar = 0;
        for (int i = leng - 1; i >= 0; i--)
        {
            if ((number[i] - '0') * 2 < 10)
            {
                if (tar == 0)
                {
                    number[i] = (number[i] - '0') * 2 + '0';
                }
                else
                {
                    number[i] = (number[i] - '0') * 2 + 1 + '0';
                }
                tar = 0;
            }
            else
            {
                if (tar == 0)
                {
                    number[i] = (number[i] - '0') * 2 - 10 + '0';
                }
                else
                {
                    number[i] = (number[i] - '0') * 2 - 10 + 1 + '0';
                }
                tar = 1;
            }
        }
        for (int i = 0; i < leng; i++)
        {
            switch (number[i])
            {
            case '0':
                b[0]++;
                break;
            case '1':
                b[1]++;
                break;
            case '2':
                b[2]++;
                break;
            case '3':
                b[3]++;
                break;
            case '4':
                b[4]++;
                break;
            case '5':
                b[5]++;
                break;
            case '6':
                b[6]++;
                break;
            case '7':
                b[7]++;
                break;
            case '8':
                b[8]++;
                break;
            case '9':
                b[9]++;
                break;
            }
        }
        int i;
        for (i = 0; i < 10; i++)
        {
            if (a[i] != b[i])
            {
                break;
            }
        }

        if (i == 10)
        {
            cout << "Yes" << endl
                 << number;
        }
        else
        {
            cout << "No" << endl
                 << number;
        }
    }
    else
    {
        cout << "No" << endl;
        int tar = 0;
        for (int i = leng - 1; i >= 0; i--)
        {
            if ((number[i] - '0') * 2 < 10)
            {
                if (tar == 0)
                {
                    number[i] = (number[i] - '0') * 2 + '0';
                }
                else
                {
                    number[i] = (number[i] - '0') * 2 + 1 + '0';
                }
                tar = 0;
            }
            else
            {
                if (tar == 0)
                {
                    number[i] = (number[i] - '0') * 2 - 10 + '0';
                }
                else
                {
                    number[i] = (number[i] - '0') * 2 - 10 + 1 + '0';
                }
                tar = 1;
            }
        }
        cout << '1' << number;
    }

    return 0;
}