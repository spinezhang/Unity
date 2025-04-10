#include "unity_registry.h"

TEST_GROUP(TestGroup2);

TEST_SETUP(TestGroup2) { }

TEST_TEAR_DOWN(TestGroup2) { }

TEST(TestGroup2, testTrue) {
    TEST_ASSERT_EQUAL(1, 1);
}
 
TEST(TestGroup2, testFalse) {
    TEST_ASSERT_EQUAL(1, 0);
}

TEST_GROUP_RUNNER(TestGroup2)
{
    RUN_TEST_CASE(TestGroup2, testTrue);
    RUN_TEST_CASE(TestGroup2, testFalse);
}

REGISTER_TEST_GROUP(TestGroup2)
