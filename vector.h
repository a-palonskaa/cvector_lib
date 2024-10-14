#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct {
	size_t size;
	size_t capacity;
	void* data;
} vector_t;

//============================================================================================
// insert element at position pos
#define vector_insert_(vec, pos, val_addr)                                      \
    do {                                                                        \
		vector_insert(get_vector(vec_addr), (pos), (val), sizeof(*(val_addr))); \
    } while (0)

#define vector_push_back_(vec_addr, src_addr)                                \
	do {                                                                     \
        memory_add_to_fit(get_vector(vec_addr), sizeof(*src_addr));          \
	    vector_push_back(get_vector(vec_addr), src_addr, sizeof(*src_addr)); \
    } while (0)

#define vector_pop_back_(vec_addr, dst_addr)                                \
	do {																	\
		vector_pop_back(get_vector(vec_addr), dst_addr, sizeof(*dst_addr)); \
	} while(0)

//============================================================================================

#define vector_size_(vec_addr)                           \
	(vec_addr) ? get_vector(vec_addr)->size : (size_t) 0

#define vector_capacity_(vec_addr)                           \
	(vec_addr) ? get_vector(vec_addr)->capacity : (size_t) 0

#define vector_tail_ptr(vec_addr)                      \
    (vec_addr) ? get_vector(vec_addr)->data : nullptr

#define cvector_head_ptr_(vec_addr)                                                                   \
	(vec_addr) ? ((void*)((char*) get_vector(vec_addr)->data + get_vector(vec_addr)->size)) : nullptr

#define vector_element_ptr_(vec, n, elm_size)                                      \
    ((vec) ? (((int)(n) < 0 || (size_t)(n) > cvector_size(vec)) ? nullptr :        \
	((void*)(((char*) get_vector(vec_addr)->data) + (elm_size) * (n)))) : nullptr)

//============================================================================================

//resize to caapacity n
#define vector_reserve_(vec_addr, n)                   \
    do {                                               \
		if (!vec_addr) {                               \
			return;                                    \
		}                                              \
        size_t capacity =  vector_capacity_(vec_addr); \
        if (capacity < (n)) {                          \
            memory_add(get_vector(vec_addr), (n));     \
        }                                              \
    } while (0)

#define vector_shrink_to_fit_(vec_addr)                               \
    do {                                                              \
        if (!vec_addr) {                                              \
			return;                                                   \
		}                                              			      \
        memory_add(get_vector(vec_addr), get_vector(vec_addr)->size); \
    } while (0)

//frees all memory associated with the vector
#define vector_free(vec_addr)                 \
    do {                                      \
       	free(get_vector(vec_addr)->data);	  \
		get_vector(vec_addr)->data = nullptr; \
		free(get_vector(vec_addr));			  \
		get_vector(vec_addr) = nullptr;       \
    } while (0)

//erase all of the elements in the vector
#define vector_clear(vec_addr)                                              \
    do {                                                                    \
		if (!vec_addr) {                                                    \
			return;                                                         \
		}																	\
		memset(get_vector(vec_addr)->data, 0, get_vector(vec_addr)->size);  \
    	get_vector(vec_addr)->size = 0;                                     \
    } while (0)

//============================================================================================

vector_t* get_vector(void* vec);
void* new_vector();

int vector_has_space(vector_t* vec, size_t len);
void memory_add_to_fit(vector_t* vec, size_t len);

void vector_push_back(vector_t* vec, void* src, size_t elm_width);
void vector_pop_back(vector_t* vec, void* dst, size_t elm_width);
void vector_erase_elm(void* vec, size_t i, size_t elm_width);
void vector_erase_range(void* vec, size_t first, size_t last, size_t elm_width);
void vector_insert(vector_t* vec, size_t pos, void* elm, size_t elm_width);

#endif /* VECTOR_H */
