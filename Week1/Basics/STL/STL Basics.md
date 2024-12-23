# Standard Template Library
The C++ Standard Template Library (STL) is a set of template classes and functions that provides the implementation of common data structures and algorithms such as lists, stacks, arrays, sorting, searching, etc. It also provides the iterators and functors which makes it easier to work with algorithms and containers.

## Components of STL
The components of STL are the features provided by Standard Template Library (STL) in C++ that can be classified into 4 types:

* Containers
* Algorithms
* Iterators
* Functors

## Containers
Containers are the data structures used to store objects and data according to the requirement. Each container is implemented as a template class that also contains the methods to perform basic operations on it. Every STL container is defined inside its own header file.

Containers can be further classified into 4 types:

1. Sequence Containers
2. Container Adaptors
3. Associative Containers
4. Unordered Associated Containers

### Sequence Containers
Sequence containers store the data in the linear manner. They are also used to implement container adaptors.
1. Arrays: The STL array is an implementation of a compile time non-resizable array. It contains various method for common array operations.
2. Vector: An STL vector can be defined as the dynamic sized array which can be resized automatically when new elements are added or removed.
3. Deque: Deque or Double-Ended Queue is sequence containers with the feature of expansion and contraction on both ends. It means we can add and remove the data to and from both ends.
4. Lists: List container stores data in non-contiguous memory unlike vectors and only provide sequential access to the stored data. It basically implements the doubly linked list.
5. Forward Lists: Forward lists also store the data in a sequential manner like lists, but with the difference that forward list stores the location of only the next elements in the sequence. It implements the singly linked list.

### Container Adaptors
The container adapters are the type of STL containers that adapt existing container classes to suit specific needs or requirements.
1. Stack: STL Stack follows the Last In First Out (LIFO) principle of element insertion and deletion. Also, these operations are performed only at one end of the stack.
2. Queue: STL Queue follows the First In First Out (FIFO) principle, means the element are inserted first are removed first and the elements inserted last are removed at last. It uses deque container by default.
3. Priority Queue: STL Priority Queue does not follow any of the FIFO or LIFO principle, but the deletion of elements is done on the basis of its priority. So, the element with the highest (by default) is always removed first. By default, it uses vector as underlying container.

### Associative Containers
Associative containers are the type of containers that store the elements in a sorted order based on keys rather than their insertion order.
1. Sets: STL Set is a type of associative container in which each element has to be unique because the value of the element identifies it. By default, the values are stored in ascending order.
2. Maps: STL Maps are associative containers that store elements in the form of a key-value pair. The keys have to be unique and the container is sorted on the basis of the values of the keys.
3. Multisets: STL Multiset is similar to the set container except that it can store duplicate values.
4. Multimaps: STL Multimap is similar to a map container but allows multiple mapped values to have same keys.

### Unordered Associative Containers
Unordered associative containers store the data in no particular order, but they allow the fastest insertion, deletion and search operations among all the container types in STL.
1. Unordered Set: STL Unordered Set stores the unique keys in the form of hash table. The order is randomized but insertion, deletion and search are fast.
2. Unordered Multiset: STL Unordered Multiset works similarly to an unordered set but can store multiple copies of the same key.
3. Unordered Map: STL Unordered Map stores the key-value pair in a hash table, where key is hashed to find the storage place.
4. Unordered Multimap: STL Unordered Multimap container is similar to unordered map, but it allows multiple values mapped to the same key.
