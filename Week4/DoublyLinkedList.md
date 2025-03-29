### Doubly Linked list
![image](https://github.com/user-attachments/assets/46e0c77e-e88c-4f0d-b3ad-20e580e1e2f9)



```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list (forward direction)
    struct Node* back;  // Pointer to the previous node in the list (backward direction)
} Node;

// Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
Node* create_node(int data1, Node* next1, Node* back1) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    new_node->data = data1;
    new_node->next = next1;
    new_node->back = back1;
    return new_node;
}

// Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
Node* create_node_with_data(int data1) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    new_node->data = data1;
    new_node->next = NULL;
    new_node->back = NULL;
    return new_node;
}

int main() {
    // Example usage
    Node* node1 = create_node_with_data(10);
    Node* node2 = create_node(20, NULL, node1);
    node1->next = node2;

    printf("Node1 data: %d, Node2 data: %d\n", node1->data, node2->data);

    // Free allocated memory
    free(node1);
    free(node2);

    return 0;
}

```

```cpp
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
        back = back1; // Addition of 'back' pointer for the doubly linked list.
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr; // Similar to a singly linked list.
        back = nullptr; // Addition of 'back' pointer initialization.
    }
};
```

```java
public class Node {
    public int data;       // Data stored in the node
    public Node next;      // Reference to the next node in the list (forward direction)
    public Node back;      // Reference to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    public Node(int data, Node next, Node back) {
        this.data = data;
        this.next = next;
        this.back = back;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    public Node(int data) {
        this.data = data;
        this.next = null;
        this.back = null;
    }
}
```
