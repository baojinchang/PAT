#include<iostream>

using namespace std;

struct Node
{
    int data, height;
    Node *lchild = NULL;
    Node *rchild = NULL;
};

Node *newnode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->height = 1;
    return node;
}

int getheight(Node *node)
{
    if (node==NULL)
    {
        return 0;
    }
    return node->height;
}

int getbf(Node *node)
{
    return getheight(node->lchild) - getheight(node->rchild);
}

void updataheight(Node *node)
{
    if (getheight(node->lchild)>getheight(node->rchild))
    {
        node->height = getheight(node->lchild) + 1;
    }
    else
    {
        node->height = getheight(node->rchild) + 1;
    }
}

void left(Node* &root)
{
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updataheight(root);
    updataheight(temp);
    root = temp;
}

void right(Node* &root)
{
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updataheight(root);
    updataheight(temp);
    root = temp;
}

int insert(Node* &root,int data)
{
    if (root==NULL)
    {
        root = newnode(data);
        return 0;
    }
    if (data<=root->data)
    {
        insert(root->lchild, data);
        updataheight(root);
        if (getbf(root)==2)
        {
            if (getbf(root->lchild)==1)
            {
                right(root);
            }
            else if (getbf(root->lchild)==-1)
            {
                left(root->lchild);
                right(root);
            }
        }
    }
    else
    {
        insert(root->rchild, data);
        updataheight(root);
        if (getbf(root)==-2)
        {
            if (getbf(root->rchild)==-1)
            {
                left(root);
            }
            else if (getbf(root->rchild)==1)
            {
                right(root->rchild);
                left(root);
            }
        }
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        insert(root, temp);
    }
    cout << root->data;

    return 0;
}