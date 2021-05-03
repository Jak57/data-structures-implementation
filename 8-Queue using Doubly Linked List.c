#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *prev;
    struct node *next;
}
node;

node *head;
node *tail;

// Removing element from the queue
int dequeue()
{
    int value;
    value = head->number;

    (head->prev)->next = NULL;
    head = head->prev;

    return value;
}

// Adding node to the queue
void enqueue(int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }

    n->number = value;
    n->next = NULL;
    n->prev = NULL;

    if (head == NULL && tail == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->next = tail;
        tail->prev = n;
        tail = n;
    }
}

int main(void)
{
    int number, x;
    number = 1;
    enqueue(number);

    number = 2;
    enqueue(number);

    number = 3;
    enqueue(number);

    for (node *tmp = tail; tmp != NULL; tmp = tmp->next)
    {
        printf("%d\n", tmp->number);
    }

    x = dequeue();
    printf("H: %d\n", x);

    x = dequeue();
    printf("H: %d\n", x);

    for (node *tmp = tail; tmp != NULL; tmp = tmp->next)
    {
        printf("%d\n", tmp->number);
    }

}
