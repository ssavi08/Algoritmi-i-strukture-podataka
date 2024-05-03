#include <stdio.h>
void selectSort(int arr[], int n);
void swap(int* x, int* y);

int main(void){

    int arr[5] = { 4, 30, 6, 100,10};
    for(int i=0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectSort(arr, 5);
    for(int i=0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectSort(int arr[],int n){

    int i = 0;
    int min_indx = 0;

    for(i = 0; i < n-1; i++){
        min_indx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_indx]){
                min_indx = j;
            }
            if(min_indx != i){
                swap(&arr[min_indx], &arr[i]);
            }
        }
    }
}

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}