#include <cstdio>
#include <iostream>

class Stack {
    private:
        static const int MAX  {50};
        int items[MAX];
        int top;
    public:
        Stack();
        bool isEmpty();
        bool isFull();
        bool push(int item);
        int pop();
        int peek();
};

Stack::Stack() {
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == MAX - 1;
}

bool Stack::push(int item) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return false;
    }
    items[++top] = item;
    return true;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow! Cannot pop from empty stack" << std::endl;
        return -1;
    }
    return items[top--];
}

int Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty! Cannot peek" << std::endl;
        return -1;
    }
    return items[top];
}