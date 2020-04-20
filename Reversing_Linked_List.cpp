#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    int next;
};

int start;

int list(Node node[], int count, int k, int adderse, int pre)
{
    if (k == 1)
    {
        return 0;
    }
    else
    {
        if (count != k)
        {
            pre = adderse;
            list(node, count + 1, k, node[adderse].next, pre);
        }
        if (count == k)
        {
            start = node[adderse].next;
            string str;
            str = to_string(adderse);
            for (int i = 0; i < 5 - str.size(); i++)
            {
                cout << "0";
            }
            cout << str << " ";
            cout << node[adderse].data << " ";
        }
        if (count > 1&& count < k)
        {
            string str;
            str = to_string(adderse);
            for (int i = 0; i < 5 - str.size(); i++)
            {
                cout << "0";
            }
            cout << str << endl;
            for (int i = 0; i < 5 - str.size(); i++)
            {
                cout << "0";
            }
            cout << str << " ";
            cout << node[adderse].data << " ";
        }
        if (count == 1)
        {
            string str;
            str = to_string(adderse);
            for (int i = 0; i < 5 - str.size(); i++)
            {
                cout << "0";
            }
            cout << str << endl;
            for (int i = 0; i < 5 - str.size(); i++)
            {
                cout << "0";
            }
            cout << str << " ";
            cout << node[adderse].data << " ";
            if (start == -1)
            {
                cout << start << endl;
            }
            else
            {
                str = to_string(start);
                for (int i = 0; i < 5 - str.size(); i++)
                {
                    cout << "0";
                }
                cout << str << endl;
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    Node node[100000];
    int n, k;
    cin >> start >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cin >> node[temp].data >> node[temp].next;
    }
    for (int i = 0; i < n / k; i++)
    {
        list(node, 1, k, start,start);
    }
    if (k==1)
    {
        k = n + 1;
    }
    if (k==n)
    {
        n = 0;
    }
    for (int i = 0; i < n % k; i++)
    {
        if (start < 10000 && start >= 1000)
        {
            cout << "0";
        }
        if (start < 1000 && start >= 100)
        {
            cout << "00";
        }
        if (start < 100 && start >= 10)
        {
            cout << "000";
        }
        if (start < 10 && start >= 0)
        {
            cout << "0000";
        }
        cout << start << " " << node[start].data << " ";
        start = node[start].next;
        if (start < 10000 && start >= 1000)
        {
            cout << "0";
        }
        if (start < 1000 && start >= 100)
        {
            cout << "00";
        }
        if (start < 100 && start >= 10)
        {
            cout << "000";
        }
        if (start < 10 && start >= 0)
        {
            cout << "0000";
        }
        cout << start << endl;
    }

    return 0;
}