### Merging two sorted lists
Given two sorted singly linked lists, merge them into one sorted linked list. The resulting list should be sorted in ascending order.<br><br>
Using a dummy node simplifies the process because it provides a consistent starting point.

### Initial State:

- **List 1**: `1 -> 3 -> 5`
- **List 2**: `2 -> 4 -> 6`
- **Dummy Node**: `0 -> null` (The dummy node is a placeholder, not part of the final merged list). Dummy node is used to help us avoid the edge case of creating the first node in the empty list.
- **Current Pointer**: Points to the dummy node initially.

### Steps:

1. Compare `1` and `2`. Since `1 < 2`, attach `1` to `current.next`. Move `l1` to `3` and advance `current` to `1`.
    
    **Merged List**: `0 -> 1`
    
2. Compare `3` and `2`. Attach `2` to `current.next`. Move `l2` to `4` and advance `current` to `2`.
    
    **Merged List**: `0 -> 1 -> 2`
    
3. Compare `3` and `4`. Attach `3` to `current.next`. Move `l1` to `5` and advance `current` to `3`.
    
    **Merged List**: `0 -> 1 -> 2 -> 3`
    
4. Continue until one list is exhausted, then attach the remaining nodes from the non-empty list.
5. At the end, return `dummy.next` (skipping the dummy node) as the head of the merged list.
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    // Node structure represents a node in a linked list
    struct Node {
        int data;
        struct Node* next;
    };
    
    // Function to create a new node with a given data value
    struct Node* createNode(int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
    
    // Function to merge two sorted linked lists
    struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
        // Create a dummy node to simplify the merge process
        struct Node dummy;
        struct Node* current = &dummy;
        dummy.next = NULL;
    
        // Traverse both lists and merge them
        while (l1 != NULL && l2 != NULL) {
            if (l1->data <= l2->data) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
    
        // Attach the remaining nodes of l1 or l2
        current->next = (l1 != NULL) ? l1 : l2;
    
        return dummy.next;  // Return the merged list
    }
    
    // Utility function to print the linked list
    void printList(struct Node* head) {
        while (head != NULL) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
    
    int main() {
        // Create two sorted linked lists for testing
        struct Node* l1 = createNode(1);
        l1->next = createNode(3);
        l1->next->next = createNode(5);
    
        struct Node* l2 = createNode(2);
        l2->next = createNode(4);
        l2->next->next = createNode(6);
    
        printf("List 1: ");
        printList(l1);
    
        printf("List 2: ");
        printList(l2);
    
        // Merge the two sorted linked lists
        struct Node* mergedList = mergeTwoLists(l1, l2);
    
        printf("Merged List: ");
        printList(mergedList);
    
        // Clean up memory (free the allocated nodes)
        while (mergedList != NULL) {
            struct Node* temp = mergedList;
            mergedList = mergedList->next;
            free(temp);
        }
    
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
    
    // Function to merge two sorted linked lists
    Node* mergeTwoLists(Node* l1, Node* l2) {
        // Create a dummy node to simplify the merge process
        Node dummy(0);
        Node* current = &dummy;
    
        // Traverse both lists and merge them
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->data <= l2->data) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
    
        // Attach the remaining nodes of l1 or l2
        current->next = (l1 != nullptr) ? l1 : l2;
    
        return dummy.next;  // Return the merged list
    }
    
    // Utility function to print the linked list
    void printList(Node* head) {
        while (head != nullptr) {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "nullptr" << endl;
    }
    
    int main() {
        // Create two sorted linked lists for testing
        Node* l1 = new Node(1);
        l1->next = new Node(3);
        l1->next->next = new Node(5);
    
        Node* l2 = new Node(2);
        l2->next = new Node(4);
        l2->next->next = new Node(6);
    
        cout << "List 1: ";
        printList(l1);
    
        cout << "List 2: ";
        printList(l2);
    
        // Merge the two sorted linked lists
        Node* mergedList = mergeTwoLists(l1, l2);
    
        cout << "Merged List: ";
        printList(mergedList);
    
        // Clean up memory (free the allocated nodes)
        while (mergedList != nullptr) {
            Node* temp = mergedList;
            mergedList = mergedList->next;
            delete temp;
        }
    
        return 0;
    }
    
    ```
    
    ```java
    import java.util.*;
    
    class Node {
        int data;
        Node next;
    
        // Constructor with both data and next node as parameters
        Node(int data1, Node next1) {
            data = data1;
            next = next1;
        }
    
        // Constructor with only data as a parameter, sets next to null
        Node(int data1) {
            data = data1;
            next = null;
        }
    }
    
    public class Main {
    
        // Function to merge two sorted linked lists
        public static Node mergeTwoLists(Node l1, Node l2) {
            // Create a dummy node to simplify the merge process
            Node dummy = new Node(0);
            Node current = dummy;
    
            // Traverse both lists and merge them
            while (l1 != null && l2 != null) {
                if (l1.data <= l2.data) {
                    current.next = l1;
                    l1 = l1.next;
                } else {
                    current.next = l2;
                    l2 = l2.next;
                }
                current = current.next;
            }
    
            // Attach the remaining nodes of l1 or l2
            current.next = (l1 != null) ? l1 : l2;
    
            return dummy.next; // Return the merged list
        }
    
        // Utility function to print the linked list
        public static void printList(Node head) {
            while (head != null) {
                System.out.print(head.data + " -> ");
                head = head.next;
            }
            System.out.println("null");
        }
    
        public static void main(String[] args) {
            // Create two sorted linked lists for testing
            Node l1 = new Node(1);
            l1.next = new Node(3);
            l1.next.next = new Node(5);
    
            Node l2 = new Node(2);
            l2.next = new Node(4);
            l2.next.next = new Node(6);
    
            System.out.print("List 1: ");
            printList(l1);
    
            System.out.print("List 2: ");
            printList(l2);
    
            // Merge the two sorted linked lists
            Node mergedList = mergeTwoLists(l1, l2);
    
            System.out.print("Merged List: ");
            printList(mergedList);
        }
    }
    
    ```
