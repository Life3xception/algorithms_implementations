#include "static_array.h"
#include "../../lib/unity.h"

static void test_static_array_create() 
{
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_create(5, 1));
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_static_array_create);
  
  // TO CONTINUE...

  return UNITY_END();
}
