#include <stdio.h>
#include <stdlib.h>

typedef struct cvor {
    char x;
    struct cvor* lijevi;
    struct cvor* desni;
} Cvor;


void dodaj(Cvor** korijen, char vrijednost) {
    Cvor* nadredjeni = NULL;
    Cvor* trenutni = *korijen;

    while (trenutni != NULL) {
        nadredjeni = trenutni;
        if (vrijednost < trenutni->x)
            trenutni = trenutni->lijevi;
        else if (vrijednost > trenutni->x)
            trenutni = trenutni->desni;
        else
            return;
    }

    Cvor* novi = (Cvor*)malloc(sizeof(Cvor));
    if (novi == NULL) {
        exit(0);
    }
    novi->x = vrijednost;
    novi->lijevi = novi->desni = NULL;

    if (nadredjeni == NULL)
        *korijen = novi;
    else if (vrijednost < nadredjeni->x)
        nadredjeni->lijevi = novi;
    else
        nadredjeni->desni = novi;
}

void preorder(Cvor* cvor) {
    if (cvor != NULL) {
        printf("%c ", cvor->x);
        preorder(cvor->lijevi);
        preorder(cvor->desni);
    }
}

void inorder(Cvor* cvor) {
    if (cvor == NULL) return;
    if (cvor->lijevi != NULL) inorder(cvor->lijevi);
    printf("%c ", cvor->x);
    if (cvor->desni != NULL) inorder(cvor->desni);
}

void postorder(Cvor* cvor) {
    if (cvor == NULL) return;
    if (cvor->lijevi != NULL) postorder(cvor->lijevi);
    if (cvor->desni != NULL) postorder(cvor->desni);
    printf("%c ", cvor->x);
}

int main() {
    Cvor* stablo = NULL;

    dodaj(&stablo, 'S');
    dodaj(&stablo, 'a');
    dodaj(&stablo, 'n');
    dodaj(&stablo, 'd');
    dodaj(&stablo, 'r');
    dodaj(&stablo, 'o');
    dodaj(&stablo, 'S');
    dodaj(&stablo, 'a');
    dodaj(&stablo, 'v');
    dodaj(&stablo, 'i');

    printf("Preorder obilazak: ");
    preorder(stablo);
    printf("\n");

    printf("Inorder obilazak: ");
    inorder(stablo);
    printf("\n");

    printf("Postorder obilazak: ");
    postorder(stablo);
    printf("\n");

    return 0;
}