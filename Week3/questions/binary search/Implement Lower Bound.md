## Problem Statement
Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

## Solution
The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

Now, we will learn how to implement the lower bound algorithm using a slight modification of the Binary Search algorithm. 

## What is Lower Bound?
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key, i.e., x.

The lower bound is the smallest index, `ind`, where `arr[ind] >= x`. If no such index is found, the lower bound algorithm returns `n`, i.e., the size of the given array.

### Brute Force Approach
**Naive approach (Using linear search):**
Let’s understand how we can find the answer using the linear search algorithm. With the knowledge that the array is sorted, our approach involves traversing the array starting from the beginning. During this traversal, each element will be compared with the target value, `x`. The index, `i`, where the condition `arr[i] >= x` is first satisfied, will be the answer.

```cpp
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}
```

**Time Complexity:** O(N), where N = size of the given array.  
**Reason:** In the worst case, we have to traverse the whole array. This is essentially the time complexity of the linear search algorithm.

**Space Complexity:** O(1) as we are using no extra space.

---

### Optimal Approach
**Optimal Approach (Using Binary Search):**

As the array is sorted, we will apply the Binary Search algorithm to find the index. The steps are as follows:

1. Declare two pointers and an `ans` variable initialized to `n` (i.e., the size of the array, as if we don’t find any index, we will return `n`).
2. Place the two pointers:
   - `low` will point to the first index.
   - `high` will point to the last index.
3. Calculate the `mid` using the formula:
   ```
   mid = (low + high) // 2
   ```
4. Compare `arr[mid]` with `x`:
   - **Case 1**: If `arr[mid] >= x`, the index `mid` may be an answer. Update the `ans` variable with `mid` and search in the left half to check for a smaller index that satisfies the same condition. Eliminate the right half by updating `high`.
   - **Case 2**: If `arr[mid] < x`, eliminate the left half and search in the right half by updating `low`.
5. Continue until the pointer `low` crosses `high`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}
```

**Time Complexity:** O(logN), where N = size of the given array.  
**Reason:** We are essentially using the Binary Search algorithm.

**Space Complexity:** O(1) as we are using no extra space.
