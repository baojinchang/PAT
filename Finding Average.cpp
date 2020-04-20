#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool jude(string temp)
{
    if (temp[0] == '-')
    {
        temp.erase(temp.begin());
    }
    int flag;
    int count = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if ((temp[i] >= '0' && temp[i] <= '9') || temp[i] == '.')
        {
            if (temp[i] == '.')
            {
                count++;
                flag = i;
                if (count == 2)
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    if (count == 1)
    {
        if (flag < temp.size() - 3)
        {
            return false;
        }
    }
    double num = stof(temp);
    if (num > 1000)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (!jude(temp))
        {
            cout << "ERROR: " << temp << " is not a legal number" << endl;
        }
        else
        {
            count++;
            sum += stof(temp);
        }
    }
    if (count == 0)
    {
        cout << "The average of 0 numbers is Undefined";
    }
    else if (count == 1)
    {
        cout << "The average of " << count << " number is ";
        printf("%0.2f", sum / count);
    }
    else
    {
        cout << "The average of " << count << " numbers is ";
        printf("%0.2f", sum / count);
    }

    return 0;
}