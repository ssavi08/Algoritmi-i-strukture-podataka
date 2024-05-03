#include <stdio.h>

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(void){

    int arr[7] = {2, 5, 1, 13, 16, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

void insertionSort(int arr[], int n){

    int key;

    for(int i = 1; i < n; i++){
        key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}