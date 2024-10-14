#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

#define vector_push_back_(vec_addr, src_addr)                                \
	do {                                                                     \
        memory_check(get_vector(vec_addr), sizeof(*src_addr));               \
	    vector_push_back(get_vector(vec_addr), src_addr, sizeof(*src_addr)); \
    } while (0)

#define vector_pop_back_(vec_addr, dst_addr)                             \
	vector_pop_back(get_vector(vec_addr), dst_addr, sizeof(*dst_addr))

#define vector_size_(vec_addr)                           \
    (vec_addr) ? get_vector(vec_addr)->size : (size_t) 0

#define vector_capacity_(vec_addr)                           \
    (vec_addr) ? get_vector(vec_addr)->capacity : (size_t) 0

typedef struct {
	size_t size;
	size_t capacity;
	void* data;
} vector_t;

vector_t* get_vector(void* vec);
void* new_vector();

int vector_has_space(vector_t* vec, size_t len);
void memory_check(vector_t* vec, size_t len);

void vector_push_back(vector_t* vec, void* src, size_t elm_width);
void vector_pop_back(vector_t* vec, void* dst, size_t elm_width);
void vector_erase_elm(void* vec, size_t i, size_t elm_width);
void vector_erase_range(void* vec, size_t first, size_t last, size_t elm_width);

#endif /* VECTOR_H */
