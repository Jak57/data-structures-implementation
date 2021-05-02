//1. Using array
#include <stdio.h>

const int CAPACITY = 100000;

typedef struct
{
    int array[100000];
    int top;
}
stack;

int size(stack *s)
{
    return s->top;
}

int pop(stack *s)
{
    int value;
    value = s->array[s->top];
    s->top -= 1;

    return value;
}

// If declare stack globally then don't have to pass address
void push(stack *s, int value)
{
    s->top += 1;
    s->array[s->top] = value;

}

int main(void)
{
    int value, x;
    stack s;
    s.top = -1;

    // Pushing element
    value = 1;
    push(&s, value);
    printf("%d\n", s.array[s.top]);

    value = 2;
    push(&s, value);
    printf("%d\n", s.array[s.top]);

    value = 3;
    push(&s, value);
    printf("%d\n", s.array[s.top]);

    value = 4;
    push(&s, value);
    printf("%d\n", s.array[s.top]);

    // Popping element
    x = pop(&s);
    printf("%d\n", x);

    x = pop(&s);
    printf("%d\n", x);

    // Size of stack

    printf("Size: %d\n", s.top + 1);


}

//2. Using Linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

// Declaring head globally so that don't have to pass address
node *head = NULL;

int size()
{
    int count = 0;
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        count++;
    }

    return count;
}

int pop()
{
    int value;
    node *tmp = head->next;

    value = head->value;
    free(head);
    head = tmp;

    return value;
}

void push(int value)
{
    //printf("%p\n", head);
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }

    n->value = value;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

int main(void)
{
    int value, x;
    //stack *head = NULL;

    value = 1;
    push(value);
    printf("%d\n", head->value);

    value = 2;
    push(value);
    printf("%d\n", head->value);

    value = 3;
    push(value);
    printf("%d\n", head->value);

    printf("Size: %d\n", size());

    x = pop();
    printf("%d\n", x);

    x = pop();
    printf("%d\n", x);

    x = pop();
    printf("%d\n", x);



}
