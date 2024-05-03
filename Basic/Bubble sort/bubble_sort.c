#include <stdio.h>
#include <stdbool.h>

void bubblesort(int arr[], int n);
void printArray(int arr[], int size);

int main(void){

    int arr[6] = { 64, 34, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n);
    bubblesort(arr, n);
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int size){

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void bubblesort(int arr[], int n){

    int temp;
    bool swapped; // dodatna varijabla za zaustavljanje, UVELIKE OPTIMIZIRA KOD
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}