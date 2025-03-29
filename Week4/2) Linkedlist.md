# Linkedlist
It is a linear data structure that can be visualized as a chain with different nodes connected, where each node represents a different element. The difference between arrays and linked lists is that, unlike arrays, the elements are not stored at a contiguous location.

Imagine an element as a house. Arrays can be represented as houses next to each other on the same street. Like a neighborhood. 

In a linked list, you only know where the first house is. The address of the 2nd house is present in the first house. Similarly the address of the 3rd house is present in the 2nd house and so on.

Node- A **node** is a basic unit of a data structure, such as a linked list, tree, or graph.

![image](https://github.com/user-attachments/assets/48e055b3-8145-4bc8-bf9c-54b93d7e9d76)

```c
struct Node {
    int data;             // Data part
    struct Node* next;    // Pointer to the next node
};
```

```cpp
//c++ code for node
class Node {
    public:
        int data;         // Data stored in the node
        Node* next;       // Pointer to the next node in the linked list
       
        // Constructors
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
        // Constructor
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};
```

```java
//java code for a node
class Node {
    int data;// Data stored in the nodeNode next;// Reference to the next node in the linked list// Constructorpublic Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1;
    }
// Constructorpublic Node(int data1) {
        this.data = data1;
        this.next = null;
    }
}
```
