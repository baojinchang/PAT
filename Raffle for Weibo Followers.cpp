#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m, s;
    cin >> m >> n >> s;
    vector<string> name;
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        name.push_back(temp);
    }
    if (m < s)
    {
        cout << "Keep going...";
    }
    else
    {
        vector<string> now;
        for (int i = s - 1; i < m; i = i + n)
        {
            string temp = name[i];
            int j = 0;
            while (1)
            {
                for (j = 0; j < now.size(); j++)
                {
                    if (now[j] == temp)
                    {
                        break;
                    }
                }
                if (j == now.size())
                {
                    break;
                }
                i++;
                temp = name[i];
            }
            now.push_back(temp);
            cout << temp << endl;
        }
    }

    return 0;
}