### Search an element in the linked list

Given a singly linked list, search for a node containing a specific value. The function should return true if the value is found, and false if the value is not present in the list.
<br>
c, cpp and java codes 

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function to check if a given element is present in the linked list
int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    // Traverse the linked list
    while (temp != NULL) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found

        // Move to the next node
        temp = temp->next;
    }

    return 0;  // Return 0 if the element is not found in the linked list
}

int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    int val = 5;  // Element to be checked for presence in the linked list

    // Call the checkifPresent function and print the result
    printf("%d\n", checkifPresent(head, val));

    return 0;  // Return 0 to indicate successful execution
}

```

```cpp
// Node class represents a node in a linked list
class Node {
public:
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node in the      list

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to check if a given element is present in the linked list
int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    // Traverse the linked list
    while (temp != nullptr) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found

        // Move to the next node
        temp = temp->next;
    }

    return 0;  // Return 0 if the element is not found in the linked list
}

// Main function
int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int val = 5;  // Element to be checked for presence in the linked list

    // Call the checkifPresent function and print the result
    cout << checkifPresent(head, val) << '\n';

    return 0;  // Return 0 to indicate successful execution
}
```

```cpp
// Node class represents a node in a linked list
class Node {
    int data;      // Data stored in the node
    Node next;     // Reference to the next node in the list

    // Constructor with both data and next node as parameters
    Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1;
    }

    // Constructor with only data as a parameter, sets next to null
    Node(int data1) {
        this.data = data1;
        this.next = null;
    }
}

// LinkedList class contains utility methods for linked list operations
public class LinkedList {

    // Function to check if a given element is present in the linked list
    public static int checkifPresent(Node head, int desiredElement) {
        Node temp = head;

        // Traverse the linked list
        while (temp != null) {
            // Check if the current node's data is equal to the desired element
            if (temp.data == desiredElement)
                return 1;  // Return 1 if the element is found

            // Move to the next node
            temp = temp.next;
        }

        return 0;  // Return 0 if the element is not found in the linked list
    }

    // Main function
    public static void main(String[] args) {
        // Create a linked list: 1 -> 2 -> 3
        int[] arr = {1, 2, 3};
        Node head = new Node(arr[0]);
        head.next = new Node(arr[1]);
        head.next.next = new Node(arr[2]);

        int val = 3;  // Element to be checked for presence in the linked list

        // Call the checkifPresent function and print the result
        System.out.print(checkifPresent(head, val));
    }
}
```
