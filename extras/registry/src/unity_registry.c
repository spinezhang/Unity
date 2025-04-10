#include "unity_registry.h"
#include "unity_fixture.h"

static TestGroupFunction testGroupRunners[MAX_TEST_GROUPS];
static uint8_t testGroupCount = 0;

void registerTestGroup(TestGroupFunction func)
{
    if (testGroupCount < MAX_TEST_GROUPS) {
        testGroupRunners[testGroupCount++] = func;
    }
}

static void runAllTests(void)
{
    for (uint8_t i = 0; i < testGroupCount; ++i)
    {
        testGroupRunners[i]();
    }
}

int runUnityTests(int argc, const char *argv[]) {
    return UnityMain(argc, argv, runAllTests);
}