# Array-based Stack Implementation
In an array-based implementation, elements are stored in contiguous memory locations, with a 'top' variable tracking the index of the topmost element.

## How It Works
Initialize an array of fixed size and set top = -1 (indicating empty stack)

- `Push`: Increment top and place the new element at that index

- `Pop`: Return the element at top index and decrement top

- `Peek`: Return the element at top index without changing top

## Advantages
- Excellent cache locality with elements stored together in memory

- No overhead for storing pointers, reducing memory consumption

- Simpler implementation with direct index-based access

- Generally faster for fixed-size operations due to better CPU cache utilization

## Limitations
- Fixed size in static implementations requires predefined capacity

- Potential overflow if capacity is exceeded in static implementations

- Costly resizing operations in dynamic implementations (O(n) time complexity)

- May waste memory if allocated array is not fully utilized



# Linked List-based Stack Implementation
In a linked list implementation, each element is stored in a node containing the data and a pointer to the next node, with a 'top' pointer referencing the most recently added node.

## How It Works
Initialize a null pointer for the top of the stack

- `Push`: Create a new node, set its next pointer to current top, update top to the new node

- `Pop`: Store data from top node, update top to point to next node, free/delete original top node

- `Peek`: Return data from top node without modifying the structure

## Advantages
- Dynamic size that grows and shrinks as needed with no fixed capacity

- No need for costly resizing operations

- Consistent O(1) time complexity for all operations regardless of size

- No memory wastage for unused pre-allocated space

## Limitations
- Additional memory overhead for storing pointers in each node (4-8 bytes per node)

- Poorer cache locality with nodes potentially scattered throughout memory

- More complex implementation requiring node management

- Slightly higher memory consumption per element due to pointer overhead

# Comparison: Array vs. Linked List Stack Implementations
| Feature | Array-based Stack | Linked List-based Stack |
| :-- | :-- | :-- |
| Memory Allocation | Contiguous memory allocation, typically fixed size in static arrays or managed growth in dynamic arrays | Dynamic memory allocation, nodes scattered throughout memory |
| Size Limitation | Fixed size in static implementations; may need resizing in dynamic implementations | No fixed size limitation, can grow as needed until system memory is exhausted |
| Memory Efficiency | No overhead for pointers, but may waste space if pre-allocated array is not fully utilized | Additional memory overhead for storing pointers in each node (4-8 bytes per node) |
| Cache Locality | Excellent - elements are stored together in memory, leading to better CPU cache utilization | Poor - nodes can be scattered throughout memory, leading to more cache misses |
| Push Operation (Time Complexity) | O(1) typically, O(n) in worst case when resizing is needed | O(1) consistently |
| Pop Operation (Time Complexity) | O(1) | O(1) consistently |
| Peek Operation (Time Complexity) | O(1) | O(1) |
| Implementation Complexity | Simpler implementation with index-based access | More complex implementation requiring node management |
| Stack Overflow Handling | May overflow if size exceeds capacity in static implementation; requires resizing in dynamic implementation | No overflow until system memory is exhausted |
| Memory Usage Pattern | All memory allocated upfront or in chunks during resizing | Memory allocated only as needed, node by node |
| Performance with Large Data | Better for fixed-size stacks with frequent operations due to cache locality | Better for stacks with unpredictable size and less frequent operations |
