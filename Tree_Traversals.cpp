#include <iostream>

using namespace std;

int n;

struct Tree
{
    int data;
    Tree *lchird;
    Tree *rchird;
};

Tree *build(int *i, int *j, int *porder, int *inorder)
{
    Tree *tree = new Tree;
    int *in;
    int l;
    for (int k = n - 1; k >= 0; k--)
    {
        for (l = 0; i + l <= j; l++)
        {
            if (porder[k] == *(i + l))
            {
                break;
            }
        }
        if (i + l > j)
        {
            l--;
        }

        if (porder[k] == *(i + l))
        {
            break;
        }
    }
    in = i + l;
    tree->data = *in;
    if (i <= in - 1)
    {
        tree->lchird = build(i, in - 1, porder, inorder);
    }
    if (i > in - 1)
    {
        tree->lchird = NULL;
    }
    if (in + 1 <= j)
    {
        tree->rchird = build(in + 1, j, porder, inorder);
    }
    if (in + 1 > j)
    {
        tree->rchird = NULL;
    }
    return tree;
}

int main()
{
    cin >> n;
    int porder[30];
    int inorder[30];
    for (int i = 0; i < n; i++)
    {
        cin >> porder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    int *i, *j;
    i = inorder;
    j = &inorder[n - 1];
    Tree *tree;
    tree = build(i, j, porder, inorder);
    int m, front, rear;
    m = front = rear = 0;
    Tree *que[31];
    Tree *p;
    int lorder[30] = {0};
    if (tree != NULL)
    {
        rear++;
        que[rear] = tree;
        while (front != rear)
        {
            front++;
            p = que[front];
            lorder[m] = p->data;
            if (p->lchird != NULL)
            {
                rear++;
                que[rear] = p->lchird;
            }
            if (p->rchird != NULL)
            {
                rear++;
                que[rear] = p->rchird;
            }
            m++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << lorder[i] << " ";
    }
    cout << lorder[n - 1];

    return 0;
}