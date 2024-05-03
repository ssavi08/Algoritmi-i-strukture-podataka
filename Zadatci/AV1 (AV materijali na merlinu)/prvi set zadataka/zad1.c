//1.
//Zadana je cjelobrojna matrica A od M redaka i N stupaca. Vrijednosti matrice su popunjene nulama i
//jedinicama. Potrebno je dati algoritam koji će ispisati koliko u toj matrici ima podmatrica dimenzije 2x2
//koje su u cijelosti popunjene jedinicama. Dopušteno je i preklapanje!
//Napisati koja je složenost vašeg algoritma.

#include <stdio.h>

int main(void){

    int i, j;
    int m = 6, n = 5;
    int mat[6][5] = {{0,1,1,1,1},
                     {1,1,1,1,1},
                     {1,1,0,0,1},
                     {0,0,0,0,0},
                     {1,1,1,0,0},
                     {1,1,1,1,1}};

    int brojac = 0;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(i != m-1 && j != n-1){
                if(mat[i][j] == 1 && mat[i][j] == mat[i+1][j] && mat[i][j] == mat[i][j+1] && mat[i][j] == mat[i+1][j+1]){
                    brojac++;
                }
            }
        }
    }
    printf("%d", brojac);

    return 0;
}

//Ovaj algoritam ima dvije ugniježđene for petlje koje prolaze kroz matricu dimenzija m x n.
//Unutar unutrašnje petlje, provjerava se da li je trenutni element na poziciji (i, j) jednak 1 i da li su svi elementi
//u gornjem lijevom, gornjem desnom, donjem lijevom i donjem desnom susjedu također jednaki 1.
//Ako jesu, povećava se brojač.

//Složenost ovog algoritma je O(m * n), gdje je m broj redova matrice, a n broj stupaca matrice.
//Budući da se provjeravaju svi elementi matrice, složenost je linearna u odnosu na veličinu matrice.