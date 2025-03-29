# Row with Maximum Ones

## Problem Statement
You have been given a non-empty grid 'mat' with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.

**Note:** If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

**Pre-requisite:** Lower Bound implementation, Upper Bound implementation, & Find the first occurrence of a number.

## Examples

### Example 1:
**Input Format:**
```
n = 3, m = 3
mat[] = 
1 1 1
0 0 1
0 0 0
```
**Result:** 0

**Explanation:** The row with the maximum number of ones is 0 (0 - indexed).

### Example 2:
**Input Format:**
```
n = 2, m = 2
mat[] = 
0 0
0 0
```
**Result:** -1

**Explanation:** The matrix does not contain any 1. So, -1 is the answer.

## Brute Force Approach

### Algorithm / Intuition
In the question, it is clearly stated that we should return -1 if the matrix does not contain any 1.

The extremely naive approach is to traverse the matrix using nested loops and for every single row count the number of 1's. Finally, return the row with the maximum no. of 1's. If multiple rows contain the maximum no. of 1's, return the row with the minimum index.

### Algorithm
1. Declare variables cnt_max (initialized with 0) and index (initialized with -1)
2. Traverse the matrix row by row
3. For each row, count the number of 1's
4. If current count > cnt_max, update cnt_max and index
5. Return index

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << 
         rowWithMax1s(matrix, n, m) << '\n';
}
```

### Complexity Analysis
- **Time Complexity:** O(n X m), where n = given row number, m = given column number
- **Space Complexity:** O(1)

## Optimal Approach

### Algorithm / Intuition
We can optimize this using Binary Search. While we cannot optimize the row traversal, we can optimize the counting of 1's for each row.

Instead of counting the number of 1's, we can use the formula:
`Number_of_ones = m(number of columns) - first occurrence of 1(0-based index)`

As each row is sorted, we can find the first occurrence of 1 using:
- lowerBound(1)
- upperBound(0)
- firstOccurrence(1)

### Algorithm
1. Declare variables cnt_max (initialized with 0) and index (initialized with -1)
2. Traverse the rows
3. For each row, use lowerBound() to get first occurrence of 1
4. Calculate number of ones using the formula
5. Update cnt_max and index if current count is greater
6. Return index

### Code

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
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << 
         rowWithMax1s(matrix, n, m) << '\n';
}
```

### Complexity Analysis
- **Time Complexity:** O(n X logm), where n = given row number, m = given column number
- **Space Complexity:** O(1)
