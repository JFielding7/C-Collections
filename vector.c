#include "vector.h"
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_CAPACITY 16

struct Vector new_vec() {
    return (struct Vector) {0, DEFAULT_CAPACITY, malloc(DEFAULT_CAPACITY * sizeof (void*))};
}

/**
 * \brief Grows a vector by a factor
 * \param vector The vector to grow
 * \param by The factor to grow by
 */
void grow(struct Vector *vector, const size_t by) {
    vector->capacity += by;
    realloc(vector->values, vector->capacity);
}

/**
 * \brief Appends the value to the end of the vector
 * \param vector The vector to add to
 * \param value The value to add
 */
void add(struct Vector *vector, void *value) {
    if (vector->length == vector->capacity) {
        grow(vector, vector->capacity);
    }

    vector->values[vector->length++] = value;
}

void extend(struct Vector *dest, void **src, const size_t size) {

    grow(dest, size);

    for (size_t i = 0; i < size; i++) {
        add(dest, src[i]);
    }
}

void extendv(struct Vector *dest, struct Vector *src) {
    grow(dest, src->length);

    for (size_t i = 0; i < src->length; i++) {
        add(dest, src->values[i]);
    }
}

void remove(struct Vector *vector) {
    if (vector->length) vector->length--;
}

void *get(const struct Vector *vector, const size_t index) {
    return vector->values[index];
}

void set(const struct Vector *vector, void *value, const size_t index) {
    vector->values[index] = value;
}

void insert(struct Vector *vector, void *value, const size_t index) {
    if (vector->length == vector->capacity) {
        grow(vector, vector->capacity);
    }
    for (size_t i = vector->length; i > index; i--) {
        vector->values[i] = vector->values[i - 1];
    }
    vector->values[index] = value;
    vector->length++;
}

void delete(struct Vector *vector, const size_t index) {
    for (size_t i = index; i < vector->length - 1; i++) {
        vector->values[i] = vector->values[i + 1];
    }
    vector->length--;
}

struct Vector slice(struct Vector *vector, size_t from_index, size_t to_index) {
    struct Vector sliced = new_vec();
    for (size_t i = from_index; i < to_index; i++) {
        add(&sliced, vector->values[i]);
    }
    return sliced;
}

bool is_empty(struct Vector *vector) {
    return vector->length == 0;
}

void clear(struct Vector *vector) {
    vector->length = 0;
}

void trim_to_size(struct Vector *vector) {
    vector->capacity = vector->length;
    realloc(vector->values, vector->length);
}
