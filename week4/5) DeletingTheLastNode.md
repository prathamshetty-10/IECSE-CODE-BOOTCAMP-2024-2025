### Deleting a node from the end of a linked list
Given a singly linked list, delete the last node from the list.


```c
//c code
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Delete the last node
    free(temp->next);
    
    // Set the next of the second last node to NULL, effectively removing the last node
    temp->next = NULL;
    
    // Return the head of the modified list
    return head;
}

int main() {
    // Initialize an array with values for the linked list
    int arr[] = {12, 5, 8, 7};
    
    // Create a linked list with the values from the array
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = arr[1];
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = arr[2];
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = arr[3];
    head->next->next->next->next = NULL;
    
    // Call the deleteTail function to delete the last node
    head = deleteTail(head);
    
    // Print the linked list after deletion
    printLL(head);
    
    return 0;
}

```

cpp code

```cpp
// Node class for a linked list
class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}
int main() {
    // Initialize a vector with values for the linked list
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // Call the deleteTail function to delete the last node
    head = deleteTail(head);
    // Print the linked list after deletion
    printLL(head);
}
```

java code

```c
// Node class definition
class Node {
    int data;
    Node next;
    // Constructor with both data and next pointer
    Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1;
    }
    // Constructor with only data (next pointer set to null)
    Node(int data1) {
        this.data = data1;
        this.next = null;
    }
}
// LinkedList class
public class LinkedList {
    // Function to delete the tail of the linked list
    private static Node deleteTail(Node head) {
        // Check if the linked list is empty or has only one node
        if (head == null || head.next == null)
            return null;
        // Create a temporary pointer for traversal
        Node temp = head;
        // Traverse the list until the second-to-last node
        while (temp.next.next != null) {
            temp = temp.next;
        }
        // Nullify the connection from the second-to-last node to delete the last node
        temp.next = null;
        // Return the updated head of the linked list
        return head;
    }
    // Function to print the linked list
    private static void printLL(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }
    // Main method
    public static void main(String[] args) {
        // Initialize an array with integer values
        int[] arr = {2, 5, 8, 7};
        // Create the linked list with nodes initialized with array values
        Node head = new Node(arr[0]);
        head.next = new Node(arr[1]);
        head.next.next = new Node(arr[2]);
        head.next.next.next = new Node(arr[3]);
        // Delete the tail of the linked list
        head = deleteTail(head);
        // Print the modified linked list
        printLL(head);
    }
}
```
