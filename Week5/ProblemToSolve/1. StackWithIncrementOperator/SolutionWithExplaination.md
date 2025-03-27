# Explaination:
## Overview
This implementation of the CustomStack class provides a solution for a stack data structure that allows push, pop, and a special increment operation on its elements.

## The Implementation Approach
The implementation uses a simple array-based approach with the following components:

- An integer array to store the stack elements

- A variable to track the top element's position (initially set to -1 to indicate an empty stack)

- A fixed maximum size determined at initialization

## Key Operations
1. Constructor  
The constructor initializes the stack with the specified maximum size. It creates an array of that size and sets the top pointer to -1, indicating an empty stack.

2. Push Operation  
When pushing an element to the stack:
    - First check if the stack is full (top index equals maximum size minus 1)

    - If full, do nothing and return

    - If not full, increment the top pointer and place the new element at that position

3. Pop Operation  
When popping an element from the stack:

    - First check if the stack is empty (top equals -1)

    - If empty, return -1 as specified

    - If not empty, return the element at the top position and decrement the top pointer

4. Increment Operation
The increment operation increases the values of the bottom elements:

    - Loop through the first k elements of the stack (or all elements if there are fewer than k)

    - For each element, add the specified value to it

## Time and Space Complexity
Space Complexity: `O(n)` where n is the maxSize

Time Complexity:

- Push: `O(1)`

- Pop: `O(1)`

- Increment: `O(k)` where k is the number of elements to increment

## <i>Optimization Opportunity
The current implementation of the increment operation is `O(k)` because it iterates through each element to be incremented. A more efficient approach could use lazy propagation to achieve `O(1)` time complexity for increment operations, by tracking increments separately and applying them only when elements are accessed or popped. </i>

# Solution:
## C:
```C
#include <stdlib.h>

typedef struct {
    int* stack;
    int top;
    int maxSize;
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->stack = (int*)malloc(maxSize * sizeof(int));
    obj->top = -1;
    obj->maxSize = maxSize;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top == obj->maxSize - 1) {
        return;
    }
    obj->stack[++obj->top] = x;
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    return obj->stack[obj->top--];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    for (int i = 0; i < k && i <= obj->top; i++) {
        obj->stack[i] += val;
    }
}
```

## C++
```C++
class CustomStack {
private:
    vector<int> stack;
    int top;
    int maxSize;
    
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top = -1;
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (top == maxSize - 1) {
            return;
        }
        stack[++top] = x;
    }
    
    int pop() {
        if (top == -1) {
            return -1;
        }
        return stack[top--];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i <= top; i++) {
            stack[i] += val;
        }
    }
};
```

## Java:
```Java
class CustomStack {
        int [] stack;
        int top;
    public CustomStack(int maxSize) {
        stack = new int[maxSize];
        top = -1;
    }
    
    public void push(int x) {
        if(top == stack.length-1)
        {
            return;
        }
        else{
            stack[++top] = x;
        }
    }
    
    public int pop() {
        if(top == -1)
        {
            return -1;
        }
        else{
            return stack[top--];
        }
    }
    
    public void increment(int k, int val) {
     for(int i = 0; i<k && i<=top;i++)
     {
        stack[i] += val;
     }
    }
}
```

## C#:
```C#
public class CustomStack {
    private int[] stack;
    private int top;
    
    public CustomStack(int maxSize) {
        stack = new int[maxSize];
        top = -1;
    }
    
    public void Push(int x) {
        if (top == stack.Length - 1) {
            return;
        }
        stack[++top] = x;
    }
    
    public int Pop() {
        if (top == -1) {
            return -1;
        }
        return stack[top--];
    }
    
    public void Increment(int k, int val) {
        for (int i = 0; i < k && i <= top; i++) {
            stack[i] += val;
        }
    }
}
```

## Go:
```Go
type CustomStack struct {
    stack []int
    top   int
}

func Constructor(maxSize int) CustomStack {
    return CustomStack{
        stack: make([]int, maxSize),
        top:   -1,
    }
}

func (this *CustomStack) Push(x int) {
    if this.top == len(this.stack)-1 {
        return
    }
    this.top++
    this.stack[this.top] = x
}

func (this *CustomStack) Pop() int {
    if this.top == -1 {
        return -1
    }
    val := this.stack[this.top]
    this.top--
    return val
}

func (this *CustomStack) Increment(k int, val int) {
    for i := 0; i < k && i <= this.top; i++ {
        this.stack[i] += val
    }
}
```

## Python3:
```Python
class CustomStack:
    def __init__(self, maxSize: int):
        self.stack = [0] * maxSize
        self.top = -1
        
    def push(self, x: int) -> None:
        if self.top == len(self.stack) - 1:
            return
        self.top += 1
        self.stack[self.top] = x
        
    def pop(self) -> int:
        if self.top == -1:
            return -1
        val = self.stack[self.top]
        self.top -= 1
        return val
    
    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.top + 1)):
            self.stack[i] += val
```

