# Stack Fundamentals
A stack is a linear data structure following Last In First Out (LIFO) principles. Elements are added/removed from one end (top). Analogy: A stack of plates.

# Core Operations
- `Push`: Add an element to the top.

- `Pop`: Remove the top element.

- `Peek/Top`: Return the top element without removal.

- `isEmpty`: Check if the stack has no elements.

- `isFull`: Check if the stack has reached capacity (array-based).

# Implementation Variants
1. Array-based
    - Pros: Cache-friendly (contiguous memory), minimal overhead.

    - Cons: Fixed size (static arrays), costly resizing (dynamic arrays).

    - Overflow risk if capacity is exceeded.

2. Linked List-based
    - Pros: Dynamic sizing, no overflow (until memory exhaustion).

    - Cons: Pointer overhead, poor cache locality.

# Role in Recursion
- **Call Stack Management:** Each recursive call creates a stack frame storing parameters, local variables, and return addresses.

- **Execution Context:** The system stack ensures nested function calls return correctly. Without stacks, recursion would fail due to lost context.

- *Example:*   
Factorial calculation. Each recursive call pushes a frame; returns unwind the stack.

# Key Applications
- **Function Call Management**: Tracks nested/recursive calls (e.g., main() → func1() → func2()).

- **Expression Evaluation**: Parses arithmetic/parentheses (e.g., converting infix to postfix).

- **Undo/Redo Mechanisms**: Each action is pushed; undo pops the last action.

- **Backtracking Algorithms**: Maze-solving via trial-and-error (push paths; pop on dead ends).

- **Compiler Design**: Syntax validation (e.g., matching braces).

# Why Stacks Matter
- **Memory Efficiency:** Automatically allocates/deallocates temporary data (e.g., local variables).

- **Algorithmic Foundation:** Critical for DFS (Depth-First Search), tree traversals, and parsing.

- **System-Level Relevance:** CPU architectures use hardware stacks for interrupt handling