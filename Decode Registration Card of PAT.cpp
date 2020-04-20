#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct Testee
{
    string level;
    string site;
    string date;
    string id;
    int grade;
} testee[10010];

struct  Out
{
    string date;
    int sum = 0;
};


bool cmp1(Testee a,Testee b)
{
    if (a.grade==b.grade)
    {
        return (a.level + a.site + a.date + a.id) < (b.level + b.site + b.date + b.id);
    }
    return a.grade > b.grade;
}

bool cmp2(Out a,Out b)
{
    if (a.sum==b.sum)
    {
        return a.date < b.date;
    }
    return a.sum > b.sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    map<string, vector<string>> target;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp >> testee[i].grade;
        testee[i].level = temp.substr(0, 1);
        testee[i].site = temp.substr(1, 3);
        testee[i].date = temp.substr(4, 6);
        testee[i].id = temp.substr(10, 3);
        target[testee[i].date].push_back(testee[i].site);
    }
    sort(testee, testee + n, cmp1);
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        cout << "Case " << i + 1 << ": " << temp << " ";
        if (temp==1)
        {
            string word;
            cin >> word;
            cout << word << endl;
            vector<Testee> num;
            for (int i = 0; i < n; i++)
            {
                if (testee[i].level==word)
                {
                    num.push_back(testee[i]);
                }
            }
            for (int i = 0; i < num.size(); i++)
            {
                printf("%s%s%s%s %d\n", num[i].level.c_str(), num[i].site.c_str(), num[i].date.c_str(), num[i].id.c_str(), num[i].grade);
            }
            if (num.size()==0)
            {
                cout << "NA" << endl;
            }
        }
        if (temp==2)
        {
            string word;
            cin >> word;
            cout << word << endl;
            int sum = 0;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (testee[i].site==word)
                {
                    count++;
                    sum += testee[i].grade;
                }
            }
            if (count==0)
            {
                cout << "NA" << endl;
            }
            else
            {
                printf("%d %d\n", count, sum);
            }
        }
        if (temp==3)
        {
            string word;
            cin >> word;
            cout << word << endl;
            vector<Out> out;
            map<string,int> m;
            for (int i = 0; i < target[word].size(); i++)
            {
               m[target[word][i]]++;
            }
            for (map<string,int>::iterator i = m.begin(); i != m.end(); i++)
            {
                Out temp;
                temp.date = i->first;
                temp.sum = i->second;
                out.push_back(temp);
            }
            sort(out.begin(), out.end(), cmp2);
            int flag = 0;
            for (int i = 0; i < out.size(); i++)
            {
                if (out[i].sum==0)
                {
                    break;
                }
                printf("%s %d\n", out[i].date.c_str(), out[i].sum);
                flag = 1;
            }
            if (flag==0)
            {
                cout << "NA" << endl;
            }
        }
        
    }
    

    return 0;
}