# Selection Sort
Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.
1. First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
2. Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.
3. We keep doing this until we get all elements moved to correct position.

![image](https://github.com/user-attachments/assets/ae349bdd-141b-47eb-be04-ca3a464579bd)

```
#include <iostream>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j; 
            }
        }

        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}

void printArray(vector<int> &arr) {
    for (int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr); 

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
```
Output: 
```
Original vector: 64 25 12 22 11 
Sorted vector:   11 12 22 25 64
```
## Complexity Analysis of Selection Sort
Time Complexity: O(n2) ,as there are two nested loops:

* One loop to select an element of Array one by one = O(n)
* Another loop to compare that element with every other Array element = O(n)
* Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n2)
* Auxiliary Space: O(1) as the only extra memory used is for temporary variables.

## Advantages of Selection Sort
* Easy to understand and implement, making it ideal for teaching basic sorting concepts.
* Requires only a constant O(1) extra memory space.
* It requires less number of swaps (or memory writes) compared to many other standard algorithms. Only cycle sort beats it in terms of memory writes. Therefore it can be simple algorithm choice when memory writes are costly.

## Disadvantages of the Selection Sort
* Selection sort has a time complexity of O(n^2) makes it slower compared to algorithms like Quick Sort or Merge Sort.
* Does not maintain the relative order of equal elements which means it is not stable.

## Resources:
https://takeuforward.org/sorting/selection-sort-algorithm/
https://www.geeksforgeeks.org/selection-sort-algorithm-2/



