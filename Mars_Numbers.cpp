#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string lowrelation[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highrelation[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, temp);
        if (temp[0] >= '0' && temp[0] <= '9')
        {
            int number = 0;
            for (int i = 0; i < temp.size(); i++)
            {
                number = number + (temp[i] - '0') * pow(10, temp.size() - 1 - i);
            }
            int x = number / 13;
            int y = number % 13;
            if (x != 0 && y != 0)
            {
                cout << highrelation[x] << " " << lowrelation[y] << endl;
            }
            if (x != 0 && y == 0)
            {
                cout << highrelation[x] << endl;
            }
            if (x == 0&&y!=0)
            {
                cout << lowrelation[y] << endl;
            }
            if (x==0&&y==0)
            {
                cout << "tret" << endl;
            }
            
        }
        else
        {
            if (temp.size() == 3)
            {
                int j;
                for ( j = 0; j < 13; j++)
                {
                    if (lowrelation[j]==temp)
                    {
                        cout << j << endl;
                        break;
                    }
                }
                if (j==13)
                {
                    for ( j = 0; j < 13; j++)
                    {
                        if (highrelation[j] == temp)
                        {
                            cout << j * 13 << endl;
                        }                       
                    }
                }
                
            }
            else if (temp.size()==4)
            {
                cout << 0 << endl;
            }
            else
            {
                string x, y;
                for (int j = 0; j < 7; j++)
                {
                    if (j<3)
                    {
                        x = x + temp[j];
                    }
                    else if(j>3)
                    {
                        y = y + temp[j];
                    }
                }
                int a, b;
                for (int j = 0; j < 13; j++)
                {
                    if (highrelation[j]==x)
                    {
                        a = j;
                    }
                    if (lowrelation[j]==y)
                    {
                        b = j;
                    }
                }
                cout << a * 13 + b << endl;
            }
        }
    }

    return 0;
}