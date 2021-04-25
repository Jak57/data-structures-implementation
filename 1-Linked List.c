1.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next->next);
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 4;
    n->next = NULL;
    list->next->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%d %p\n", tmp->number, tmp->next);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

}
2. Efficient Version

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;
    node *aux = NULL;
    
    for (int i = 0; i < 10; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Freeing heap memory
            while (list != NULL)
            {
                node *tmp = list->next;
                free(list);
                list = tmp;
            }
            return 1;
        }
        
        n->number = i + 1;
        n->next = NULL;
        
        if (i == 0)
        {
            list = n;
            aux = n;
        }
        else 
        {
            aux->next = n;
            aux = n;
        }
    }
    
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%d %p\n", tmp->number, tmp->next);
    }
    
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    
}
