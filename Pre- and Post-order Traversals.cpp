#include<iostream>
#include<vector>

using namespace std;

vector<int> pre, in, post;
bool flag = true;

void getin(int lpre,int rpre,int lpost,int rpost)
{
    if (lpre==rpre)
    {
        in.push_back(pre[lpre]);
        return;
    }
    if (pre[lpre]==post[rpost])
    {
        int i = lpre + 1;
        while (i<=rpre&&pre[i]!=post[rpost-1])
        {
            i++;
        }
        if (i-lpre==1)
        {
            flag = false;
        }
        else
        {
            getin(lpre + 1, i - 1, lpost, i - lpre - 2 + lpost);
        }
        in.push_back(pre[lpre]);
        getin(i, rpre, i - lpre + lpost - 1, rpost - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pre.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        post.push_back(temp);
    }
    getin(0, n - 1, 0, n - 1);
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i];
        if (i!=in.size()-1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}