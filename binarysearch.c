#include <stdio.h>

// Function to perform binary search on a sorted array arr[]
// Returns the index of target if it is present in the array, otherwise returns -1
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If we reach here, then the element was not present in the array
    return -1;
}

// Driver program to test above function
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int target = 10;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, arr_size - 1, target);
    if (result != -1)
        printf("Element %d is present at index %d\n", target, result);
    else
        printf("Element %d is not present in the array\n", target);

    return 0;
}
