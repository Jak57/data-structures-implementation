#include <stdio.h>
#include <stdlib.h>

// Creating a node
typedef struct node
{
    int number;
    struct node *prev;
    struct node *next;
}
node;

node *head;

// Delete a node from a doubly linked list
void Delete(int value)
{
    for (node *tmp = head;  tmp != NULL; tmp = tmp->next)
    {
        if (tmp->number == value)
        {
            // Deleting first node
            if (tmp->prev == NULL)
            {
                head = tmp->next;
            }
            // Delete last node
            else if (tmp->next == NULL)
            {
                (tmp->prev)->next = NULL;
            }
            // Delete node at middle
            else
            {
                (tmp->prev)->next = tmp->next;
                (tmp->next)->prev = tmp->prev;
            }
        }
    }
}

// Insert to a doubly linked list
void insert(int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }

    n->number = value;
    n->prev = NULL;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
        //printf("%d\n", head->number);
    }
    else
    {
        head->prev = n;
        n->next = head;
        head = n;
        //printf("%d\n", head->number);
    }
}

int main(void)
{
    int number;
    number = 1;
    insert(number);

    number = 2;
    insert(number);

    number = 3;
    insert(number);

    number = 4;
    insert(number);

    number = 5;
    insert(number);

    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d %p %p\n", tmp->number, tmp->prev, tmp->next);
    }

    // Deleting
    number = 5;
    Delete(number);
    number = 2;
    Delete(number);

    printf("After deleting:\n");
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d %p %p\n", tmp->number, tmp->prev, tmp->next);
    }

    return 0;
}
