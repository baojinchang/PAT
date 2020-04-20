#include <iostream>
#include <string>

using namespace std;

struct Tree
{
    int count = 1;
    Tree *pre = NULL;
    Tree *lchild = NULL;
    Tree *rchild = NULL;
    int node;
};

int number[30];

int post(Tree *tree, int &i)
{
    if (tree->lchild != NULL)
    {
        post(tree->lchild, i);
    }
    if (tree->rchild != NULL)
    {
        post(tree->rchild, i);
    }
    number[i++] = tree->node;

    return 0;
}

int main()
{
    int n;
    cin >> n;
    Tree *tree = new Tree;
    string str;
    cin >> str;
    cin >> tree->node;
    Tree *p = tree;
    for (int i = 1; i < n * 2; i++)
    {
        cin >> str;
        if (str == "Push")
        {
            Tree *q = new Tree;
            cin >> q->node;
            if (p->lchild == NULL&&p->count==1)
            {
                p->lchild = q;
                q->pre = p;
                p = q;
            }
            else if (p->rchild == NULL&p->count==0)
            {
                p->rchild = q;
                q->pre = p;
                p = q;
            }
            else
            {
                while (p->lchild != NULL && p->rchild != NULL)
                {
                    p = p->pre;
                }
                if (p->lchild == NULL&&p->count==1)
                {
                    p->lchild = q;
                    q->pre = p;
                    p = q;
                }
                else
                {
                    p->rchild = q;
                    q->pre = p;
                    p = q;
                }
            }
        }
        else
        {
            if (p->count == 1)
            {
                p->count--;
            }
            else
            {
                p = p->pre;
            }
        }
    }
    int count = 0;
    post(tree, count);
    for (int i = 0; i < count; i++)
    {
        cout << number[i];
        if (i != count - 1)
        {
            cout << " ";
        }
    }

    return 0;
}