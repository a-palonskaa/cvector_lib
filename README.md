# Vector Library

## Overview
The `cvector_lib` provides a dynamic array implementation in C. It offers functionality to insert, remove, and manipulate elements while automatically handling memory allocation and resizing.

## Features

- **Dynamic Resizing**: Automatically expands or shrinks the capacity of the vector as needed.
- **Element Insertion**: Insert elements at specified positions.
- **Element Removal**: Remove elements from the back or specific positions.
- **Memory Management**: Handles memory allocation and deallocation.
- **Safe Access**: Provides functions to check size and capacity before accessing elements.

## Usage

### Creating a New Vector

To create a new vector, use:

```c
vector_t* my_vector = new_vector();
```

### Inserting Elements

To insert an element at a specific position, use:

```c
vector_insert_(my_vector, position, &value);
```

### Adding Elements

To push an element to the back of the vector, use:

```c
vector_push_back_(my_vector, &value);
```

### Removing Elements

To pop an element from the back, use:

```c
vector_pop_back_(my_vector, &value);
```

### Accessing Vector Properties

To get the size and capacity of the vector, use:

```c
size_t size = vector_size_(my_vector);
size_t capacity = vector_capacity_(my_vector);
```

### Memory Management

To free all memory associated with the vector, use:

```c
vector_free(my_vector);
```

To clear the vector without freeing memory, use:

```c
vector_clear(my_vector);
```

### Resizing the Vector

To reserve additional capacity, use:

```c
vector_reserve_(my_vector, new_capacity);
```

To shrink the vector to fit its size, use:

```c
vector_shrink_to_fit_(my_vector);
```

## Example of usage

Here is a simple example of how to use the Vector Library:

```c
#include "vector.h"

int main() {
    vector_t* vec = new_vector();
    int value = 10;

    vector_push_back_(vec, &value);
    vector_insert_(vec, 0, &value);

    printf("Vector size: %zu\n", vector_size_(vec));

    vector_free(vec);
    return 0;
}
```
