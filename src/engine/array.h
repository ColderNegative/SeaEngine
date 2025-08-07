#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "src/engine/types.h"

typedef struct {
    void *elements;
    u32 size;
    u32 capacity;
    size_t element_size;
} Array;

Array *array_create(u32 size, size_t element_size);
bool array_push(Array *array, const void *element);
void array_destroy(Array *array);
