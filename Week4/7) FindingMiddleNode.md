### Finding middle node
Given a singly linked list, find the middle node of the list. If the list has an even number of nodes, return the second middle node.
<br>
<br>
Fast and Slow pointer approach -Initialize two pointers: the slow pointer moves one step at a time, and the fast pointer moves two steps at a time. As you traverse the list, the slow pointer will cover half the distance compared to the fast pointer. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. This approach runs in **O(n)** time complexity, where `n` is the number of nodes, and uses **O(1)** space complexity since only two pointers are required.

![image](https://github.com/user-attachments/assets/d9b4185c-a3e9-4f4e-b459-c7dc13fca8d0)


```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function to find the middle node of a linked list
Node* findMiddle(Node* head) {
    // Initialize the slow pointer to the head
    Node* slow = head;
    
    // Initialize the fast pointer to the head
    Node* fast = head;

    // Traverse the linked list using the Tortoise and Hare algorithm
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step
        slow = slow->next;
        
        // Move fast two steps
        fast = fast->next->next;
    }

    // Return the slow pointer, which is now at the middle node
    return slow;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    // Find the middle node
    Node* middleNode = findMiddle(head);

    // Display the value of the middle node
    printf("The middle node value is: %d\n", middleNode->data);

    return 0;
}

```

```cpp
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:

    // Data stored in the node
    int data;  
    
     // Pointer to the next node in the list
    Node* next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to find the middle
// node of a linked list
Node *findMiddle(Node *head) {
    
     // Initialize the slow pointer to the head.
    Node *slow = head; 
    
     // Initialize the fast pointer to the head.
    Node *fast = head; 

    // Traverse the linked list using the
    // Tortoise and Hare algorithm.
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step.
        slow = slow->next; 
         // Move fast two steps.
        fast = fast->next->next; 
    }
    
    
     // Return the slow pointer,
     // which is now at the middle node.
    return slow; 
}

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}
```

```java
                                
import java.util.*;

// Node class represents a node in a linked list
class Node {
    // Data stored in the node
    int data; 
     // Pointer to the next node in the list
    Node next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    // Constructor with only data as
    // a parameter, sets next to null
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class FindMiddleOfLinkedList {
    
    static Node findMiddle(Node head) {
        // Initialize the slow pointer to the head.
        Node slow = head; 
        
        // Initialize the fast pointer to the head.
        Node fast = head;   

        // Traverse the linked list using
        // the Tortoise and Hare algorithm.
        while (fast != null && fast.next != null && slow != null) {
            // Move fast two steps.
            fast = fast.next.next;  
            // Move slow one step.
            slow = slow.next;        
        }
        // Return the slow pointer,
        // which is now at the middle node.
        return slow;  
    }

    public static void main(String[] args) {
        // Creating a sample linked list:
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        // Find the middle node
        Node middleNode = findMiddle(head);

        // Display the value of the middle node
        System.out.println("The middle node value is: " + middleNode.data);
    }
}
```
