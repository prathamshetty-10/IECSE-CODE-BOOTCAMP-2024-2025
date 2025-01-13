# Pointers and Structures

Pointer- A pointer is a variable that stores the memory address of another variable.

**Syntax:**

```
int a = 10;
int *p = &a; // Pointer to an integer
```

Dereferencing: Accessing the value stored at the address.

```
printf("Value of a: %d", *p);
```

**Null Pointers:**

- A pointer that does not point to any valid memory location.
    
    int *ptr = NULL;
    

Struct- A `struct` (short for structure) is a user-defined data type used to group multiple variables under one name.

```c
struct Node {
    int data;             // Data part
    struct Node* next;    // Pointer to the next node
};
```
Node- A node typically refers to a fundamental unit or element that stores data and may have one or more connections to other nodes.

Classes-  A class is a more advanced version of a struct. It not only groups variables (like structs) but also encapsulates methods (functions) that operate on the data.

- They are blueprints for creating **objects.**

Objects are instance of classes.

Creating nodes in cpp

```java
class Node {
public:
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize the node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;  // Initially, the next pointer is null
    }
};
```

Declaring Objects in cpp

```java
Node* node2 = new Node(10);  // Creates a node with data = 10 and next = nullptr
```

Creating Nodes in Java

```java
public class Node {
    int data;       // The data part of the node
    Node next;      // The reference to the next node in the list

    public Node(int data) {
        this.data = data;
        this.next = null;  // Initially, the next node is null
    
	    
}
```

Declaring Objects in Java

```java
Node node= new Node(5); //creates a node with data =5 and next = null
```
