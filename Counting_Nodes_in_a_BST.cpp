#include <iostream>

using namespace std;

struct Tree
{
    int data;
    Tree *lchild = NULL;
    Tree *rchild = NULL;
};

int ma = 0;

int order(Tree *tree, int deep)
{
    if (deep > ma)
    {
        ma = deep;
    }
    if (tree->lchild != NULL)
    {
        order(tree->lchild, deep + 1);
    }
    if (tree->rchild != NULL)
    {
        order(tree->rchild, deep + 1);
    }

    return 0;
}

int inorder(Tree *tree, int deep, int &n1, int &n2)
{
    if (deep == ma)
    {
        n1++;
    }
    if (deep == ma - 1)
    {
        n2++;
    }
    if (tree->lchild != NULL)
    {
        inorder(tree->lchild, deep + 1,n1,n2);
    }
    if (tree->rchild != NULL)
    {
        inorder(tree->rchild, deep + 1,n1,n2);
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    Tree *tree = new Tree;
    cin >> tree->data;
    for (int i = 1; i < n; i++)
    {
        Tree *p = new Tree;
        cin >> p->data;
        Tree *q = tree;
        Tree *now = tree;
        while (q != NULL)
        {
            now = q;
            if (q->data >= p->data)
            {
                q = q->lchild;
            }
            else
            {
                q = q->rchild;
            }
        }
        if (now->data >= p->data)
        {
            now->lchild = p;
        }
        else
        {
            now->rchild = p;
        }
    }
    order(tree, 0);
    int n1 = 0, n2 = 0;
    inorder(tree, 0, n1, n2);
    cout << n1 << " + " << n2 << " = " << n1 + n2;

    return 0;
}