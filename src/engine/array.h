#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "src/engine/util.h"
#include "types.h"

typedef struct {
    void *elements;
    u32 size;
    u32 capacity;
    size_t element_size;
} Array;

Array *array_create(u32 size, size_t element_size) {
    if (size <= 0) {ERROR_RETURN(NULL, "Invalid array size");}
    if (element_size <= 0) {ERROR_RETURN(NULL, "Invalid array element size");}

    u32 capacity = 2 * size;
    void *elements = calloc(capacity, element_size);

    Array *array = malloc(sizeof(*array));
    *array = (Array) {
        .elements = elements,
        .size = 0,
        .capacity = capacity,
        .element_size = element_size,
    };

    return array;
}

bool array_push(Array *array, const void *element) {
    if (array->size >= array->capacity) {
        u32 new_capacity = array->capacity * 2;

        array->elements = realloc(array->elements, array->element_size * new_capacity);
        if (array->elements == NULL) {
            ERROR_RETURN(false, "failed to reallocate array");
        }

        array->capacity = new_capacity;
    }

    // Casting to char pointer required to get correct byte position as a char is of byte size
    void *target = (char*)array->elements + (array->element_size * array->size);
    memcpy(target, element, array->element_size);
    array->size++;

    return true;
}

void array_destroy(Array *array) {
    free(array->elements);
    free(array);
}
