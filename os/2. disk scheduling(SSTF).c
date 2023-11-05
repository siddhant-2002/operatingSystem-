#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int abs(int a) {
    return (a >= 0) ? a : -a;
}

int findClosestRequest(int *requests, int n, int head) {
    int minDistance = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (abs(requests[i] - head) < minDistance) {
            minDistance = abs(requests[i] - head);
            index = i;
        }
    }

    return index;
}

void SSTF(int *requests, int n, int head) {
    int totalMovement = 0;
    int currentHead = head;

    printf("Sequence of movement: ");
    for (int i = 0; i < n; i++) {
        int closestRequestIndex = findClosestRequest(requests, n, currentHead);
        totalMovement += abs(requests[closestRequestIndex] - currentHead);
        printf("%d ", requests[closestRequestIndex]);
        currentHead = requests[closestRequestIndex];
        requests[closestRequestIndex] = INT_MAX; // Mark as visited
    }

    printf("\nTotal head movement: %d\n", totalMovement);
}

int main() {
    int n, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int *requests = (int *)malloc(n * sizeof(int));
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    SSTF(requests, n, head);
    free(requests);
    return 0;
}