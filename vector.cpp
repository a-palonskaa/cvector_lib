#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

//============================================================================================

vector_t* get_vector(void* vec) {
    return ((vector_t*)((char*) vec + sizeof(void*) - sizeof(vector_t)));
}

void* new_vector() {
    vector_t* vector = (vector_t*) calloc(sizeof(vector_t), sizeof(char));
	vector->size = 0;
	vector->capacity = 1;
	vector->data = calloc(vector->capacity, sizeof(char));
    return &vector->data;
}

//============================================================================================

void vector_push_back(vector_t* vec, void* src, size_t elm_width) {
	memcpy((char*) vec->data + vec->size, src, elm_width);
	vec->size += elm_width;
}

void vector_pop_back(vector_t* vec, void* dst, size_t elm_width) {
	if (vec->size <= 0) {
		return;
	}
	memcpy(dst, (char*) vec->data + vec->size - elm_width, elm_width);
	memset((char*) vec->data + vec->size - elm_width, 0, elm_width);
	vec->size -= elm_width;
}

//============================================================================================

int vector_has_space(vector_t* vec, size_t len) {
	return (int) vec->capacity - (int) vec->size + len;
}

void memory_add_to_fit(vector_t* vec, size_t len) {
	while (!vector_has_space(vec, len)) {
		vec->capacity *= 2;
	}
	vec->data = realloc(vec->data, vec->capacity);
}

void memory_add(vector_t* vec, size_t new_capacity) {
	vec->data = realloc(vec->data, new_capacity);
	vec->capacity = new_capacity;
}

//============================================================================================

void vector_insert(vector_t* vec, size_t pos, void* elm, size_t elm_width) {
	memcpy((char*) vec->data + (pos - 1) * elm_width, elm, vec->size - pos * elm_width);
}

void vector_erase_elm(void* vec, size_t pos, size_t elm_width) {
    memcpy((char*) get_vector(vec)->data + (pos - 1) * elm_width,
            get_vector(vec)->data, get_vector(vec)->size - pos * elm_width);
	get_vector(vec)->size -= elm_width;
	memset((char*) get_vector(vec)->data + get_vector(vec)->size, 0, elm_width);
}

void vector_erase_range(void* vec, size_t first, size_t last, size_t elm_width) {
	memcpy((char*) get_vector(vec)->data + (first - 1) * elm_width,
           (char*)get_vector(vec)->data + last * elm_width, get_vector(vec)->size - last * elm_width);
	get_vector(vec)->size -= elm_width * (1 + last - first);
	memset((char*) get_vector(vec)->data + get_vector(vec)->size, 0, elm_width * (1 + last - first));
}

//============================================================================================
