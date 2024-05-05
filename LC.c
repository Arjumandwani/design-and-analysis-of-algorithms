#include <stdio.h>

// Function to perform linear congruential search
int linearCongruentialSearch(int array[], int n, int key) {
    int index = key % n; // Compute the initial index
    
    // Linear probing loop
    while (array[index] != key && array[index] != -1) {
        index = (index + 1) % n; // Move to the next location
    }
    
    // If the element is found, return its index, otherwise return -1
    if (array[index] == key)
        return index;
    else
        return -1;
}

int main() {
    int array[] = {37, 22, 44, 77, 55, -1, 99}; // Example array with -1 indicating empty locations
    int n = sizeof(array) / sizeof(array[0]); // Size of the array
    int key = 55; // Element to search
    
    int index = linearCongruentialSearch(array, n, key);
    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found\n", key);
    
    return 0;
}

