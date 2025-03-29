# Finding Median in Row-wise Sorted Matrix

## Problem Statement
Given a row-wise sorted matrix of size MXN, where M is the number of rows and N is the number of columns, find the median in the given matrix.

**Note:** MXN is odd.

## Examples

### Example 1
**Input Format:** M = 3, N = 3
```
matrix[][] = 1 4 9 
            2 5 6
            3 8 7
```
**Result:** 5

**Explanation:** If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

### Example 2
**Input Format:** M = 3, N = 3
```
matrix[][] = 1 3 8 
            2 3 4
            1 2 5
```
**Result:** 3

**Explanation:** If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. So, median = 3

## Solutions

### 1. Brute-force Approach

#### Algorithm
1. Use a loop (i) to select a particular row at a time
2. Use another loop (j) for every row to traverse each column
3. Store each element matrix[i][j] to a linear array/list
4. Return the middle element of the linear array

#### Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> lst;

    // Traverse the matrix and copy elements to list
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lst.push_back(matrix[i][j]);
        }
    }

    // Sort the list
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
```

#### Complexity Analysis
- **Time Complexity:** O(MXN) + O(MXN(log(MXN)))
  - O(MXN) for traversing the matrix
  - O(MXN(log(MXN))) for sorting the linear array
- **Space Complexity:** O(MXN) for the temporary list

### 2. Optimal Approach using Binary Search

#### Algorithm & Intuition
The optimal approach uses binary search to eliminate checking every element. The search space is between the minimum and maximum elements in the matrix.

**Key Observations:**
- Search space: [min(matrix), max(matrix)]
- For median x, numbers ≤ x should be > (MXN)/2
- Use upper bound concept for row-wise sorted property

#### Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    // Find range
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
```

#### Complexity Analysis
- **Time Complexity:** O(log(10^9)) × O(M(logN))
  - Search space is [0, 10^9]
  - Binary search takes O(log(10^9))
  - countSmallEqual() takes O(M(logN))
- **Space Complexity:** O(1) as no extra space is used
