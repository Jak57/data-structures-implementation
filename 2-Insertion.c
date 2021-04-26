1. // Insert at beginning
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

    for (int i = 0; i < 4; i++)
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

    // Inserting node in beginning
    // O(1) insertion
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 5;
    n->next = NULL;

    n->next = list;
    list = n;

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

2. // Insert at middle
    
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
    
    for (int i = 0; i < 4; i++)
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
        if (tmp->number == 3)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return 1;
            }
            
            n->number = 5;
            n->next = tmp->next;
            tmp->next = n;
            
        }
    }
    
    while (list != NULL)
    {
        printf("%d\n", list->number);
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    
}
