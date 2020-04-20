#include<iostream>
#include<vector>

using namespace std;

int n;

int vist(int v,vector<int> node,int deep,vector<int> path)
{
    path[deep] = node[v];
    if (v*2+1>n-1)
    {
        for (int i = 0; i <= deep; i++)
        {
            cout << path[i];
            if (i==deep)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
    else
    {
        if (v*2+2<n)
        {
            vist(v * 2 + 2, node, deep + 1,path);
        }
        if (v*2+1<n)
        {
            vist(v * 2 + 1, node, deep + 1,path);
        }

    }
    

    return 0;
}

int main()
{
    cin >> n;
    vector<int> node(n);
    vector<int> path(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        node[i] = temp;
    }
    vist(0,node,0,path);
    int flag = 0;
    if (node[0]>=node[1])
    {
        flag = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (flag==0&&node[(i-1)/2]>=node[i])
        {
            flag = -1;
            break;
        }
        if (flag==1&&node[(i-1)/2]<node[i])
        {
            flag = -1;
            break;
        }
    }
    if (flag==1)
    {
        cout << "Max Heap";
    }
    else if (flag==0)
    {
        cout << "Min Heap";
    }
    else
    {
        cout << "Not Heap";
    }

    return 0;
}