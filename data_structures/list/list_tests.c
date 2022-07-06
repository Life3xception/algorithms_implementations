#include "list.h"
#include "../../lib/unity.h"

static void test_list_create() 
{
  List *list = list_create(1,0);
  TEST_ASSERT_NOT_NULL(list);
  list_free(list);
}

static void test_list_is_ordered() 
{
  List *list = list_create(1,0);
  TEST_ASSERT_TRUE(list_is_ordered(list));
  list_free(list);
}

static void test_list_is_circular() 
{
  List *list = list_create(0,1);
  TEST_ASSERT_TRUE(list_is_circular(list));
  list_free(list);
}

static void test_list_is_empty_true() 
{
  List *list = list_create(0,1);
  TEST_ASSERT_TRUE(list_is_empty(list));
  list_free(list);
}

static void test_list_is_empty_false() 
{
  List *list = list_create(0,1);
  int x = 10;
  list_insert_head(list, &x);
  TEST_ASSERT_FALSE(list_is_empty(list));
  list_free(list);
}

static void test_list_insert_head_one_element()
{
  List *list = list_create(0,1);
  int x = 10;
  TEST_ASSERT_EQUAL_PTR(&x, list_insert_head(list, &x));
  list_free(list); 
}

static void test_list_insert_head_ordered_list()
{
  List *list = list_create(1,0);
  int x = 10;
  TEST_ASSERT_EQUAL_PTR(NULL, list_insert_head(list, &x));
  list_free(list); 
}

static void test_list_insert_ordered_descending_order()
{
  // head insertions
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3;
  TEST_ASSERT_EQUAL_PTR(&a3, list_insert_ordered(list, &a3));
  TEST_ASSERT_EQUAL_PTR(&a2, list_insert_ordered(list, &a2));
  TEST_ASSERT_EQUAL_PTR(&a1, list_insert_ordered(list, &a1));
  list_free(list);
}

static void test_list_insert_ordered_ascending_order()
{
  // tail insertions
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3;
  TEST_ASSERT_EQUAL_PTR(&a1, list_insert_ordered(list, &a1));
  TEST_ASSERT_EQUAL_PTR(&a2, list_insert_ordered(list, &a2));
  TEST_ASSERT_EQUAL_PTR(&a3, list_insert_ordered(list, &a3));
  list_free(list);
}

static void test_list_insert_ordered_middle_elements()
{
  // middle insertions
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5;
  TEST_ASSERT_EQUAL_PTR(&a1, list_insert_ordered(list, &a1));
  TEST_ASSERT_EQUAL_PTR(&a5, list_insert_ordered(list, &a5));
  TEST_ASSERT_EQUAL_PTR(&a3, list_insert_ordered(list, &a3));
  TEST_ASSERT_EQUAL_PTR(&a2, list_insert_ordered(list, &a2));
  TEST_ASSERT_EQUAL_PTR(&a4, list_insert_ordered(list, &a4));
  list_free(list);
}

static void test_list_free()
{
  List *list1 = list_create(0,0);
  List *list2 = list_create(0,0);
  int a1 = 1, a2 = 2, a3 = 3;
  list_insert_head(list1, &a1);
  list_insert_head(list1, &a2);
  list_insert_head(list2, &a1);
  list_insert_head(list2, &a2);
  list_insert_head(list2, &a3);
  TEST_ASSERT_EQUAL_PTR(list_free(list1), list_free(list2));
}

static void test_list_search_present()
{
  List *list = list_create(0,0);
  int a1 = 1, a2 = 2, a3 = 3;
  list_insert_head(list, &a1);
  list_insert_head(list, &a2);
  list_insert_head(list, &a3);
  TEST_ASSERT_EQUAL_PTR(&a2, list_search(list, &a2));
  list_free(list);
}

static void test_list_search_not_present()
{
  List *list = list_create(0,0);
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  list_insert_head(list, &a1);
  list_insert_head(list, &a2);
  list_insert_head(list, &a3);
  TEST_ASSERT_EQUAL_PTR(NULL, list_search(list, &a4));
  list_free(list);
}

static void test_list_print()
{
  int length = 100;
  int A[length];
  List *list = list_create(0,0);

  for(int i = 0; i < length; i++) {
    A[i] = i;
    list_insert_head(list, &A[i]);
  }

  list_print(list);
  list_free(list);
}

static void test_list_delete_head_of_list()
{
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3;
  list_insert_ordered(list, &a1);
  list_insert_ordered(list, &a2);
  list_insert_ordered(list, &a3);
  TEST_ASSERT_EQUAL_PTR(&a1, list_delete(list, &a1));
  list_free(list);
}

static void test_list_delete_tail_of_list()
{
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3;
  list_insert_ordered(list, &a1);
  list_insert_ordered(list, &a2);
  list_insert_ordered(list, &a3);
  TEST_ASSERT_EQUAL_PTR(&a3, list_delete(list, &a3));
  list_free(list);
}

static void test_list_delete_element_middle_of_list()
{
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3;
  list_insert_ordered(list, &a1);
  list_insert_ordered(list, &a2);
  list_insert_ordered(list, &a3);
  TEST_ASSERT_EQUAL_PTR(&a2, list_delete(list, &a2));
  list_free(list);
}

static void test_list_delete_element_not_present()
{
  List *list = list_create(1,0);
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  list_insert_ordered(list, &a1);
  list_insert_ordered(list, &a2);
  list_insert_ordered(list, &a3);
  TEST_ASSERT_EQUAL_PTR(NULL, list_delete(list, &a4));
  list_free(list);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_list_create);
  RUN_TEST(test_list_is_ordered);
  RUN_TEST(test_list_is_circular);
  RUN_TEST(test_list_is_empty_true);
  RUN_TEST(test_list_is_empty_false);
  RUN_TEST(test_list_insert_head_one_element);
  RUN_TEST(test_list_insert_head_ordered_list);
  RUN_TEST(test_list_insert_ordered_descending_order);
  RUN_TEST(test_list_insert_ordered_ascending_order);
  RUN_TEST(test_list_insert_ordered_middle_elements);
  RUN_TEST(test_list_free);
  RUN_TEST(test_list_search_present);
  RUN_TEST(test_list_search_not_present);
  RUN_TEST(test_list_print);
  RUN_TEST(test_list_delete_head_of_list);
  RUN_TEST(test_list_delete_tail_of_list);
  RUN_TEST(test_list_delete_element_middle_of_list);
  RUN_TEST(test_list_delete_element_not_present);
  return UNITY_END();
}