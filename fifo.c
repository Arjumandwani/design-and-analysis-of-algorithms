#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int profit;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Job*)a)->profit) / (((struct Job*)a)->weight);
    double ratio_b = (double)(((struct Job*)b)->profit) / (((struct Job*)b)->weight);
    return ratio_b > ratio_a;
}

double maxProfit(struct Job jobs[], int n, int capacity) {
    int i; // declare loop variable here
    qsort(jobs, n, sizeof(struct Job), compare);
    
    int currentWeight = 0;
    double currentProfit = 0;
    
    for (i = 0; i < n; i++) {
        if (currentWeight + jobs[i].weight <= capacity) {
            currentWeight += jobs[i].weight;
            currentProfit += jobs[i].profit;
        }
        else {
            int remainingWeight = capacity - currentWeight;
            currentProfit += (double)(jobs[i].profit * remainingWeight) / jobs[i].weight;
            break;
        }
    }
    
    return currentProfit;
}

int main() {
    struct Job jobs[] = {{1, 60, 10}, {2, 100, 20}, {3, 120, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int capacity = 50;
    
    double max_profit = maxProfit(jobs, n, capacity);
    printf("Maximum profit using FIFO branch and bound: %.2f\n", max_profit);
    
    return 0;
}

