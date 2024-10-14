#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"


int main() {
    void* h = new_vector();
    int a = 666;
    vector_push_back_(h, &a);
    a = 100;
    vector_push_back_(h, &a);
    a = 24;
    vector_push_back_(h, &a);
    a = 98;
    vector_push_back_(h, &a);
    vector_erase_range(h, 3, 4, sizeof(int));
    int b = 0;
    vector_pop_back_(h, &b);
    printf("%d\n", b);
    b = 0;
    vector_pop_back_(h, &b);
    printf("%d\n", b);
    b = 0;
    vector_pop_back_(h, &b);
    printf("%d\n", b);
};
