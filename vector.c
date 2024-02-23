#include <stddef.h>
#include <stdlib.h>

struct Vector {
    size_t length;
    size_t capacity;
    void **values;
};

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


