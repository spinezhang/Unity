#include "unity_registry.h"

TEST_GROUP(TestGroup1);

TEST_SETUP(TestGroup1) { }

TEST_TEAR_DOWN(TestGroup1) { }

TEST(TestGroup1, testTrue) {
    TEST_ASSERT_EQUAL(1, 1);
}
 
TEST(TestGroup1, testFalse) {
    TEST_ASSERT_EQUAL(1, 0);
}

TEST_GROUP_RUNNER(TestGroup1)
{
    RUN_TEST_CASE(TestGroup1, testTrue);
    RUN_TEST_CASE(TestGroup1, testFalse);
}

REGISTER_TEST_GROUP(TestGroup1)
