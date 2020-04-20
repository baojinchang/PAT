#include <iostream>

using namespace std;

struct Tree
{
    int data;
    Tree *lchild = NULL;
    Tree *rchild = NULL;
};

int pre(Tree *tree, int number[], int &i)
{
    number[i] = tree->data;
    i++;
    if (tree->lchild != NULL)
    {
        pre(tree->lchild, number, i);
    }
    if (tree->rchild != NULL)
    {
        pre(tree->rchild, number, i);
    }

    return 0;
}

int mirror(Tree *tree, int number[], int &i)
{
    number[i] = tree->data;
    i++;
    if (tree->rchild != NULL)
    {
        mirror(tree->rchild, number, i);
    }
    if (tree->lchild != NULL)
    {
        mirror(tree->lchild, number, i);
    }

    return 0;
}

int post(Tree *tree, int number[], int &i)
{
    if (tree->lchild != NULL)
    {
        post(tree->lchild, number, i);
    }
    if (tree->rchild != NULL)
    {
        post(tree->rchild, number, i);
    }
    number[i] = tree->data;
    i++;

    return 0;
}

int postmirr(Tree *tree, int number[], int &i)
{
    if (tree->rchild != NULL)
    {
        postmirr(tree->rchild, number, i);
    }
    if (tree->lchild != NULL)
    {
        postmirr(tree->lchild, number, i);
    }
    number[i] = tree->data;
    i++;

    return 0;
}

int main()
{
    int n;
    cin >> n;
    int *order = new int[n];
    Tree *tree = new Tree;
    cin >> tree->data;
    order[0] = tree->data;
    for (int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        order[i] = temp;
        Tree *p = new Tree;
        p->data = temp;
        Tree *q = tree;
        Tree *j = q;
        while (q != NULL)
        {
            j = q;
            if (p->data < q->data)
            {
                q = q->lchild;
            }
            else
            {
                q = q->rchild;
            }
        }
        if (p->data < j->data)
        {
            j->lchild = p;
        }
        else
        {
            j->rchild = p;
        }
    }
    int *number1 = new int[n];
    int *number2 = new int[n];
    int count = 0;
    pre(tree, number1, count);
    count = 0;
    mirror(tree, number2, count);
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (number1[i] != order[i])
        {
            break;
        }
    }
    for (j = 0; j < n; j++)
    {
        if (number2[j] != order[j])
        {
            break;
        }
    }
    delete[] number1;
    delete[] number2;
    delete[] order;
    if (i == n)
    {
        cout << "YES" << endl;
        int *number = new int[n];
        count = 0;
        post(tree, number, count);
        for (int i = 0; i < n - 1; i++)
        {
            cout << number[i] << " ";
        }
        cout << number[n - 1];
        delete[] number;
    }
    else if (j == n)
    {
        cout << "YES" << endl;
        int *number = new int[n];
        count = 0;
        postmirr(tree, number, count);
        for (int i = 0; i < n - 1; i++)
        {
            cout << number[i] << " ";
        }
        cout << number[n - 1];
        delete[] number;
    }
    else
    {
        cout << "NO";
    }

    return 0;
}