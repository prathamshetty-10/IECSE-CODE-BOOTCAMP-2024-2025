# Explaination:
## What is a Monotonic Stack:
### Overview

A monotonic stack is a specialized stack data structure that maintains elements in either strictly increasing or decreasing order. This ordered arrangement enables efficient solutions to problems requiring identification of next/previous greater/smaller elements, range queries, and pattern recognition in sequences. Unlike standard stacks, monotonic variants enforce ordering constraints during insertion operations through strategic element removal, creating optimized pathways for solving complex array processing tasks.

### Core Properties and Structural Characteristics

#### Order Preservation Mechanism

Monotonic stacks dynamically maintain element order through conditional insertion protocols:

1. **Increasing Order**: Each new element triggers removal of all preceding larger values until encountering a smaller or equal element.
2. **Decreasing Order**: Insertions require elimination of preceding smaller elements until locating a larger or equal comparator.

This self-correcting behavior ensures the stack's elements always adhere to the chosen monotonic property, whether increasing or decreasing. The ordering direction depends on the problem's requirements - decreasing stacks typically identify next larger elements while increasing stacks find next smaller counterparts.

#### Element Lifecycle Management

Each element undergoes two atomic operations:

1. **Insertion**: Potential predecessor removal (`O(1)` amortized via aggregate analysis)
2. **Retention**: Continuous existence until superseded by qualifying successors

This dual-phase handling creates implicit associations between stack elements and their contextual relationships within the processed sequence.

### Operational Workflow and Algorithmic Patterns

#### Standard Insertion Protocol
- C++:
```C++
    vector<T> monotonicStack(const std::vector<T>& sequence) {
        std::vector<T> stack;
        
        for (const T& element : sequence) {
            while (!stack.empty() && violatesOrder(stack.back(), element)) {
                process(stack.back());
                stack.pop_back();
            }
            stack.push_back(element);
        }
        
        return stack;
    }
```
- Go:
```go
func monotonicStack(sequence []T) []T {
    stack := make([]T, 0)
    
    for _, element := range sequence {
        for len(stack) > 0 && violatesOrder(stack[len(stack)-1], element) {
            process(stack[len(stack)-1])
            stack = stack[:len(stack)-1]
        }
        stack = append(stack, element)
    }
    
    return stack
}
```
- Python:
```python  
def monotonic_stack(sequence):
    stack = []
    for element in sequence:
        while stack and violates_order(stack[-1], element):
            process(stack.pop())
        stack.append(element)
    return stack
```

*Process varies based on application requirements*

#### Key Operational Phases

1. **Pre-Insertion Validation**
    - Compare new element against stack top
    - Remove conflicting elements violating monotonicity
2. **Post-Removal Processing**
    - Capture relationships between removed elements and current element
    - Update result arrays with computed values (e.g., next greater element indices)
3. **Element Finalization**
    - Append current element to stack after constraint satisfaction

### Computational Complexity Analysis

#### Time Efficiency

Despite nested loop appearances, the algorithm achieves **O(n)** time complexity through amortized analysis:

- Each element enters stack **once** (O(n) total pushes)
- Each element exits stack **at most once** (O(n) total pops)
- Total operations bounded by 2n → O(n)


#### Space Requirements

- Worst-case **O(n)** auxiliary storage when input sequence is already monotonic
- Average-case typically matches worst-case due to stack's order preservation

## Algorithm Overview

This solution calculates final prices for items in a shop where each item receives a discount equal to the first subsequent price that is less than or equal to its original price. The implementation uses a **monotonic stack** approach to achieve O(n) time complexity, significantly outperforming naive O(n²) methods.

## Core Strategy

### Monotonic Stack Utilization

The algorithm maintains a stack of indices representing items **awaiting discount discovery**. The stack preserves a **non-increasing order** of prices corresponding to these indices. This structure enables efficient identification of valid discounts while processing prices sequentially.

## Operational Workflow

### Key Data Structures

- **Result Array**: Stores final prices after applying discounts
- **Index Stack**: Tracks positions of items needing discount resolution


### Primary Processing Phase

