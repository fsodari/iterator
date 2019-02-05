#include "iterator/iterator.h"
#include <stdio.h>

void it_first(iterator *self);
void it_next(iterator *self);
int it_is_end(iterator *self);
void it_current(iterator *self, void *node);

int main(int argc, char **argv)
{
    struct iterator_ops ops = {
            .first = it_first,
            .next = it_next,
            .is_end = it_is_end,
            .current = it_current
    };

    iterator obj;
    iterator_init(&obj);
    obj.ops = &ops;

    printf("Project Name Main Exe!\n");

    return 0;
}

void it_first(iterator *self)
{
    (void)self;
}

void it_next(iterator *self)
{
    (void)self;
}

int it_is_end(iterator *self)
{
    (void)self;
}

void it_current(iterator *self, void *node)
{
    (void)self;
    (void)node;
}
