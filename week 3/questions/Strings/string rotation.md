# Rotate String Solutions

## Problem Statement
Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts on `s`.

A shift on `s` consists of moving the leftmost character of `s` to the rightmost position.

For example, if `s = "abcde"`, then it will become `"bcdea"` after one shift.

### Examples

**Example 1:**

Input:
```plaintext
s = "abcde", goal = "cdeab"
```
Output:
```plaintext
true
```

**Example 2:**

Input:
```plaintext
s = "abcde", goal = "abced"
```
Output:
```plaintext
false
```

---

## Solution 1

### Intuition
By concatenating the string `s` with itself, we create a string that contains all possible rotations of `s`. Checking if `goal` is a substring of this new string is a straightforward way to verify if `goal` is a valid rotation.

### Approach
1. If the sizes of `s` and `goal` are different, return `false`.
2. Concatenate `s` with itself to form `ss`.
3. Check if `goal` is a substring of `ss`.

### Complexity
- **Time Complexity:** O(n + m), where `n` is the length of `s` and `m` is the length of `goal`.
- **Space Complexity:** O(n), as a new string `ss` is created.

### Code
```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string check = s + s;
        return check.find(goal) != string::npos;
    }
};
```

---

## Solution 2

### Intuition
By rotating `s` one character at a time and comparing it to `goal`, we can determine if `goal` is a valid rotation of `s`.

### Approach
1. If the sizes of `s` and `goal` are different, return `false`.
2. Iterate through the length of `s`.
3. For each rotation, create a new string by slicing `s` at different positions and compare it with `goal`.
4. Return `true` if a match is found; otherwise, return `false`.

### Complexity
- **Time Complexity:** O(n^2), where `n` is the length of `s` (rotating the string and comparing take linear time, and this is repeated `n` times).
- **Space Complexity:** O(n), as a new string `rotated` is created for each iteration.

### Code
```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        
        string rotated;
        for (int i = 0; i < s.size(); i++) {
            rotated = s.substr(i) + s.substr(0, i);
            if (rotated == goal)
                return true;
        }
        return false;
    }
};
