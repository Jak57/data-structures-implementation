#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *table[2];


int main(void)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->next = NULL;
    table[0] = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    table[0]->next = n;

    //n = malloc(sizeof(node));
    //2nd element
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    table[1] = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
    n->next = NULL;
    table[1]->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 5;
    n->next = NULL;
    table[1]->next->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 5;
    n->next = NULL;
    table[1]->next->next->next = n;

    for (int i = 0; i < 2; i++)
    {
        node *list = table[i];
        for (node *tmp = list; tmp != NULL; tmp = tmp->next)
        {
            printf("%d ", tmp->number);
        }
        printf("\n");
    }

}
