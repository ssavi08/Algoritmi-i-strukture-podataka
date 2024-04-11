#include <stdio.h>
#include <stdint.h>

#define GB (1024 * 1024 * 1024)

typedef struct Node {
    int data;
    struct Node* next;
} Node;


uint64_t max_el_niz(uint64_t dostupna_mem, uint64_t velicina_el) {
    uint64_t max_elements = (dostupna_mem * GB) / velicina_el;
    return max_elements;
}


uint64_t max_el_list(uint64_t dostupna_mem, uint64_t velicina_node) {
    uint64_t max_nodes = (dostupna_mem * GB) / (sizeof(Node) + velicina_node);
    return max_nodes;
}

int main() {
    uint64_t dostupna_mem = 16;
    uint64_t velicina_el = sizeof(int);
    uint64_t velicina_node = sizeof(Node);
    uint64_t max_el_result = max_el_niz(dostupna_mem, velicina_el);
    uint64_t max_el_list_result = max_el_list(dostupna_mem, velicina_el);

    printf("max broj elemenata N niza: %llu\n", max_el_result);
    printf("max broj elemenata N povezanog popisa: %llu\n", max_el_list_result);

    return 0;
}