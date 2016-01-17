/*==================[inclusions]============================================*/
#include "ute.h"
/*
#include "ute_test_id.h"
supplies the enum composed of test IDs:

typedef enum {
  TEST_ID_group1_name1,
  TEST_ID_group1_name2,
  TEST_ID_group2_name1,
  TEST_ID_group2_name2,
  ...
  TEST_ID_COUNT
} uteTestId_t;

*/

/*==================[macros]================================================*/
/* BITS_PER_RESULT must divide 8 */
#define BITS_PER_RESULT 2

#define TEST_ID_TO_INDEX(ID)                 (((ID)*BITS_PER_RESULT)/8)
#define TEST_ID_TO_SUBINDEX(ID)              (((ID)*BITS_PER_RESULT)%8)
#define TEST_ID_RESULT_TO_MASK(ID, RESULT)   ((RESULT) << TEST_ID_TO_SUBINDEX(ID))

/*==================[external data]=========================================*/
unsigned char ute_resultArray[TEST_ID_TO_INDEX(TEST_ID_COUNT-1)+1];

/*==================[external function definitions]=========================*/
void Ute_InitResultArray()
{
  unsigned int result_slot;
  unsigned int index;
  for(index = 0; index < sizeof(ute_resultArray); index++) 
  {
    ute_resultArray[index] = 0;
    for(result_slot = 0; result_slot < 8/BITS_PER_RESULT; result_slot++)
    {
      ute_resultArray[index] |=  TEST_ID_RESULT_TO_MASK(result_slot, UTE_RESULT_NOT_RUN);
    }
  } 
}

void Ute_SetResult(uteTestId_t testId, int result)
{
  int index = TEST_ID_TO_INDEX(testId);

  if(result)
  {
    ute_resultArray[index] |= TEST_ID_RESULT_TO_MASK(testId, UTE_RESULT_PASS);
  }
  else
  {
    ute_resultArray[index] |= TEST_ID_RESULT_TO_MASK(testId, UTE_RESULT_FAIL);
  }
}

#if(UTE_PRINT_RESULT_ON == 1)
#include <stdio.h>
void Ute_DumpResultArray()
{
  int i;
  printf("\n");
  for(i = 0; i < sizeof(ute_resultArray); i++)
  {
    printf("%02x", ute_resultArray[i]);
  }
  printf("\n");
}
#else
void Ute_DumpResultArray()
{
}
#endif
