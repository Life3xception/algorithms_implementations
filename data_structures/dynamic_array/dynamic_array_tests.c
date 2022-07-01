#include "dynamic_array.h"
#include "../../lib/unity.h"

static void test_dynamic_array_create_wrong_is_ordered() 
{
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_create(5, 1));
}

static void test_dynamic_array_create_wrong_capacity() 
{
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_create(1, 0));
}

static void test_dynamic_array_create() 
{
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_NOT_NULL(dynamic_array);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_is_ordered()
{
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_TRUE(dynamic_array_is_ordered(dynamic_array));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_is_empty()
{
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_TRUE(dynamic_array_is_empty(dynamic_array));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_size_empty()
{
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==0);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_size_not_empty()
{
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  int x = 4;
  dynamic_array_insert(dynamic_array, &x);
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==1);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_free()
{
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_NULL(dynamic_array_free(dynamic_array));
}

static void test_dynamic_array_insert_one_element()
{
  int a1 = 1;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_insert(dynamic_array, &a1));
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==1);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_insert_one_element_not_ordered()
{
  int a1 = 1;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_insert(dynamic_array, &a1));
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==1);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_insert_more_elements()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_insert(dynamic_array, &a1));
  TEST_ASSERT_EQUAL_PTR(&a2, dynamic_array_insert(dynamic_array, &a2));
  TEST_ASSERT_EQUAL_PTR(&a3, dynamic_array_insert(dynamic_array, &a3));
  TEST_ASSERT_EQUAL_PTR(&a4, dynamic_array_insert(dynamic_array, &a4));
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==4);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_insert_array_full()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,3);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_insert(dynamic_array, &a1));
  TEST_ASSERT_EQUAL_PTR(&a2, dynamic_array_insert(dynamic_array, &a2));
  TEST_ASSERT_EQUAL_PTR(&a3, dynamic_array_insert(dynamic_array, &a3));
  TEST_ASSERT_EQUAL_PTR(&a4, dynamic_array_insert(dynamic_array, &a4));
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==4);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_remove_one_element()
{
  int a1 = 1;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_remove(dynamic_array, &a1));
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==0);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_remove_more_elements()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_remove(dynamic_array, &a1));
  TEST_ASSERT_EQUAL_PTR(&a2, dynamic_array_remove(dynamic_array, &a2));
  TEST_ASSERT_EQUAL_PTR(&a3, dynamic_array_remove(dynamic_array, &a3));
  TEST_ASSERT_EQUAL_PTR(&a4, dynamic_array_remove(dynamic_array, &a4));
  TEST_ASSERT_TRUE(dynamic_array_size(dynamic_array)==0);
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_search_not_ordered_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a2, dynamic_array_search(dynamic_array, &a2));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_search_not_ordered_not_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_search(dynamic_array, &a4));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_search_ordered_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a2, dynamic_array_search(dynamic_array, &a2));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_search_ordered_not_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_search(dynamic_array, &a4));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_max_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a4, dynamic_array_max(dynamic_array));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_max_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a4, dynamic_array_max(dynamic_array));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_min_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_min(dynamic_array));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_min_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_min(dynamic_array));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_predecessor_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_predecessor(dynamic_array, &a2));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_predecessor_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, dynamic_array_predecessor(dynamic_array, &a2));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_predecessor_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_predecessor(dynamic_array, &a1));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_predecessor_not_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_predecessor(dynamic_array, &a1));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_successor_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a3, dynamic_array_successor(dynamic_array, &a2));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_successor_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a3, dynamic_array_successor(dynamic_array, &a2));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_successor_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(1,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_successor(dynamic_array, &a4));
  dynamic_array_free(dynamic_array);
}

static void test_dynamic_array_successor_not_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  DynamicArray *dynamic_array = dynamic_array_create(0,5);
  dynamic_array_insert(dynamic_array, &a1);
  dynamic_array_insert(dynamic_array, &a2);
  dynamic_array_insert(dynamic_array, &a3);
  dynamic_array_insert(dynamic_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, dynamic_array_successor(dynamic_array, &a4));
  dynamic_array_free(dynamic_array);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_dynamic_array_create_wrong_is_ordered);
  RUN_TEST(test_dynamic_array_create_wrong_capacity);
  RUN_TEST(test_dynamic_array_create);
  RUN_TEST(test_dynamic_array_is_ordered);
  RUN_TEST(test_dynamic_array_is_empty);
  RUN_TEST(test_dynamic_array_size_empty);
  RUN_TEST(test_dynamic_array_size_not_empty);
  RUN_TEST(test_dynamic_array_free);
  RUN_TEST(test_dynamic_array_insert_one_element);
  RUN_TEST(test_dynamic_array_insert_one_element_not_ordered);
  RUN_TEST(test_dynamic_array_insert_more_elements);
  RUN_TEST(test_dynamic_array_insert_array_full);
  RUN_TEST(test_dynamic_array_remove_one_element);
  RUN_TEST(test_dynamic_array_remove_more_elements);
  RUN_TEST(test_dynamic_array_search_not_ordered_present);
  RUN_TEST(test_dynamic_array_search_not_ordered_not_present);
  RUN_TEST(test_dynamic_array_search_ordered_present);
  RUN_TEST(test_dynamic_array_search_ordered_not_present);
  RUN_TEST(test_dynamic_array_max_ordered);
  RUN_TEST(test_dynamic_array_max_not_ordered);
  RUN_TEST(test_dynamic_array_min_ordered);
  RUN_TEST(test_dynamic_array_min_not_ordered);
  RUN_TEST(test_dynamic_array_predecessor_ordered);
  RUN_TEST(test_dynamic_array_predecessor_not_ordered);
  RUN_TEST(test_dynamic_array_predecessor_ordered_not_present);
  RUN_TEST(test_dynamic_array_predecessor_not_ordered_not_present);
  RUN_TEST(test_dynamic_array_successor_ordered);
  RUN_TEST(test_dynamic_array_successor_not_ordered);
  RUN_TEST(test_dynamic_array_successor_ordered_not_present);
  RUN_TEST(test_dynamic_array_successor_not_ordered_not_present);
  return UNITY_END();
}
