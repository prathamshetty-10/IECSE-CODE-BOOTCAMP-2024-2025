### Challenges with Arrays and Addressing these limitations with Linked List

- Fixed Size
    
    Arrays require a fixed size to be declared at the time of creation. If you overestimate, you waste memory; if you underestimate, you run out of space.
    
- Insertion and Deletion Complexity
    
    In arrays, inserting or deleting elements is expensive because it often involves shifting elements. For example:
    
    Inserting at the beginning: O(n) due to shifting.
    
    Deleting an element: O(n) due to shifting.
    
- Contiguous memory allocation
    
    Arrays require contiguous blocks of memory, which might not be available for large arrays.
    
- Expanding or Shrinking the Structure
    
    Resizing an array involves creating a new array and copying the elements, which is expensive (O(n)).
    
- Inefficient use of space
    
    Arrays can lead to memory wastage if the declared size exceeds the actual usage.
    

**Why Linked Lists?**

- **Fixed Size**: Linked lists dynamically allocate memory, avoiding the need for a fixed size.
- **Insertion and Deletion Complexity**: Linked lists allow constant-time insertion and deletion without shifting elements.
- **Contiguous Memory Allocation**: Linked lists use scattered memory, avoiding the need for contiguous blocks.
- **Expanding or Shrinking the Structure**: Linked lists can grow or shrink dynamically without resizing or copying.
- **Inefficient Use of Space**: Linked lists allocate memory as needed, reducing wasted space.
