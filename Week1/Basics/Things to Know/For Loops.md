# For loops
In C++, for loop is an entry-controlled loop that is used to execute a block of code repeatedly for the given number of times. It is generally preferred over while and do-while loops in case the number of iterations is known beforehand.
```
#include <bits/stdc++.h>
using namespace std;

int main() {

      // for loop to print "Hi" 5 times
    for (int i = 5; i < 10; i++) {
          cout << "Hi" << endl;
    }
  
    return 0;
}
```
Output:
```
Hi
Hi
Hi
Hi
Hi
```
# Working of a for Loop in C++
![image](https://github.com/user-attachments/assets/57d58728-ac23-4037-833f-09a7a2e18432)


Control falls into the for loop. Initialization is done.

The flow jumps to Condition.

Condition is tested.

If the Condition yields true, the flow goes into the Body.

If the Condition yields false, the flow goes outside the loop.

The statements inside the body of the loop get executed.

The flow goes to the update.

Updating takes place and the flow goes to Step 3 again.

The for loop has ended and the flow has gone outside.

## Other Types of for Loop in C++
The above explained for loop is the actual legacy for loop that has been the part of the language since the beginning. But the different versions of for loop were added later in the languages. They are:

1. Range-Based for Loop in C++
C++ range-based for loops execute for loops over a range of values, such as all the elements in a container, in a more readable way than the traditional for loops. It is much simpler as compared to traditional for loop. But the disadvantage of this is that it has limited applications.

2. for_each Loop in C++
C++ for_each loop is not a loop but an algorithm that mimics the range based for loop. It accepts a function that executes over each of the container elements. This loop is defined in the header file <algorithm> and hence has to be included for the successful operation of this loop.

## Resources:
https://takeuforward.org/for-loop/understanding-for-loop/

https://www.geeksforgeeks.org/cpp-for-loop/

