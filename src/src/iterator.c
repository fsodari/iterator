#include "iterator/iterator.h"
#include <stdlib.h>

static void iterator_ops_first(iterator *self)
{
    (void)self;
}

static void iterator_ops_next(iterator *self)
{
    (void)self;
}

static int iterator_ops_is_end(iterator *self)
{
    (void)self;
    return 0;
}

static void iterator_ops_current(iterator *self, void *node)
{
    (void)self;
    (void)node;
}

static struct iterator_ops ops = {
        .first = iterator_ops_first,
        .next = iterator_ops_next,
        .is_end = iterator_ops_is_end,
        .current = iterator_ops_current
};

void iterator_init(iterator *self)
{
    if (self) {
        self->ops = &ops;
    }
}

void iterator_destroy(iterator *self)
{
    free(self);
}
