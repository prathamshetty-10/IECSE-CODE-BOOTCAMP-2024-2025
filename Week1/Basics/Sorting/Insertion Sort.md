# Insertion Sort 
## Implementation
* We start with second element of the array as first element in the array is assumed to be sorted.
* Compare second element with the first element and check if the second element is smaller then swap them.
* Move to the third element and compare it with the first two elements and put at its correct position
* Repeat until the entire array is sorted.

## Code
```
#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}
```
## Working
![image](https://github.com/user-attachments/assets/7bd31c3b-427f-42ff-9ac7-1cea9a23460d)

Initially, the first two elements are compared in insertion sort.

![image](https://github.com/user-attachments/assets/975da88a-462b-462b-b8a2-29883d5e0d85)

Here, 31 is greater than 12. That means both elements are already in ascending order. So, for now, 12 is stored in a sorted sub-array.

![image](https://github.com/user-attachments/assets/f2037ee7-e509-4732-b580-d89cfe85ee5e)

Now, move to the next two elements and compare them.

![image](https://github.com/user-attachments/assets/711318cf-5649-4f00-8f0c-17e58b214ec4)

Here, 25 is smaller than 31. So, 31 is not at correct position. Now, swap 31 with 25. Along with swapping, insertion sort will also check it with all elements in the sorted array.

For now, the sorted array has only one element, i.e. 12. So, 25 is greater than 12. Hence, the sorted array remains sorted after swapping.

![image](https://github.com/user-attachments/assets/70f5e301-f74c-4430-9d0f-54510b1863f0)

Now, two elements in the sorted array are 12 and 25. Move forward to the next elements that are 31 and 8.

![image](https://github.com/user-attachments/assets/eab9bfcb-a249-46fe-997a-25f403c472f6)

Both 31 and 8 are not sorted. So, swap them.

![image](https://github.com/user-attachments/assets/40ba4e67-2f8f-45d4-96db-079fb13fc876)

After swapping, elements 25 and 8 are unsorted.

![image](https://github.com/user-attachments/assets/dc8337e6-ba5e-4dc0-b182-4fffdcf397a2)

So, swap them.

![image](https://github.com/user-attachments/assets/aff7a746-1982-4fe2-87d8-7d5bd6e20fcc)

Now, elements 12 and 8 are unsorted.

![insertion-sort10](https://github.com/user-attachments/assets/9b240a5f-0ecb-4d90-a082-aad170eff1ad)

So, swap them too.

![insertion-sort11](https://github.com/user-attachments/assets/fbf3b63c-b640-4340-829e-3115a0da1359)

Now, the sorted array has three items that are 8, 12 and 25. Move to the next items that are 31 and 32.

![insertion-sort12](https://github.com/user-attachments/assets/e6f98177-35d0-4820-aa3b-6e72a3a2c7d2)

Hence, they are already sorted. Now, the sorted array includes 8, 12, 25 and 31.

![insertion-sort13](https://github.com/user-attachments/assets/9d21a887-65c4-45fc-86c9-20833a289439)

Move to the next elements that are 32 and 17.

![insertion-sort14](https://github.com/user-attachments/assets/21376658-9389-44a9-955a-f12de5645953)

17 is smaller than 32. So, swap them

![insertion-sort15](https://github.com/user-attachments/assets/ed8d429a-be8d-4147-afc3-c1e42eeeeac5)

Swapping makes 31 and 17 unsorted. So, swap them too.

![insertion-sort16](https://github.com/user-attachments/assets/5bde3215-75a9-4dcd-88b6-c8b4d650aa16)

Now, swapping makes 25 and 17 unsorted. So, perform swapping again.

![insertion-sort17](https://github.com/user-attachments/assets/6e22f5ca-dc6e-4fb3-859a-634d188a315a)

Now, the array is completely sorted.

Time Complexity: Best Case - It occurs when there is no sorting required, i.e. the array is already sorted. The best-case time complexity of insertion sort is O(n).

Worst Case -  It occurs when the array elements are required to be sorted in reverse order. That means suppose you have to sort the array elements in ascending order, but its elements are in descending order. The worst-case time complexity of insertion sort is O(n^2).

Space Complexity - O(1). It is because, in insertion sort, an extra variable is required for swapping.

## Resources:
https://takeuforward.org/data-structure/insertion-sort-algorithm/

https://www.geeksforgeeks.org/insertion-sort-algorithm/





















