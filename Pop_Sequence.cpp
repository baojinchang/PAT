#include<iostream>

using namespace std;

int m;

struct Stack
{
    int top = 0;
    int *que = new int[m];
};


int main()
{
    cin >> m;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int j;
        int count = 1;
        Stack stack;
        int *temp = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }
        for ( j = 0; j < n; j++)
        {
            if (stack.top>0&&temp[j]<stack.que[stack.top-1])
            {
                break;
            }
            else if (stack.top>m)
            {
                break;
            }
            else
            {
                while (stack.top==0||stack.que[stack.top-1]<temp[j])
                {
                    stack.que[stack.top] = count;
                    stack.top++;
                    count++;
                }
                if (stack.top>m)
                {
                    break;
                }
                stack.top--;
            }
        }
        if (j==n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}