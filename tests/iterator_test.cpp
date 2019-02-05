#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include <iostream>

extern "C"
{
#include "iterator/iterator.h"
}

void test_first(iterator *self);
void test_next(iterator *self);
int test_is_end(iterator *self);
void test_current(iterator *self, void *node);

TEST_GROUP(ITERATOR)
{
    iterator_ops ops = {
        .first = test_first,
        .next = test_next,
        .is_end = test_is_end,
        .current = test_current
    };

    iterator dut;

    void setup()
    {
        iterator_init(&dut);
        dut.ops = &ops;
    }

    void teardown()
    {

    }
};

TEST(ITERATOR, opstest)
{
    int node;

    iterator_first(&dut);
    iterator_next(&dut);
    iterator_is_end(&dut);
    iterator_current(&dut, &node);
}

void test_first(iterator *self)
{
    CHECK(self);
}

void test_next(iterator *self)
{
    CHECK(self);
}

int test_is_end(iterator *self)
{
    CHECK(self);
    return 1;
}

void test_current(iterator *self, void *node)
{
    CHECK(self);
    CHECK(node);
}
