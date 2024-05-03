//2.
//Zadan je cjelobrojni niz V od N elemenata. Svi brojevi u nizu su pozitivni. Zadan je i pozitivan broj C.
//Potrebno je dati algoritam koji će ispitati da li postoje 2 elementa niza V čija suma iznosi točno C.
//Ako takvi elementi postoje, potrebno je ispisati na kojim mjestima se u nizu oni nalaze.
//Ako ne postoje takva 2 broja onda ispisati odgovarajuću poruku. Napisati također koja je složenost vašeg algoritma.

#include <stdio.h>
#include <stdbool.h>

int main(void){

    int V[] = {2,4,8,8};
    int n = sizeof(V) / sizeof(V[0]);
    int c = 16, i, j;
    bool exists = false;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j){
                if(V[i] + V[j] == c){
                    printf("%d + %d = %d\n", i, j, c);
                    exists = true;
                }
            }
        }
    }

    if(!exists){
        printf("Ne postoje");
    }

    return 0;
}

//Ovaj algoritam ima dvije ugniježđene petlje koje prolaze kroz niz V dužine n.
//Unutar unutrašnje petlje, provjerava se da li je zbroj elemenata na pozicijama i i j jednak c.
//Ako jest, ispisuje se zbroj i indeksi tih elemenata, a postavlja se indikator exists na true.

//Složenost ovog algoritma je O(n^2), gdje je n duljina niza V.
//Budući da se prolazi kroz sve kombinacije parova elemenata u nizu, složenost raste kvadratno u odnosu na duljinu niza.