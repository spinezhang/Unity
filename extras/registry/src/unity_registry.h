#ifndef TEST_REGISTRY_H
#define TEST_REGISTRY_H

#include <stdio.h>
#include "unity_fixture.h"

#ifdef __cplusplus
extern "C" {
#endif

// Max number of test groups
#define MAX_TEST_GROUPS 32

typedef void (*TestGroupFunction)(void);

void registerTestGroup(TestGroupFunction func);

#define REGISTER_TEST_GROUP(name) \
    __attribute__((constructor)) static void register_##name##_tests(void) { \
        void TEST_##name##_GROUP_RUNNER(void); \
        registerTestGroup(TEST_##name##_GROUP_RUNNER); \
    }

// API to run all registered test groups
int runUnityTests(int argc, const char *argv[]);

#define RUN_UNITY_TESTS() \
    runUnityTests(0, NULL)

#ifdef __cplusplus
}
#endif
#endif // TEST_REGISTRY_H
