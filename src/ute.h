#ifndef UTE_H
#define UTE_H

/*==================[inclusions]============================================*/
#include "ute_test_id.h"
#include <string.h>

/*==================[external function declarations]========================*/
extern void Ute_InitResultArray(void);
extern void Ute_DumpResultArray(void);
extern void Ute_SetResult(uteTestId_t testId, int result);

/*==================[type definitions]======================================*/
typedef enum {
  UTE_RESULT_NOT_RUN = 0x0,
  UTE_RESULT_PASS    = 0x1,
  UTE_RESULT_FAIL    = 0x2,
  UTE_RESULT_MASK    = 0x3
} uteTestResult_t;

/*==================[macros]================================================*/
#define TEST_ASSERT(RESULT) Ute_SetResult(testId, RESULT)
#define TEST_ASSERT_EQUAL(EXPECTED, ACTUAL) Ute_SetResult(testId, (EXPECTED)==(ACTUAL))
#define TEST_ASSERT_EQUAL_MEMORY(EXPECTED, ACTUAL, LEN) Ute_SetResult(testId, memcmp((EXPECTED),(ACTUAL),(LEN)) == 0)

/* in this version of UTE, additional messages are ignored */
#define TEST_ASSERT_MESSAGE(RESULT, MSG) Ute_SetResult(testId, RESULT)
#define TEST_ASSERT_EQUAL_MESSAGE(EXPECTED, ACTUAL, MSG) Ute_SetResult(testId, (EXPECTED)==(ACTUAL))
#define TEST_ASSERT_EQUAL_MEMORY_MESSAGE(EXPECTED, ACTUAL, LEN, MSG) Ute_SetResult(testId, memcmp((EXPECTED),(ACTUAL),(LEN)) == 0)

#define TEST_GROUP(group)\
    int TEST_GROUP_##group = 0

#define TEST_SETUP(group) \
  static void TEST_##group##_SETUP(void)

#define TEST_TEAR_DOWN(group) \
  static void TEST_##group##_TEAR_DOWN(void)

#define TEST(group, name) \
    static void TEST_##group##_##name##_(uteTestId_t testId);\
    void TEST_##group##_##name##_run(void);\
    void TEST_##group##_##name##_run(void)\
    {\
        TEST_##group##_SETUP();\
        TEST_##group##_##name##_(TEST_ID_##group##_##name);\
        TEST_##group##_TEAR_DOWN();\
    }\
    static void TEST_##group##_##name##_(uteTestId_t testId)

#define DECLARE_TEST_CASE(group, name) \
    void TEST_##group##_##name##_run(void)

#define RUN_TEST_CASE(group, name) \
    TEST_##group##_##name##_run();

/* normally generated, lists all tests that pertains to test group */
#define TEST_GROUP_RUNNER(group)\
    static void TEST_##group##_GROUP_RUNNER(void)

/* normally generated, runs one test group */
#define RUN_TEST_GROUP(group)\
    TEST_##group##_GROUP_RUNNER(); 

#endif /* if !defined(UTE_H) */
