#include <stdio.h>

void FCFS(int frames, int pages, int page[]) {
    int i, j, f = 0, count = 0;
    int frame[10];
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    for (i = 0; i < pages; i++) {
        int flag = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                f++;
                break;
            }
        }
        if (flag == 0) {
            frame[count % frames] = page[i];
            count++;
        }
    }
    int faults = pages - f;
    printf("\nPage Hit using FCFS: %d\n", f);
    printf("\nPage Faults using FCFS: %d\n", faults);
}

void LRU(int frames, int pages, int page[]) {
    int i, j, f = 0, count = 0;
    int frame[10];
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    for (i = 0; i < pages; i++) {
        int flag = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                f++;
                break;
            }
        }
        if (flag == 0) {
            for (j = 0; j < frames - 1; j++) {
                frame[j] = frame[j + 1];
            }
            frame[frames - 1] = page[i];
        }
    }
    int faults = pages - f;
    printf("\nPage Hit using LRU: %d\n", f);
    printf("\nPage Faults using LRU: %d\n", faults);
}

void Optimal(int frames, int pages, int page[]) {
    int i, j, k, f = 0;
    int frame[10];
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    for (i = 0; i < pages; i++) {
        int flag = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                f++;
                break;
            }
        }
        if (flag == 0) {
            int max = -1, index = -1;
            for (j = 0; j < frames; j++) {
                int temp = 0;
                for (k = i + 1; k < pages; k++) {
                    if (frame[j] == page[k]) {
                        break;
                    }
                    temp++;
                }
                if (temp > max) {
                    max = temp;
                    index = j;
                }
            }
            frame[index] = page[i];
        }
    }
    int faults = pages - f;
    printf("\nPage Hit using Optimal: %d\n", f);
    printf("\nPage Faults using Optimal: %d\n", faults);
}

int main() {
    int frames, pages, i, choice;
    int page[30];

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    printf("Enter the reference string: ");
    for (i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }
	do{
		
	
    printf("Choose the Page Replacement Algorithm:\n1. FCFS\n2. LRU\n3. Optimal\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FCFS(frames, pages, page);
            break;
        case 2:
            LRU(frames, pages, page);
            break;
        case 3:
            Optimal(frames, pages, page);
            break;
        case 4:
        	exit(0);
        	break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
    }
}while(choice != 5);

    return 0;
}

 