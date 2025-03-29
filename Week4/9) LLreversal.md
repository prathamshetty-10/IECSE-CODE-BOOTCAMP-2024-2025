### Linked List reversal

Given a singly linked list, reverse the list
<br><br>

![image](https://github.com/user-attachments/assets/4721435d-0e3e-4e09-b9df-e4a1479b6cc4)


The main idea is to flip the order of connections in the linked list, which changes the direction of the arrows. When this happens, the last element becomes the new first element of the list. This in-place reversal allows us to efficiently transform the original list without using extra space.a

3 pointer approach-We use three pointers: `temp`, `prev`, and `front`. We start with `temp` pointing to the head, `prev` as `NULL`, and `front` to store the next node. For each node, we reverse its `next` pointer to point to `prev`. Then, we move `prev` to `temp` (current node) and `temp` to `front` (next node). This process continues until `temp` reaches `NULL`, at which point `prev` becomes the new head of the reversed list. 

![image](https://github.com/user-attachments/assets/c369f642-cdbe-4767-9bbd-aa6da39128d2)


```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function to reverse a linked list using the 3-pointer approach
Node* reverseLinkedList(Node* head) {
    // Initialize 'temp' at head of linked list
    Node* temp = head;
    
    // Initialize pointer 'prev' to NULL, representing the previous node
    Node* prev = NULL;
    
    // Traverse the list, continue until 'temp' reaches the end (NULL)
    while (temp != NULL) {
        // Store the next node in 'front' to preserve the reference
        Node* front = temp->next;
        
        // Reverse the direction of the current node's 'next' pointer
        // to point to 'prev'
        temp->next = prev;
        
        // Move 'prev' to the current node for the next iteration
        prev = temp;
        
        // Move 'temp' to the 'front' node, advancing the traversal
        temp = front;
    }
    
    // Return the new head of the reversed linked list
    return prev;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with values 1, 3, 2, and 4
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 3;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 2;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    // Print the original linked list
    printf("Original Linked List: ");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    printf("Reversed Linked List: ");
    printLinkedList(head);

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

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse a linked list
// using the 3-pointer approach
Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at
   // head of linked list
   Node* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   Node* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       Node* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}

```

```java
import java.util.Stack;

// Node class represents a
// node in a linked list
class Node {
    // Data stored in the node
    int data;      
    // Pointer to the next
    // node in the list
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

public class ReverseLinkedListUsingStack {

    // Function to reverse a singly
    // linked list using a recursion
    public static Node reverseLinkedList(Node head) {
        // Base case:
        // If the linked list is empty or has only one node,
        // return the head as it is already reversed.
        if (head == null || head.next == null) {
            return head;
        }
        
        // Recursive step:
        // Reverse the linked list starting
        // from the second node (head.next).
        Node newHead = reverseLinkedList(head.next);
        
        // Save a reference to the node following
        // the current 'head' node.
        Node front = head.next;
        
        // Make the 'front' node point to the current
        // 'head' node in the reversed order.
        front.next = head;
        
        // Break the link from the current 'head' node
        // to the 'front' node to avoid cycles.
        head.next = null;
        
        // Return the 'newHead,' which is the new
        // head of the reversed linked list.
        return newHead;
    }

    // Function to print the linked list
    public static void printLinkedList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create a linked list with values 1, 3, 2, and 4
        Node head = new Node(1);
        head.next = new Node(3);
        head.next.next = new Node(2);
        head.next.next.next = new Node(4);

        // Print the original linked list
        System.out.print("Original Linked List: ");
        printLinkedList(head);

        // Reverse the linked list
        head = reverseLinkedList(head);

        // Print the reversed linked list
        System.out.print("Reversed Linked List: ");
        printLinkedList(head);
    }
}

```
