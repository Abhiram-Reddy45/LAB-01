#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 18250   // Approximately 50 years of daily temperatures

// Swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Partition function for QuickSort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int *bubbleArray = (int *)malloc(SIZE * sizeof(int));
    int *quickArray = (int *)malloc(SIZE * sizeof(int));

    if (bubbleArray == NULL || quickArray == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random temperatures (-20°C to 40°C)
    for (int i = 0; i < SIZE; i++)
    {
        bubbleArray[i] = rand() % 61 - 20;
        quickArray[i] = bubbleArray[i];
    }

    clock_t start, end;
    double bubbleTime, quickTime;

    // Bubble Sort Timing
    start = clock();
    bubbleSort(bubbleArray, SIZE);
    end = clock();

    bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Quick Sort Timing
    start = clock();
    quickSort(quickArray, 0, SIZE - 1);
    end = clock();

    quickTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n=============================================\n");
    printf(" Temperature Sorting Performance Comparison\n");
    printf("=============================================\n");
    printf("Dataset Size : %d records\n\n", SIZE);

    printf("Bubble Sort Execution Time : %.6f seconds\n", bubbleTime);
    printf("Quick Sort Execution Time  : %.6f seconds\n", quickTime);

    if (bubbleTime > quickTime)
    {
        printf("\nQuick Sort is faster by %.2f times.\n",
               bubbleTime / quickTime);
    }
    else
    {
        printf("\nBubble Sort is faster.\n");
    }

    free(bubbleArray);
    free(quickArray);

    return 0;
}
