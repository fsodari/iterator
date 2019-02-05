#ifndef ITERATOR_H
#define ITERATOR_H

struct iterator_ops;
typedef struct iterator
{
    struct iterator_ops *ops;
} iterator;

struct iterator_ops
{
    void (*first)(iterator*);
    void (*next)(iterator*);
    int (*is_end)(iterator*);
    void (*current)(iterator*, void*);
};

void iterator_init(iterator *self);
void iterator_destroy(iterator *self);

static inline void iterator_first(iterator *self)
{
    if (self) {
        self->ops->first(self);
    }
}

static inline void iterator_next(iterator *self)
{
    if (self) {
        self->ops->next(self);
    }
}

static inline int iterator_is_end(iterator *self)
{
    if (self) {
        return self->ops->is_end(self);
    } else {
        return -1;
    }
}
static inline void iterator_current(iterator *self, void *node)
{
    if (self) {
        self->ops->current(self, node);
    }
}

#endif
