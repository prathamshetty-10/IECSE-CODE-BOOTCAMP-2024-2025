# Check if Two Strings are Anagrams

## Problem Statement
Given two strings, check if they are anagrams of each other or not.

## Examples

### Example 1
**Input:** CAT, ACT  
**Output:** true  
**Explanation:** Since the count of every letter of both strings are equal.

### Example 2
**Input:** RULES, LESRT  
**Output:** false  
**Explanation:** Since the count of U and T is not equal in both strings.

## Solutions

### Solution 1: Using Sorting

#### Approach
Sort both strings and compare each letter. If all letters match, the strings are anagrams.

For example:
- Str1 = "INTEGER"
- Str2 = "TEGERNI"

After sorting:
- Str1 = "EEGINRT"
- Str2 = "EEGINRT"

Since both strings are identical after sorting, they are anagrams.

#### Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

bool CheckAnagrams(string str1, string str2) {
    // Case 1: when both of the strings have different lengths
    if (str1.length() != str2.length())
        return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    // Case 2: check if every character of str1 and str2 matches with each other
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";
    if(CheckAnagrams(Str1, Str2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
```

#### Complexity Analysis
- **Time Complexity:** O(nlogn) due to sorting
- **Space Complexity:** O(1)

### Solution 2: Using Frequency Count

#### Approach
Count the frequency of each character in the first string and then decrease the count while iterating through the second string. If all frequencies are zero at the end, the strings are anagrams.

#### Implementation

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

bool CheckAnagrams(string str1, string str2) {
    // when both of the strings have different lengths
    if (str1.length() != str2.length())
        return false;
    
    int freq[26] = {0};
    
    // Count frequencies for first string
    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i] - 'A']++;
    }
    
    // Decrease frequencies for second string
    for (int i = 0; i < str2.length(); i++) {
        freq[str2[i] - 'A']--;
    }
    
    // Check if all frequencies are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";
    if(CheckAnagrams(Str1, Str2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
```

#### Complexity Analysis
- **Time Complexity:** O(n), where n is the length of the strings
- **Space Complexity:** O(1), as we use a fixed-size array of 26 characters

## Example Output
```
True
```
