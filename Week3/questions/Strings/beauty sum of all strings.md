# Beauty Sum of All Substrings

## Problem Statement
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is `3 - 1 = 2`.

Given a string `s`, return the sum of the beauty of all of its substrings.

### Examples

**Example 1:**

Input:
```plaintext
s = "aabcb"
```
Output:
```plaintext
5
```
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

**Example 2:**

Input:
```plaintext
s = "aabcbaa"
```
Output:
```plaintext
17
```

---

## Approach
1. Initialize `sol` to store the solution.
2. Generate all possible substrings using two nested loops.

### Outer Loop:
- Initialize a vector `c` of length 26 with default values of 0 to track character frequencies.
- Use `maxN` to keep track of the maximum frequency encountered.
- Use `minPair` (a pair of integers) to track the minimum frequency and the count of characters with that frequency. Set `minPair` to `{1,1}` initially because there is at least one character in the substring.

### Inner Loop:
- Update the frequency of the current character in vector `c`.
- Update `maxN` if the current frequency is greater than the existing `maxN`.
- Update `minPair`:
  - If the current frequency equals `minPair.first`, increment `minPair.second`.
  - If the current frequency is less than `minPair.first`, update `minPair` to `{c[curr], 1}`.
  - If the current frequency is greater than `minPair.first` by exactly 1, decrement `minPair.second`. If `minPair.second` becomes 0, update `minPair.first` and recalculate `minPair.second`.

### Final Step:
- After the inner loop ends, increment `sol` by taking the difference of `maxN - minPair.first`.

### Complexity
- **Time Complexity:** O(n^2), due to nested loops.
- **Space Complexity:** O(1), ignoring the vector `c` as it is constant in size.

---

## Code
```cpp
class Solution {
public:
    int beautySum(string s) {
        int sol = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> c(26, 0);
            int maxN = 0;
            pair<int, int> minPair = {1, 1};
            c[s[i] - 'a']++;
            for (int j = i + 1; j < s.size(); j++) {
                int curr = s[j] - 'a';
                c[curr]++;
                maxN = max(maxN, c[curr]);

                if (minPair.first == c[curr]) minPair.second++;
                else if (c[curr] < minPair.first) {
                    minPair.first = c[curr];
                    minPair.second = 1;
                }
                else if (minPair.first + 1 == c[curr] && --minPair.second == 0) {
                    minPair.first++;
                    minPair.second = 0;
                    for (int k : c) {
                        if (k == minPair.first) minPair.second++;
                    }
                }

                sol += maxN - minPair.first;
            }
        }
        return sol;
    }
};
