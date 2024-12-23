# While loops 
A while loop in C++ is a control flow statement that repeatedly executes a block of code as long as the specified condition evaluates to true.
```
while (condition) {
    // Body of the loop
}
```
condition: A boolean expression. The loop continues as long as this condition is true.

Body of the loop: Code to execute repeatedly.

## How it Works
1. The condition is evaluated.

2. If the condition is true, the loop body is executed.

3. Steps 1 and 2 repeat until the condition becomes false.

## Example
```
#include <iostream>
using namespace std;

int main() {
    int count = 1;

    // While loop example
    while (count <= 5) {
        cout << "Count is: " << count << endl;
        count++;
    }

    return 0;
}
```
Output: 
```
Count is: 1
Count is: 2
Count is: 3
Count is: 4
Count is: 5
```
## Key Points
1. The condition is checked before executing the loop body.
2. If the condition is false initially, the body will not execute even once.
3. Ensure the loop has a terminating condition to avoid infinite loops.

## Infinite While Loop
An infinite loop runs indefinitely if the condition is always true. For example:
```
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (true) {
        cout << "This is an infinite loop, iteration: " << i++ << endl;
    }

    return 0;
}
```
## Common Use Cases
1. Input validation
2. Iterating over elements
3. Repeated operations until a condition is met

## Resources:
https://www.geeksforgeeks.org/cpp-while-loop/
https://takeuforward.org/while-loop/while-loops-in-programming/
