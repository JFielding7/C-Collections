#ifndef VECTOR_IMPL__$
#define VECTOR_IMPL__$
#include <stddef.h>
#include <stdbool.h>

struct Vector {
    size_t length;
    size_t capacity;
    void **values;
};

extern struct Vector new_vec();

extern void grow(struct Vector *vector, size_t by);

extern void add(struct Vector *vector, void *value);

extern void extend(struct Vector *dest, void **src, size_t size);

extern void extendv(struct Vector *dest, struct Vector *src);

extern void remove(struct Vector *vector);

extern void remove(struct Vector *vector);

extern void *get(const struct Vector *vector, size_t index);

extern void set(const struct Vector *vector, void *value, size_t index);

extern void insert(struct Vector *vector, void *value, size_t index);

extern void delete(struct Vector *vector, size_t index);

extern struct Vector slice(struct Vector *vector, size_t from_index, size_t to_index);

extern bool is_empty(struct Vector *vector);

extern void clear(struct Vector *vector);

extern void trim_to_size(struct Vector *vector);

#endif