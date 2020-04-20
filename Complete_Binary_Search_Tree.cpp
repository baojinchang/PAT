#include<iostream>
#include<algorithm>

using namespace std;

struct Tree
{
    int id;
    Tree *lchild = NULL;
    Tree *rchild = NULL;
};

int invist(Tree *tree,int order[],int &i)
{
    if (tree->lchild!=NULL)
    {
        invist(tree->lchild, order, i);
    }
    order[i++] = tree->id;
    if (tree->rchild!=NULL)
    {
        invist(tree->rchild, order, i);
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    int *number = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    Tree *tree[n];
    tree[0] = new Tree;
    tree[0]->id = 0;
    for (int i = 1; i < n; i++)
    {
        tree[i] = new Tree;
        tree[i]->id = i;
        int temp = (i - 1) / 2;
        if (i%2==0)
        {
            tree[temp]->rchild = tree[i];
        }
        else
        {
            tree[temp]->lchild = tree[i];
        }
    }
    int *order = new int[n];
    int count = 0;
    invist(tree[0], order, count);
    sort(number, number + n);
    for (int i = 0; i < n-1; i++)
    {
        int j;
        for ( j = 0; i < n; j++)
        {
            if (order[j]==i)
            {
                break;
            }
        }
        cout << number[j] << " ";
    }
    int i;
    for ( i = 0; i < n; i++)
    {
        if (order[i]==n-1)
        {
            break;
        }
    }
    cout << number[i];

    return 0;
}