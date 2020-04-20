#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node
{
    vector<int> hobby;
};


int main()
{
    int n;
    cin >> n;
    Node node[1001];
    for (int i = 1; i < n+1; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp[0]-'0'; j++)
        {
            int a;
            cin >> a;
            node[i].hobby.push_back(a);
        }
    }
    

    return 0;
}