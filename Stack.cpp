#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int *stack = new int[n];
    int top = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp=="Pop")
        {
            if (top==0)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                top--;
                cout << stack[top] << endl;
            }
        }
        else if (temp=="Push")
        {
            cin >> stack[top];
            top++;
        }
        else if (temp=="PeekMedian")
        {
            int *number = new int[top];
            for (int i = 0; i < top; i++)
            {
                number[i] = stack[i];
            }
            sort(number, number + top);
            if (top==0)
            {
                cout << "Invalid" << endl;
            }
            else if (top%2==0)
            {
                cout << number[top / 2 - 1] << endl;
            }
            else
            {
                cout << number[(top - 1) / 2] << endl;
            }
            delete[] number;
        }
    }

    return 0;
}