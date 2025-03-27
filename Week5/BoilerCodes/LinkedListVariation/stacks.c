#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

//List of all method definitions
Stack* createStack();
void push(Stack* s, int data);
int pop(Stack* s);
int peek(Stack* s);
int isEmpty(Stack* s);
void destroyStack(Stack* s);

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s) {
        s->top = NULL;
        s->size = 0;
    }
    return s;
}

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = s->top;
        s->top = newNode;
        s->size++;
    }
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }    
    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->top->data;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void destroyStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}
