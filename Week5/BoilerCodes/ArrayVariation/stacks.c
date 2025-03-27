#include <stdio.h>

#define MAX 50

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return 0;
    }
    s->items[++s->top] = item;
    return 1;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    return s->items[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    }
    return s->items[s->top];
}