1. **Iterate through prices** from left to right
2. For each price:
    - **Resolve pending discounts**: Compare current price with stacked indices
    - **Apply discounts**: For all stacked items where current price ≤ their price
        - Calculate discount as `stacked_price - current_price`
        - Update corresponding result entry
    - **Add current index** to the stack after resolving applicable discounts

### Post-Processing Phase

- **Handle unresolved items**: Any indices remaining in the stack after main processing receive no discount
- **Set final prices** for these items to their original values


## Time Complexity

- **O(n)** for all operations
    - Each index enters/leaves the stack exactly once
    - Constant-time operations per price element


## Space Complexity

- **O(n)** for stack storage and result array
- Optimal for problem constraints with linear space requirements


## Critical Observations

### Stack Behavior Characteristics

- Maintains **price monotonicity** ensuring efficient discount resolution
- Enables **single-pass processing** through clever backtracking
- Automatically handles nested discount relationships


### Edge Case Handling

- **No subsequent discount**: Automatically detected in post-processing
- **Equal prices**: Correctly triggers discount application
- **Ascending price sequences**: Stack remains populated until descending price found


## Performance Advantages

### Comparative Efficiency

- Eliminates redundant comparisons through state tracking
- Avoids quadratic explosion in worst-case scenarios
- Enables real-time processing of large datasets


### Implementation Benefits

- Minimal conditional checks
- Straightforward index management
- Clear separation of main logic and cleanup

This approach demonstrates how careful data structure selection transforms an apparently `O(n²)` problem into linear-time complexity while maintaining code simplicity and operational efficiency.


# Solutions:
## C:
```C
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* res = (int*)malloc(pricesSize * sizeof(int));
    int* stack = (int*)malloc(pricesSize * sizeof(int));
    int top = -1;
    *returnSize = pricesSize;    
    for (int i = 0; i < pricesSize; i++) {
        while (top >= 0 && prices[stack[top]] >= prices[i]) {
            int id = stack[top];
            top--;
            res[id] = prices[id] - prices[i];
        }
        top++;
        stack[top] = i;
    }    
    while (top >= 0) {
        int id = stack[top];
        res[id] = prices[id];
        top--;
    }    
    free(stack);
    return res;
}
```
## C++:
```C++
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        stack<int> s;        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && prices[s.top()] >= prices[i]) {
                int id = s.top();
                s.pop();
                res[id] = prices[id] - prices[i];
            }
            s.push(i);
        }        
        while (!s.empty()) {
            int id = s.top();
            res[id] = prices[id];
            s.pop();
        }        
        return res;
    }
};
```

## Java:
```Java
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();        
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && prices[stack.peek()] >= prices[i]) {
                int id = stack.pop();
                res[id] = prices[id] - prices[i];
            }
            stack.push(i);
        }        
        while (!stack.isEmpty()) {
            int id = stack.pop();
            res[id] = prices[id];
        }        
        return res;
    }
}
```

## C#:
```C#
public class Solution {
    public int[] FinalPrices(int[] prices) {
        int n = prices.Length;
        int[] res = new int[n];
        Stack<int> stack = new Stack<int>();        
        for (int i = 0; i < n; i++) {
            while (stack.Count > 0 && prices[stack.Peek()] >= prices[i]) {
                int id = stack.Pop();
                res[id] = prices[id] - prices[i];
            }
            stack.Push(i);
        }        
        while (stack.Count > 0) {
            int id = stack.Pop();
            res[id] = prices[id];
        }        
        return res;
    }
}
```
## Go:
```Go
func finalPrices(prices []int) []int {
    n := len(prices);
    res := make([]int, n)
    s := []int{}
    for i := 0; i < n; i++{
        for len(s) > 0 &&  prices[s[len(s)-1]] >= prices[i]{
            id := s[len(s)-1]
            s = s[:len(s)-1]
            res[id] = prices[id] - prices[i]
        }
        s = append(s,i)
    }
    for _, id := range s{
        res[id] = prices[id];
    }
    return res
}
```

## Python3:
```Python
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        res = [0] * n
        stack = []
        
        for i in range(n):
            while stack and prices[stack[-1]] >= prices[i]:
                idx = stack.pop()
                res[idx] = prices[idx] - prices[i]
            stack.append(i)
            
        for idx in stack:
            res[idx] = prices[idx]
            
        return res
```