# Time and Space Complexity
## Time Complexity
We can solve a problem using different logic and different codes. Time complexity basically helps to judge different codes and also helps to decide which code is better. In an interview, an interviewer generally judges a code by its time complexity.

Now, the term, time complexity, seems that it is referring to the time taken by a machine to execute a particular code. But in real life, Time complexity does not refer to the time taken by the machine to execute a particular code. 

The valid algorithm takes a finite amount of time for execution. The time required by the algorithm to solve given problem is called time complexity  of the algorithm. Time complexity is very useful measure in algorithm analysis.

To estimate the time complexity, we need to consider the cost of each fundamental instruction and the number of times the instruction is executed.

The rate at which the time, required to run a code, changes with respect to the input size, is considered the time complexity. Basically, the time complexity of a particular code depends on the given input size, not on the machine used to run the code.

To represent the time complexity, we generally use the Big O notation `O()` where O is a function of time taken by the code
### Example
```
Algorithm ADD SCALAR(A, B)
//Description: Perform arithmetic addition of two numbers
//Input: Two scalar variables A and B
//Output: variable C, which holds the addition of A and B
C <- A + B
return C
```
The addition of two scalar numbers requires one addition operation. the time complexity of this algorithm is constant, so T(n) = O(1) .

In order to calculate time complexity on an algorithm, it is assumed that a constant time c is taken to execute one operation, and then the total operations for an input length on N are calculated. Consider an example to understand the process of calculation: Suppose a problem is to find whether a pair (X, Y) exists in an array, A of N elements whose sum is Z. The simplest idea is to consider every pair and check if it satisfies the given condition or not.
```
#include <iostream>
using namespace std;

// Function to find a pair in the given
// array whose sum is equal to z
bool findPair(int a[], int n, int z)
{
    // Iterate through all the pairs
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)

            // Check if the sum of the pair
            // (a[i], a[j]) is equal to z
            if (i != j && a[i] + a[j] == z)
                return true;

    return false;
}

// Driver Code
int main()
{
    // Given Input
    int a[] = { 1, -2, 1, 0, 5 };
    int z = 0;
    int n = sizeof(a) / sizeof(a[0]);

    // Function Call
    if (findPair(a, n, z))
        cout << "True";
    else
        cout << "False";
    return 0;
}
```
Output: `False`

Assuming that each of the operations in the computer takes approximately constant time, let it be c. The number of lines of code executed actually depends on the value of Z. During analyses of the algorithm, mostly the worst-case scenario is considered, i.e., when there is no pair of elements with sum equals Z. In the worst case, 

* N*c operations are required for input.
* The outer loop i loop runs N times.
* For each i, the inner loop j loop runs N times.
* So total execution time is N*c + N*N*c + c. Now ignore the lower order terms since the lower order terms are relatively insignificant for large input, therefore only the highest order term is taken (without constant) which is N*N in this case. Different notations are used to describe the limiting behavior of a function, but since the worst case is taken so big-O notation will be used to represent the time complexity.

Hence, the time complexity is O(N^2) for the above algorithm. Note that the time complexity is solely based on the number of elements in array A i.e the input length, so if the length of the array will increase the time of execution will also increase.

## Space complexity
The term space complexity generally refers to the memory space that a code uses while being executed. Again space complexity is also dependent on the machine and so we are going to represent the space complexity using the Big O notation instead of using the standard units of memory like MB, GB, etc.

### Example
```
Input(a)//1 Input space
Input(b)//1 Input space
c=a+b
//c->1 auxiliary space
```
The variables a and b are used to store the inputs but c refers to the space we are using to solve the problem and c is the auxiliary space. Here the space complexity will be O(3).

Similarly, if we use an array of size n, the space complexity will be O(N).

## Note
If a question of adding two numbers like a and b is asked, one of the possible methods will be 

b = a+b. In this case, the space complexity is definitely reduced as we are not using any extra variable but this is not a good practice to manipulate the given inputs or data. In an interview, we must be careful that we will not manipulate the given data even if the space complexity becomes 2N instead of N. If the interviewer specifically instructs us to manipulate, then only we should attempt this method.

## Resources
https://takeuforward.org/time-complexity/time-and-space-complexity-strivers-a2z-dsa-course/

https://www.geeksforgeeks.org/time-complexity-and-space-complexity/
