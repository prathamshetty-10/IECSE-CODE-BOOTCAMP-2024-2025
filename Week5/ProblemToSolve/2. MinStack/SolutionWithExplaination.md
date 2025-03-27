# Explaination:
## Core Concept

This solution implements a specialized stack that maintains O(1) time complexity for all operations including minimum value retrieval through a **dual-stack architecture**. The system combines a primary stack for standard operations with a secondary stack dedicated to tracking minimum values at each operational state.

## Structural Design

### Dual-Stack Configuration

1. **Primary Stack**
    - Stores all elements following standard Last-In-First-Out (LIFO) behavior
2. **Minimum History Stack**
    - Maintains parallel entries representing the minimum value **observed up to each corresponding position** in the primary stack
    - Each position i contains the minimum value between element i and all elements below it in the stack

### State Tracking Mechanism

- **Initialization**: Both stacks start empty with a top pointer at -1 (empty state indicator)
- **Pointer Management**: A single integer tracks the current top position of both stacks simultaneously


## Operational Workflow

### Push Operation

1. Add new element to the primary stack
2. Update minimum stack:
    - **First element**: Directly becomes the new minimum
    - **Subsequent elements**: Compare new value with current minimum (top of minimum stack)
    - Store the smaller value in the minimum stack
3. Increment top pointer



### Pop Operation

1. Remove top element from **both** stacks
2. Decrement top pointer

*Critical Property*: Synchronized stack modifications ensure minimum history remains accurate after each removal

### Top Operation

Return the top element of the primary stack

### Minimum Retrieval

Return the top element of the minimum stack

## Performance Characteristics

### Time Complexity

- **All operations**: O(1)
    - Push: Two constant-time append operations and one comparison
    - Pop: Two constant-time slice truncations
    - Top/Minimum: Direct array access


### Space Complexity

- O(n) additional space for maintaining parallel minimum history
- Trade-off: Accepts doubled storage requirements to achieve optimal time efficiency


## Design Advantages

1. **State Consistency**: Minimum values remain valid through all stack modifications
2. **Operational Simplicity**: Avoids complex recalculation mechanisms
3. **Bounded Operations**: No worst-case degradation in performance

## Implementation Considerations

### Edge Case Handling

- **Empty Stack**: All operations assume non-empty state per problem constraints
- **Value Equality**: Handles duplicate minimum values through repeated entries


### <i>Optimization Potential

While this implementation uses O(n) extra space, alternative approaches using single-stack encoding or delta storage could reduce space usage while maintaining O(1) operations. The presented solution prioritizes implementation clarity and operational efficiency.</i>

# Solution:
## C:
```C
typedef struct {
    int* stack;
    int* minStack;
    int top;
    int minTop;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10000;
    obj->stack = (int*)malloc(obj->capacity * sizeof(int));
    obj->minStack = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minTop++;
        obj->minStack[obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
```

## C++
```C++
class MinStack {
private:
    stack<int> s;
    stack<int> mins;
    
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        }
    }
    
    void pop() {
        if (s.top() == mins.top()) {
            mins.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
```

## Java:
```Java
class MinStack {
    private ArrayList<Integer> stack;
    private ArrayList<Integer> minStack;
    
    public MinStack() {
        stack = new ArrayList<>();
        minStack = new ArrayList<>();
    }
    
    public void push(int val) {
        stack.add(val);
        if (minStack.isEmpty() || val <= minStack.get(minStack.size() - 1)) {
            minStack.add(val);
        }
    }
    
    public void pop() {
        if (!stack.isEmpty()) {
            if (stack.get(stack.size() - 1).equals(minStack.get(minStack.size() - 1))) {
                minStack.remove(minStack.size() - 1);
            }
            stack.remove(stack.size() - 1);
        }
    }
    
    public int top() {
        return stack.get(stack.size() - 1);
    }
    
    public int getMin() {
        return minStack.get(minStack.size() - 1);
    }
}
```

## C#:
```C#
public class MinStack {
    private Stack<int> stack;
    private Stack<int> minStack;
    
    public MinStack() {
        stack = new Stack<int>();
        minStack = new Stack<int>();
    }
    
    public void Push(int val) {
        stack.Push(val);
        if (minStack.Count == 0 || val <= minStack.Peek()) {
            minStack.Push(val);
        }
    }
    
    public void Pop() {
        if (stack.Count > 0) {
            if (stack.Peek() == minStack.Peek()) {
                minStack.Pop();
            }
            stack.Pop();
        }
    }
    
    public int Top() {
        return stack.Peek();
    }
    
    public int GetMin() {
        return minStack.Peek();
    }
}
```

## Go:
```Go
type MinStack struct {
    stack    []int
    minStack []int
}

func Constructor() MinStack {
    return MinStack{
        stack:    make([]int, 0),
        minStack: make([]int, 0),
    }
}

func (this *MinStack) Push(val int) {
    this.stack = append(this.stack, val)
    if len(this.minStack) == 0 || val <= this.minStack[len(this.minStack)-1] {
        this.minStack = append(this.minStack, val)
    }
}

func (this *MinStack) Pop() {
    if len(this.stack) > 0 {
        if this.stack[len(this.stack)-1] == this.minStack[len(this.minStack)-1] {
            this.minStack = this.minStack[:len(this.minStack)-1]
        }
        this.stack = this.stack[:len(this.stack)-1]
    }
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1]
}

func (this *MinStack) GetMin() int {
    return this.minStack[len(this.minStack)-1]
}
```

## Python3:
```Python
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []
        
    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
            
    def pop(self) -> None:
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()
        
    def top(self) -> int:
        return self.stack[-1]
        
    def getMin(self) -> int:
        return self.min_stack[-1]
```