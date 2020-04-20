#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *lchild = NULL;
    Node *rchild = NULL;
};

int pre[40];
int in[40];

bool cmp(int a, int b)
{
    return abs(a) < abs(b);
}

Node *build(int p, int q, int n)
{
    if (p + 1 == q)
    {
        Node *tree = new Node;
        tree->data = in[p];
        return tree;
    }
    if (q <= p)
    {
        return NULL;
    }
    int temp = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = p; j < q; j++)
        {
            if (pre[i] == in[j])
            {
                temp = j;
                break;
            }
        }
        if (temp != -1 && pre[i] == in[temp])
        {
            break;
        }
    }
    Node *tree = new Node;
    tree->data = in[temp];
    tree->lchild = build(p, temp, n);
    tree->rchild = build(temp + 1, q, n);
    return tree;
}

bool red(Node *tree)
{
    if (tree == NULL)
    {
        return true;
    }
    if (tree->data < 0)
    {
        if (tree->lchild != NULL && tree->lchild->data < 0)
        {
            return false;
        }
        if (tree->rchild != NULL && tree->rchild->data < 0)
        {
            return false;
        }
    }
    if (red(tree->lchild) && red(tree->rchild))
    {
        return true;
    }
    return false;
}

int sum = -1;

bool jude(Node *tree,int n)
{
    if (tree==NULL)
    {
        return true;
    }
    if (tree->data>0)
    {
        n++;
    }
    if (tree->lchild==NULL&&tree->rchild==NULL)
    {
        if (sum==-1)
        {
            sum = n;
        }
        else if (sum!=n)
        {
            return false;
        }
    }
    if (jude(tree->lchild,n)&&jude(tree->rchild,n))
    {
        return true;
    }
    return false;
}

bool isredblack(Node *tree)
{
    if (tree->data < 0)
    {
        return false;
    }
    if (red(tree)&&jude(tree, 0))
    {
        return true;
    }
    return false;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
            in[i] = pre[i];
        }
        sort(in, in + n, cmp);
        Node *tree = build(0, n, n);
        if (isredblack(tree))
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }

    return 0;
}