# Koko Eating Bananas

## Problem Statement
A monkey is given 'n' piles of bananas, whereas the 'ith' pile has 'a[i]' bananas. An integer 'h' is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats 'k' bananas. If the pile contains less than 'k' bananas, then the monkey consumes all the bananas and won't eat any more bananas in that hour.

Find the minimum number of bananas 'k' to eat per hour so that the monkey can eat all the bananas within 'h' hours.

## Examples

### Example 1:
**Input Format:**
- N = 4, a[] = {7, 15, 6, 3}, h = 8

**Result:** 5

**Explanation:**
If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.

### Example 2:
**Input Format:**
- N = 5, a[] = {25, 12, 8, 14, 19}, h = 5

**Result:** 25

**Explanation:**
If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.

## Understanding the Problem

Let's understand how Koko will eat the bananas. Assume, the given array is {3, 6, 7, 11} and the given time i.e. h is 8.

1. Koko cannot eat bananas from different piles. He should complete the pile he has chosen and then he can go for another pile.
2. If Koko decides to eat 2 bananas/hour:
   - For first pile (3 bananas): ceil(3/2) = 2 hrs
   - For second pile (6 bananas): ceil(6/2) = 3 hrs
   - For third pile (7 bananas): ceil(7/2) = 4 hrs
   - For fourth pile (11 bananas): ceil(11/2) = 6 hrs
   
Total time = 15 hours

**Observation:** The maximum number of bananas ('k') that Koko can consume in an hour is obtained from the pile that contains the largest quantity of bananas. Therefore, the maximum value of 'k' corresponds to the maximum element present in the given array.

## Brute Force Approach

### Algorithm / Intuition
The extremely naive approach is to check all possible answers from 1 to max(a[]). The minimum number for which the required time <= h, is our answer.

### Algorithm
1. Find the maximum value i.e. max(a[]) in the given array
2. Run a loop from 1 to max(a[]), to check all possible answers
3. For each number i, calculate the hours required using calculateTotalHours()
4. Return the first i for which the required hours <= h

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}

int main() {
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
```

### Complexity Analysis
- **Time Complexity:** O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array
- **Space Complexity:** O(1)

## Optimal Approach

### Algorithm / Intuition
We can optimize the approach using Binary Search. While we don't have a sorted array, our answer space [1, max(a[])] is sorted, making it suitable for binary search.

### Algorithm
1. Find the maximum element in the array (max(a[]))
2. Set pointers: low = 1 and high = max(a[])
3. While low <= high:
   - Calculate mid = (low + high) // 2
   - Calculate total hours needed with mid bananas/hour
   - If totalH <= h: eliminate right half (high = mid - 1)
   - Else: eliminate left half (low = mid + 1)
4. Return low

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
```

### Complexity Analysis
- **Time Complexity:** O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array
- **Space Complexity:** O(1)
