#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and value of the item
struct Item {
    int value;
    int weight;
};

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute the maximum value that can be obtained by
// fractional knapsack of capacity W
double fractionalKnapsack(int W, struct Item arr[], int n) {
	int i;
    // Sort items based on their value per weight ratio (value/weight)
    for (i = 0; i < n; i++) {
    	int j;
        for ( j = i + 1; j < n; j++) {
            double ratio1 = (double)arr[i].value / arr[i].weight;
            double ratio2 = (double)arr[j].value / arr[j].weight;
            if (ratio1 < ratio2) {
                // Swap arr[i] and arr[j]
                struct Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    // Loop through all items
    i;
    for (i = 0; i < n; i++) {
        // If adding the current item won't overflow the knapsack, add it fully
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        // If adding the current item will overflow the knapsack, add the fraction of it
        else {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

// Driver program to test above function
int main() {
    int W = 50; // Knapsack capacity
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // Array of items
    int n = sizeof(arr) / sizeof(arr[0]); // Number of items

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %lf\n", maxValue);

    return 0;
}
