#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

void bubbleSort(int arr[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arraySize = 100000; // Fast Output process er jonno 10,000 rakha hoyeche
    int count=0;
    int *unsortedArray = (int *)malloc(arraySize * sizeof(int));

    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: numbers.txt file not found!\n");
        free(unsortedArray);
        return 1;
    }

    for (int i = 0; i < arraySize; i++) {
        fscanf(file, "%d", &unsortedArray[i]);
    }
    fclose(file);

    printf("Data loaded. Sorting started...\n");

    //clock_t start = clock();
    bubbleSort(unsortedArray, arraySize);
    //clock_t end = clock();

    //double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    //printf("Sorting completed in %f seconds!\n\n", time_taken);

    // ==========================================
    // Full Sorted Array Screen e Print korar Loop
    // ==========================================
    printf("--- Sorted Array Elements ---\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", unsortedArray[i]);
        count++;
    }
    printf("\ntotal output: %d", count);
    free(unsortedArray);
    return 0;
}
