//1. Building Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

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

//2. Searching in Balanced binary search tree which is sorted
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

bool binarySearchTree(node *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    else if (number < root->number)
    {
        return binarySearchTree(root->left, number);
    }
    else if (number > root->number)
    {
        return binarySearchTree(root->right, number);
    }
    else
    {
        return true;
    }

}

int main(void)
{
    node *root = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
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

    n->number = 5;
    n->left = NULL;
    n->right = NULL;
    root->right = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    root->left->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    root->left->right = n;
    
    printf("%d %d %d %d %d\n", root->number, root->left->number, root->right->number, root->left->left->number, root->left->right->number);

    bool find = binarySearchTree(root, 1);
    
    if (find == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }

    return 0;

}
//3. Correct code. Printing tree, freeing tree and searching

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    print_tree(root->left);
    printf("%d\n", root->number);
    print_tree(root->right);
}

bool binarySearchTree(node *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    else if (number < root->number)
    {
        return binarySearchTree(root->left, number);
    }
    else if (number > root->number)
    {
        return binarySearchTree(root->right, number);
    }
    else
    {
        return true;
    }

}

int main(void)
{
    node *root = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
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

    n->number = 5;
    n->left = NULL;
    n->right = NULL;
    root->right = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    root->left->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    root->left->right = n;
    
    print_tree(root);
    free_tree(root);

    return 0;

}

