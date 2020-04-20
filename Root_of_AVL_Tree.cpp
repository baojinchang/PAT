#include<iostream>

using namespace std;

struct Tree
{
    int node;
    Tree *lchild = NULL;
    Tree *rchild = NULL;
};

int main()
{
    int n;
    cin >> n;
    Tree *tree = new Tree;
    cin >> tree->node;
    for (int i = 1; i < n; i++)
    {
        
    }
    

    return 0;
}