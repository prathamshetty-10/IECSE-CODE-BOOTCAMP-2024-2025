# Reverse Words in a String

## Problem Statement
Given a string s, reverse the words of the string.

## Examples

### Example 1
**Input:** `s="this is an amazing program"`  
**Output:** `"program amazing an is this"`

### Example 2
**Input:** `s="This is decent"`  
**Output:** `"decent is This"`

## Solutions

### Solution 1: Brute Force Using Stack

#### Intuition
We need to print the words in reverse order. We can store them in reverse order of occurrence using a stack data structure.

#### Approach
1. Use a stack to push all the words
2. Words will be stored in reverse order in the stack
3. Pop elements one by one and add them to answer string with appropriate spacing

#### Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "TUF is great for interview preparation";
    cout << "Before reversing words: " << endl;
    cout << s << endl;
    
    s += " ";
    stack<string> st;
    int i;
    string str = "";
    
    // Split string into words and push to stack
    for(i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            st.push(str);
            str = "";
        }
        else str += s[i];
    }
    
    // Construct reversed string
    string ans = "";
    while(st.size() != 1) {
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top(); // Last word shouldn't have a space after it
    
    cout << "After reversing words: " << endl;
    cout << ans;
    return 0;
}
```

#### Complexity Analysis
- **Time Complexity:** O(N), where N is the length of the string
- **Space Complexity:** O(N) for the stack and answer string

### Solution 2: Optimized Solution

#### Intuition
Instead of using extra space with a stack, we can reverse words as we traverse through the string from the end.

#### Approach
1. Traverse string from end until we hit a space
2. When space is encountered, we've completed a word
3. Add word to result string with appropriate spacing:
   - If result is empty, this is the last word (no space needed after it)
   - If result is not empty, add space after the word

#### Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

string result(string s) {
    int left = 0;
    int right = s.length()-1;
    
    string temp = "";
    string ans = "";
    
    // Iterate through string to form words
    while (left <= right) {
        char ch = s[left];
        if (ch != ' ') {
            temp += ch;
        } 
        else if (ch == ' ') {
            if (ans != "") 
                ans = temp + " " + ans;
            else 
                ans = temp;
            temp = "";
        }
        left++;
    }
    
    // Handle last word
    if (temp != "") {
        if (ans != "") 
            ans = temp + " " + ans;
        else 
            ans = temp;
    }
    
    return ans;    
}

int main() {
    string st = "TUF is great for interview preparation";
    cout << "Before reversing words: " << endl;
    cout << st << endl;
    cout << "After reversing words: " << endl;
    cout << result(st);
    return 0;
}
```

#### Complexity Analysis
- **Time Complexity:** O(N), where N is the length of string
- **Space Complexity:** O(1), constant extra space

## Sample Output
```
Before reversing words:
TUF is great for interview preparation
After reversing words:
preparation interview for great is TUF
```
