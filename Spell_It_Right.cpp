#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    string str1, str2;
    cin >> str1;
    int leng;
    leng = str1.size();
    for (int i = 0; i < leng; i++)
    {
        sum = sum + (str1[i] - '0');
    }
    str2 = to_string(sum);
    leng = str2.size();
    if (sum == 0)
    {
        cout << "zero";
    }
    else
    {
        for (int i = 0; i < leng - 1; i++)
        {
            switch (str2[i])
            {
            case '0':
                cout << "zero ";
                break;
            case '1':
                cout << "one ";
                break;
            case '2':
                cout << "two ";
                break;
            case '3':
                cout << "three ";
                break;
            case '4':
                cout << "four ";
                break;
            case '5':
                cout << "five ";
                break;
            case '6':
                cout << "six ";
                break;
            case '7':
                cout << "seven ";
                break;
            case '8':
                cout << "eight ";
                break;
            case '9':
                cout << "nine ";
                break;
            }
        }
        switch (str2[leng - 1])
        {
        case '0':
            cout << "zero";
            break;
        case '1':
            cout << "one";
            break;
        case '2':
            cout << "two";
            break;
        case '3':
            cout << "three";
            break;
        case '4':
            cout << "four";
            break;
        case '5':
            cout << "five";
            break;
        case '6':
            cout << "six";
            break;
        case '7':
            cout << "seven";
            break;
        case '8':
            cout << "eight";
            break;
        case '9':
            cout << "nine";
            break;
        }

        return 0;
    }
}