## Problem Statement
You're given a sorted array `arr` of `n` integers and an integer `x`. Find the **floor** and **ceiling** of `x` in `arr[0..n-1]`.

The **floor** of `x` is the largest element in the array which is smaller than or equal to `x`.
The **ceiling** of `x` is the smallest element in the array greater than or equal to `x`.

---

## Pre-requisite: Lower Bound & Binary Search

### Example 1:
**Input Format:**
```
n = 6, arr[] = {3, 4, 4, 7, 8, 10}, x = 5
```
**Result:**
```
4 7
```
**Explanation:**
The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

---

### Example 2:
**Input Format:**
```
n = 6, arr[] = {3, 4, 4, 7, 8, 10}, x = 8
```
**Result:**
```
8 8
```
**Explanation:**
The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

---

## Solution
We are going to solve this problem using the concepts of **Lower Bound** and **Binary Search**.

---

### What is the Floor of `x`?
The floor of `x` is the largest element in the array which is smaller than or equal to `x` (i.e., the largest element in the array ≤ `x`).

### What is the Ceiling of `x`?
The ceiling of `x` is the smallest element in the array greater than or equal to `x` (i.e., the smallest element in the array ≥ `x`).

---

## Algorithm / Intuition

### Floor
1. Declare two pointers `low` and `high`, and an `ans` variable initialized to `-1` (to handle cases where no floor exists).
2. Use binary search:
   - If `arr[mid] ≤ x`, store `arr[mid]` as a potential answer and eliminate the left half by moving `low` to `mid + 1`.
   - If `arr[mid] > x`, eliminate the right half by moving `high` to `mid - 1`.

### Ceiling
1. Declare two pointers `low` and `high`, and an `ans` variable initialized to `-1` (to handle cases where no ceiling exists).
2. Use binary search:
   - If `arr[mid] ≥ x`, store `arr[mid]` as a potential answer and eliminate the right half by moving `high` to `mid - 1`.
   - If `arr[mid] < x`, eliminate the left half by moving `low` to `mid + 1`.

---

## Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1; // look for larger number
        } else {
            high = mid - 1; // look on the left
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1; // look for smaller number
        } else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
}

int main() {
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
    return 0;
}
```

---

### Output for Example 1:
```
The floor and ceil are: 4 7
```

---

## Complexity Analysis

### Time Complexity
**O(logN)**, where `N` is the size of the array. 
- We are using binary search to find the floor and ceiling.

### Space Complexity
**O(1)**
- No extra space is used.

---

## Follow-up Question

### Why are we not explicitly checking for the largest or smallest during the floor or ceiling calculation?
- In the **floor algorithm**, every time we find a potential answer (`arr[mid] <= x`), we move to the right half to explore larger numbers.
- In the **ceil algorithm**, every time we find a potential answer (`arr[mid] >= x`), we move to the left half to explore smaller numbers.

In both cases, the direction of search ensures that we automatically find the largest or smallest number satisfying the condition, without additional checks.

---
