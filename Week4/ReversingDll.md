### Reversing Doubly Linked List
Given a doubly linked list (DLL), reverse the list and return the new head of the reversed list.<br><br>
![image](https://github.com/user-attachments/assets/7d1845de-9624-426e-9291-43dc74056feb)


To reverse a doubly linked list, you need to swap the `next` and `prev` pointers for each node in the list. Here's the general approach:

1. **Initialize a pointer** to traverse the list, starting from the head of the doubly linked list.
2. **Iterate through the list**: For each node:
    - Swap the `next` and `prev` pointers. That is, set the node's `next` pointer to its `prev`, and set its `prev` pointer to its `next`.
3. After the iteration, the **head of the list** will need to be updated to the last node (which was previously the tail).
4. **End condition**: The process stops when you reach the end of the list (i.e., when `prev` is `null`).

```c
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for doubly linked list
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list (forward direction)
    struct Node* back;  // Pointer to the previous node in the list (backward direction)
} Node;

// Function to create a new node with both data and next/back pointers
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

// Function to create a new node with data and no references to next/back (end of the list)
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

// Function to convert an array to a doubly linked list
Node* convert_arr_to_dll(int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = create_node_with_data(arr[0]);
    Node* prev = head;

    for (int i = 1; i < size; i++) {
        Node* temp = create_node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse a doubly linked list (in-place link exchange method)
Node* reverse_dll(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* temp = current->back;
        current->back = current->next;
        current->next = temp;
        prev = current;
        current = current->back;
    }

    return prev;
}

int main() {
    int arr[] = {12, 5, 8, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = convert_arr_to_dll(arr, size);
    printf("\nDoubly Linked List Initially:  \n");
    print(head);

    printf("\nDoubly Linked List After Reversing: \n");
    head = reverse_dll(head);
    print(head);

    return 0;
}

```

```cpp
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list 
    //(forward direction)
    Node* next;     
    // Pointer to the previous node in the list
    //(backward direction)
    Node* back;     

    // Constructor for a Node with both data,
    //a reference to the next node,
    //and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data,
    //and no references to the next and
    //backious nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array
// to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with
    //the first element of the array
    
    Node* head = new Node(arr[0]);
    
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the
        //array and set its 'back' pointer to
        //the previous node
        
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the
        //previous node to point to
        //the new node
        prev->next = temp; 
         // Move 'prev' to the newly created
         //node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements
//of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 
// Function to reverse a doubly linked list
// In-place link exchange method
Node* reverseDLL(Node* head) {
    
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return head; 
    }
    
     // Initialize a pointer to
     // the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to
    // the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        prev = current->back; 
        
        // Swap the previous and
        // next pointers
        current->back = current->next; 
        
        // This step reverses the links
        current->next = prev;          
        
        // Move to the next node
        // in the original list
        current = current->back; 
    }
    
    // The final node in the original list
    // becomes the new head after reversal
    return prev->back;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);

    return 0;
}
```

```cpp

import java.util.Stack;

public class DLinkedList {
    public static class Node {
        // Data stored in the node
        public int data;
        // Reference to the next node
        //in the list (forward direction)
        public Node next;
        // Reference to the previous nod
        //in the list (backward direction)
        public Node back;

        // Constructor for a Node with both data, 
        //a reference to the next node, and a
        //reference to the previous node
        public Node(int data1, Node next1, Node back1) {
            data = data1;
            next = next1;
            back = back1;
        }

        // Constructor for a Node with data,
        //and no references to the next and
        //previous nodes (end of the list)
        public Node(int data1) {
            data = data1;
            next = null;
            back = null;
        }
    }

    private static Node convertArr2DLL(int[] arr) {
        // Create the head node with the
        //first element of the array
        Node head = new Node(arr[0]);
        // Initialize 'prev' to the head node
        Node prev = head;

        for (int i = 1; i < arr.length; i++) {
            // Create a new node with data from
            // the array and set its 'back' pointer
            // to the previous node
            
            Node temp = new Node(arr[i], null, prev);
            // Update the 'next' pointer of the
            // previous node to point to the new node
            
            prev.next = temp;
            // Move 'prev' to the newly created node
            //for the next iteration
            prev = temp;
        }
        // Return the head of the doubly linked list
        return head;
    }

    private static void print(Node head) {
        while (head != null) {
            // Print the data in the current node
            System.out.print(head.data + " ");
            // Move to the next node
            head = head.next; 
        }
        System.out.println();
    }
    
    private static Node reverseDLL(Node head) {
        // Check if the list is empty
        // or has only one node
        if (head == null || head.next == null) {
            // No change is needed;
            // return the current head
            return head; 
        }
        
         // Initialize a pointer to
         // the previous node        
        Node prev = null;
        
        // Initialize a pointer to
        // the current node
        Node current = head;
        
        // Traverse the linked list
        while (current != null) {
            
            // Store a reference to
            // the previous node
            prev = current.back;
            
            // Swap the previous and
            // next pointers
            current.back = current.next;
            
            // This step reverses the links
            current.next = prev;
            
            // Move to the next node
            // in the orignal list
            
            current = current.back;
        }

        // The final node in the original list
        // becomes the new head after reversal
        return prev.back;
    }

    

    public static void main(String[] args) {
        int[] arr = {12, 5, 6, 8, 4};
        // Convert the array to a doubly linked list
        Node head = convertArr2DLL(arr);

        // Print the doubly linked list
        System.out.println(“Doubly Linked List Initially:  “);
        print(head);

        System.out.println("Doubly Linked List After Reversing :");

        head = reverseDLL(head);
        print(head);

    }
}
```
