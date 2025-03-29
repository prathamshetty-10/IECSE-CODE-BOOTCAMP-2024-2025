### Cycle Detection
Given a singly linked list, detect if the list contains a cycle. If the list contains a cycle, return true; otherwise, return false.
<br>
<br>

1. Initialize Two Pointers: Set both `slow` and `fast` pointers to the head of the linked list. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time. Both pointers advance simultaneously.
2. Traverse the List: Move the `slow` pointer forward by one step and the `fast` pointer by two steps in each iteration.
3. Check for Termination Conditions:
    ◦ If `fast` or `fast.next` becomes `null`, it means the linked list is linear (no loop), and the algorithm ends, returning `false`.
    ◦ If `fast` and `slow` meet at the same node, a loop is detected in the linked list, and the algorithm ends, returning `true`.

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function to detect a cycle in the linked list using the Tortoise and Hare algorithm
int detectCycle(Node* head) {
    // Initialize two pointers, slow and fast, to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list with slow and fast pointers
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return 1;  // Loop detected
        }
    }

    // If fast reaches the end of the list, there is no loop
    return 0;  // No loop detected
}

int main() {
    // Create a sample linked list with a loop for testing
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));
    Node* fourth = (Node*)malloc(sizeof(Node));
    Node* fifth = (Node*)malloc(sizeof(Node));

    head->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;
    fifth->data = 5;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop
    fifth->next = third;

    // Check if there is a loop in the linked list
    if (detectCycle(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    // Clean up memory (free the allocated nodes)
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}

```

```cpp
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
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

// Function to detect a loop in a linked
// list using the Tortoise and Hare Algorithm
bool detectCycle(Node* head) {
    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return true;  // Loop detected
        }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}

int main() {
    // Create a sample linked list
    // with a loop for testing
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}

```

```cpp
import java.util.HashMap;
import java.util.Map;

// Node class represents a
// node in a linked list
class Node {
    // Data stored in the node
    public int data;   
    // Pointer to the next node in the list
    public Node next;  

    // Constructor with both data
    // and next node as parameters
    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    // Constructor with only data as
    // a parameter, sets next to null
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Main {

    // Function to detect a loop in a linked list
    // using the Tortoise and Hare Algorithm
    public static boolean detectCycle(Node head) {
        // Initialize two pointers, slow and fast,
        // to the head of the linked list
        Node slow = head;
        Node fast = head;

        // Step 2: Traverse the linked list
        // with the slow and fast pointers
        while (fast != null && fast.next != null) {
            // Move slow one step
            slow = slow.next;
            // Move fast two steps
            fast = fast.next.next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        // If fast reaches the end of the
        // list, there is no loop
        return false;
    }

    public static void main(String[] args) {
        // Create a sample linked list
        // with a loop for testing
        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);
        Node fourth = new Node(4);
        Node fifth = new Node(5);

        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        // Create a loop
        fifth.next = third;

        // Check if there is a loop
        // in the linked list
        if (detectCycle(head)) {
            System.out.println("Loop detected in the linked list.");
        } else {
            System.out.println("No loop detected in the linked list.");
        }

        // No need to explicitly free memory
        // in Java; the garbage collector handles it
    }
}

```
