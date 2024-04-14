#include <stdio.h>

int main(){
    int n = 10;
    int V[10] = {3, 5, 8, 10, 11, 11, 13, 23, 24, 25};
    int trazeni_broj = 0;
    int donja_granica = 1;
    int gornja_granica = n;
    printf("Unesi broj kojeg trazis:");
    scanf("%d", &trazeni_broj);

    while(donja_granica <= gornja_granica){
        int sredina = (donja_granica+gornja_granica)/2;
        if(trazeni_broj == V[sredina]){
            printf("Pronaden."); break;
        }
        if(trazeni_broj > V[sredina]) donja_granica = sredina+1;
        if(trazeni_broj < V[sredina]) gornja_granica = sredina-1;
    }
    if(donja_granica >= gornja_granica)
        printf("Broj nije pronaden");
    return 0;
}