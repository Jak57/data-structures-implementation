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
