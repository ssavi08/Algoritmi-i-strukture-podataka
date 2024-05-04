//3.
//Zadan je niz V={1,1,2,3,4,4,4,4,5,6,7,11,11,14,15,16,18,19,19,19,19,20,21,22,22,23,26,27,29,30,32}.
//Opisati izvođenje algoritma BINARNO PRETRAŽIVANJE za podatke:
//a) X = 31
//b) X = 30
//Napisati tablicu u kojoj će se pratiti vrijednosti sljedećih varijabli: sredina, dg, gg.
//Za svako ponavljanje petlje u algoritmu napisati jedan redak tablice.
//Iza tablice opisati na koji način je završio algoritam,
//te koliko ponavljanja je algoritam napravio. Napisati također koliko najviše ponavljanja ovaj algoritam radi i zašto.

#include <stdio.h>

int binarys(int arr[], int x, int n);

int main(void){

    int arr[] = {1,1,2,3,4,4,4,4,5,6,7,11,11,14,15,
                 16,18,19,19,19,19,20,21,22,22,23,26,
                 27,29,30,32};

    int l, r, x, y, mid, n, i = 0;
    n = sizeof(arr) / sizeof(arr[0]);

    binarys(arr, 31, n);
    printf("\n");
    binarys(arr, 30, n);

    return 0;
}


int binarys(int arr[], int x, int n){
    int r = n - 1;
    int l = 0;
    int mid, i = 0;
    printf("Trazi se broj %d.\n", x);
    while(l <= r){
        mid = l + (r-l)/2;
        if(i == 0){
            printf("%d. iteracija: l: %d, r: %d, mid: %d\n", i+1, l, r, mid);
        }
        i++;
        if(x == arr[mid]){
            printf("Pronaden broj %d.\n", x);
            return mid;
        };
        if(x > mid){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
        if(l > r){
            printf("Broj nije pronaden..\n");
            break;
        }
        
        printf("%d. iteracija: l: %d, r: %d, mid: %d\n", i+1, l, r, mid = l + (r-l)/2);
    }

    return -1;
}