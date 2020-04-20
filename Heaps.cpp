#include<iostream>
#include<vector>

using namespace std;

int vist(vector<int> node,int v,int n)
{
    if (v*2+1<n)
    {
        vist(node, v * 2 + 1, n);
    }
    if (v*2+2<n)
    {
        vist(node, v * 2 + 2, n);
    }
    cout << node[v];
    if (v!=0)
    {
        cout << " ";
    }

    return 0;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<int> node(n);
        for (int i = 0; i < n; i++)
        {
            cin >> node[i];
        }
        int flag = 0;
        if (node[0]>=node[1])
        {
            flag = 1;
        }
        int j;
        if (flag==0)
        {
            for ( j = 0; j < n; j++)
            {
                if (j*2+1<n)
                {
                    if(node[j]>=node[j*2+1])
                        break;
                }
                if (j*2+2<n)
                {
                    if(node[j]>=node[j*2+2])
                        break;
                }
            }
        }
        if(flag==1)
        {
            for ( j = 0; j < n; j++)
            {
                if (j*2+1<n)
                {
                    if(node[j]<node[j*2+1])
                        break;
                }
                if (j*2+2<n)
                {
                    if(node[j]<node[j*2+2])
                        break;
                }
            }
        }
        if (j!=n)
        {
            cout << "Not Heap" << endl;
        }
        else if (flag==0)
        {
            cout << "Min Heap" << endl;
        }
        else
        {
            cout << "Max Heap" << endl;
        }
        vist(node, 0, n);
        cout << endl;
    }
    

    return 0;
}