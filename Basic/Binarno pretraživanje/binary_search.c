#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x);

int main(void){

    int arr[6] = { 2, 4, 6, 10, 12, 14 };
    int r = sizeof(arr) / sizeof(arr[0]);
    printf("Unesi broj kojeg trazis:");
    int x;
    scanf("%d", &x);
    int result = binarySearch(arr, 0, r-1, x);
    (result == -1) ? printf("Ne sadrzi") : printf("Sadrzi.");

    return 0;

}

int binarySearch(int arr[], int l, int r, int x){

    while(l <= r){
        int m = l + (r - l) / 2;

        if( arr[m] == x )
            return m;

        if( arr[m] < x )
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

