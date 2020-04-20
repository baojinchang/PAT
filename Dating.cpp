#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    int count = 0;
    string str;
    for (int i = 0; i < str1.size()&&i<str2.size(); i++)
    {
        if (str1[i]==str2[i])
        {
            str = str + str1[i];
        }
    }
    int j;
    for ( j = 0; j < str.size(); j++)
    {
        if (str[j]>='A'&&str[j]<='G')
        {
            switch (str[j])
            {
            case 'A':
                cout << "MON"
                     << " ";
                break;
            case 'B':
                cout << "TUE"
                     << " ";
                break;
            case 'C':
                cout << "WED"
                     << " ";
                break;
            case 'D':
                cout << "THU"
                     << " ";
                break;
            case 'E':
                cout << "FRI"
                     << " ";
                break;
            case 'F':
                cout << "SAT"
                     << " ";
                break;
            case 'G':
                cout << "SUN"
                     << " ";
                break;
            }
            break;
        }
    }
    j++;
    for ( j; j <str.size() ; j++)
    {
        if (str[j]>='0'&&str[j]<='9')
        {
            cout << 0 << str[j] - '0' << ":";
            break;
        }
        if (str[j]>='A'&&str[j]<='N')
        {
            cout << str[j] - 'A' + 10 << ":";
            break;
        }
    }
    for (int i = 0; i < str3.size()&&i<str4.size(); i++)
    {
        if(str3[i]==str4[i]&&((str3[i]>='a'&&str3[i]<='z')||(str3[i]>='A'&&str3[i]<='Z')))
        {
            if (i<10)
            {
                cout << 0 << i;
            }
            else
            {
                cout << i;
            }
            break;
        }
    }

    return 0;
}