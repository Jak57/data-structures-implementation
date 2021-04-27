#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

bool binarySearchTree(node *root, int number)
{

}

int main(void)
{
    node *root = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    root = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    root->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    root->right = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
    n->left = NULL;
    n->right = NULL;
    root->left->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 5;
    n->left = NULL;
    n->right = NULL;
    root->left->right = n;

    printf("%d %d %d %d %d\n", root->number, root->left->number, root->right->number, root->left->left->number, root->left->right->number);

    return 0;

}
