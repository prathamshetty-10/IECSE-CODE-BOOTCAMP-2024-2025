# Roman Numerals to Integer Conversion

## Problem Statement
Roman numerals are represented by seven different symbols:

| Symbol | Value  |
|--------|--------|
| I      | 1      |
| V      | 5      |
| X      | 10     |
| L      | 50     |
| C      | 100    |
| D      | 500    |
| M      | 1000   |

### Rules for Roman Numerals:
1. Roman numerals are usually written from largest to smallest from left to right.
2. If a smaller numeral appears before a larger numeral, it indicates subtraction.

### Examples of Subtraction Rules:
- **I** can be placed before **V** (5) and **X** (10) to make 4 and 9.
- **X** can be placed before **L** (50) and **C** (100) to make 40 and 90.
- **C** can be placed before **D** (500) and **M** (1000) to make 400 and 900.

### Examples:
- **III** = 3 (I + I + I)
- **LVIII** = 58 (L + V + III)
- **MCMXCIV** = 1994 (M + CM + XC + IV)

---

## Approach
1. Use a hash map (`unordered_map`) to store the values of the Roman numeral characters.
2. Traverse the input string `s`.
3. Compare the value of the current Roman numeral with the next one:
   - If the current numeral is smaller than the next numeral, subtract its value.
   - Otherwise, add its value.
4. Return the accumulated sum.

---

## Complexity
- **Time Complexity:** O(n), where `n` is the length of the string `s`.
- **Space Complexity:** O(1), as the hash map is of constant size.

---

## Code
```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }
        return ans;
    }
};
