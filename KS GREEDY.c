#include <stdio.h>
#include <stdlib.h>

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value per unit weight
int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio_b = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    if (ratio_a > ratio_b) return -1; // Sort in descending order
    else if (ratio_a < ratio_b) return 1;
    else return 0;
}

// Function to solve fractional knapsack problem
double fractional_knapsack(struct Item items[], int n, int capacity) {
    // Sort items based on value per unit weight
    qsort(items, n, sizeof(struct Item), compare);
    
    double total_value = 0.0;
    int remaining_capacity = capacity;
    
    // Declare loop variable outside the loop
    int i;
    
    // Iterate through sorted items and add them to knapsack greedily
    for (i = 0; i < n; i++) {
        if (remaining_capacity >= items[i].weight) {
            // Take the whole item
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            total_value += (double)remaining_capacity / items[i].weight * items[i].value;
            break; // Knapsack full
        }
    }
    
    return total_value;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    
    double max_value = fractional_knapsack(items, n, capacity);
    printf("Maximum value that can be obtained: %.2lf\n", max_value);
    
    return 0;
}

