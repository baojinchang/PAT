#include <iostream>
#include <string>
#include<algorithm>
#include<map>

using namespace std;

bool jude(char &a)
{
    if(a>='a'&&a<='z')
    {
        return true;
    }
    if (a>='A'&&a<='Z')
    {
        a = a + 32;
        return true;
    }
    if (a>='0'&&a<='9')
    {
        return true;
    }
    return false;
}

int main()
{
    string str;
    getline(cin, str);
    map<string, int> ans;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (jude(str[i]))
        {
            temp += str[i];
        }
        else if(jude(str[i-1]))
        {
            ans[temp]++;
            temp.clear();
        }
    }
    if (temp.size()!=0)
    {
        ans[temp]++;
    }
    int max = -1;
    for (map<string,int> ::iterator i = ans.begin(); i != ans.end(); i++)
    {
        if (i->second>max)
        {
            max = i->second;
            str = i->first;
        }
    }
    cout << str << " " << max;

    return 0;
}