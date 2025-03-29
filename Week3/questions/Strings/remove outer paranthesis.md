# Remove Outer Parentheses

## Intuition
We need to remove the outermost parentheses from each segment of valid parentheses in the given string. A valid parentheses string is one where every opening parenthesis `(` has a matching closing parenthesis `)`. If we can track how many open and close parentheses we've seen, we can figure out which parentheses are the outermost ones and skip them.

## Approach

### 1. Initialize Variables
* `result`: An empty string to store the final output
* `balance`: A counter to keep track of the balance of parentheses (`(` increases the balance and `)` decreases it)

### 2. Loop Through the String
* Use a for loop to go through each character in the string s
* For each character:
   * If it's an opening parenthesis `(`:
      * If the balance is more than 0, it means this `(` is not an outermost parenthesis, so add it to 'result'
      * Increase the balance by 1
   * If it's a closing parenthesis `)`:
      * Decrease the balance by 1
      * If the balance is more than 0 after decreasing, it means this `)` is not an outermost parenthesis, so add it to 'result'

### 3. Return the Result
* After processing all characters, the 'result' string will contain the original string without the outermost parentheses

## Complexity Analysis

### Time Complexity
* O(n), where n is the length of the string s
* We traverse through the string once

### Space Complexity
* O(n), where n is the length of the string s
* The result string might store almost all characters from s

## Implementation

```cpp
class Solution {
public:
    // Function to remove outermost parentheses of every primitive string in the
    // decomposition of s
    string removeOuterParentheses(string s) {
        string result;   // To store the final result
        int balance = 0; // To keep track of the balance of parentheses

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If balance is greater than 0, it means this '(' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
                balance++; // Increase the balance for '('
            } else {
                balance--; // Decrease the balance for ')'
                // If balance is greater than 0, it means this ')' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
            }
        }

        return result; // Return the final result after removing outermost
                      // parentheses
    }
};
```
