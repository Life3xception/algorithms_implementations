#include "static_array.h"
#include "../../lib/unity.h"

static void test_static_array_create_wrong_is_ordered() 
{
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_create(5, 1));
}

static void test_static_array_create_wrong_capacity() 
{
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_create(1, 0));
}

static void test_static_array_create() 
{
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_NOT_NULL(static_array);
  static_array_free(static_array);
}

static void test_static_array_is_ordered()
{
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_TRUE(static_array_is_ordered(static_array));
  static_array_free(static_array);
}

static void test_static_array_is_empty()
{
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_TRUE(static_array_is_empty(static_array));
  static_array_free(static_array);
}

static void test_static_array_size_empty()
{
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_TRUE(static_array_size(static_array)==0);
  static_array_free(static_array);
}

static void test_static_array_size_not_empty()
{
  StaticArray *static_array = static_array_create(1,5);
  int x = 4;
  static_array_insert(static_array, &x);
  TEST_ASSERT_TRUE(static_array_size(static_array)==1);
  static_array_free(static_array);
}

static void test_static_array_free()
{
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_NULL(static_array_free(static_array));
}

static void test_static_array_insert_one_element()
{
  int a1 = 1;
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_insert(static_array, &a1));
  TEST_ASSERT_TRUE(static_array_size(static_array)==1);
  static_array_free(static_array);
}

static void test_static_array_insert_one_element_not_ordered()
{
  int a1 = 1;
  StaticArray *static_array = static_array_create(0,5);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_insert(static_array, &a1));
  TEST_ASSERT_TRUE(static_array_size(static_array)==1);
  static_array_free(static_array);
}

static void test_static_array_insert_more_elements()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_insert(static_array, &a1));
  TEST_ASSERT_EQUAL_PTR(&a2, static_array_insert(static_array, &a2));
  TEST_ASSERT_EQUAL_PTR(&a3, static_array_insert(static_array, &a3));
  TEST_ASSERT_EQUAL_PTR(&a4, static_array_insert(static_array, &a4));
  TEST_ASSERT_TRUE(static_array_size(static_array)==4);
  static_array_free(static_array);
}

static void test_static_array_insert_array_full()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,3);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_insert(static_array, &a1));
  TEST_ASSERT_EQUAL_PTR(&a2, static_array_insert(static_array, &a2));
  TEST_ASSERT_EQUAL_PTR(&a3, static_array_insert(static_array, &a3));
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_insert(static_array, &a4));
  TEST_ASSERT_TRUE(static_array_size(static_array)==3);
  static_array_free(static_array);
}

static void test_static_array_remove()
{
  int a1 = 1;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_remove(static_array, &a1));
  TEST_ASSERT_TRUE(static_array_size(static_array)==0);
  static_array_free(static_array);
}

static void test_static_array_search_not_ordered_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a2, static_array_search(static_array, &a2));
  static_array_free(static_array);
}

static void test_static_array_search_not_ordered_not_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_search(static_array, &a4));
  static_array_free(static_array);
}

static void test_static_array_search_ordered_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a2, static_array_search(static_array, &a2));
  static_array_free(static_array);
}

static void test_static_array_search_ordered_not_present()
{
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_search(static_array, &a4));
  static_array_free(static_array);
}

static void test_static_array_max_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a4, static_array_max(static_array));
  static_array_free(static_array);
}

static void test_static_array_max_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a4, static_array_max(static_array));
  static_array_free(static_array);
}

static void test_static_array_min_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_min(static_array));
  static_array_free(static_array);
}

static void test_static_array_min_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_min(static_array));
  static_array_free(static_array);
}

static void test_static_array_predecessor_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_predecessor(static_array, &a2));
  static_array_free(static_array);
}

static void test_static_array_predecessor_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a1, static_array_predecessor(static_array, &a2));
  static_array_free(static_array);
}

static void test_static_array_predecessor_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_predecessor(static_array, &a1));
  static_array_free(static_array);
}

static void test_static_array_predecessor_not_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_predecessor(static_array, &a1));
  static_array_free(static_array);
}

static void test_static_array_successor_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a3, static_array_successor(static_array, &a2));
  static_array_free(static_array);
}

static void test_static_array_successor_not_ordered() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(&a3, static_array_successor(static_array, &a2));
  static_array_free(static_array);
}

static void test_static_array_successor_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(1,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_successor(static_array, &a4));
  static_array_free(static_array);
}

static void test_static_array_successor_not_ordered_not_present() {
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  StaticArray *static_array = static_array_create(0,5);
  static_array_insert(static_array, &a1);
  static_array_insert(static_array, &a2);
  static_array_insert(static_array, &a3);
  static_array_insert(static_array, &a4);
  TEST_ASSERT_EQUAL_PTR(NULL, static_array_successor(static_array, &a4));
  static_array_free(static_array);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_static_array_create_wrong_is_ordered);
  RUN_TEST(test_static_array_create_wrong_capacity);
  RUN_TEST(test_static_array_create);
  RUN_TEST(test_static_array_is_ordered);
  RUN_TEST(test_static_array_is_empty);
  RUN_TEST(test_static_array_size_empty);
  RUN_TEST(test_static_array_size_not_empty);
  RUN_TEST(test_static_array_free);
  RUN_TEST(test_static_array_insert_one_element);
  RUN_TEST(test_static_array_insert_one_element_not_ordered);
  RUN_TEST(test_static_array_insert_more_elements);
  RUN_TEST(test_static_array_insert_array_full);
  RUN_TEST(test_static_array_remove);
  RUN_TEST(test_static_array_search_not_ordered_present);
  RUN_TEST(test_static_array_search_not_ordered_not_present);
  RUN_TEST(test_static_array_search_ordered_present);
  RUN_TEST(test_static_array_search_ordered_not_present);
  RUN_TEST(test_static_array_max_ordered);
  RUN_TEST(test_static_array_max_not_ordered);
  RUN_TEST(test_static_array_min_ordered);
  RUN_TEST(test_static_array_min_not_ordered);
  RUN_TEST(test_static_array_predecessor_ordered);
  RUN_TEST(test_static_array_predecessor_not_ordered);
  RUN_TEST(test_static_array_predecessor_ordered_not_present);
  RUN_TEST(test_static_array_predecessor_not_ordered_not_present);
  RUN_TEST(test_static_array_successor_ordered);
  RUN_TEST(test_static_array_successor_not_ordered);
  RUN_TEST(test_static_array_successor_ordered_not_present);
  RUN_TEST(test_static_array_successor_not_ordered_not_present);
  return UNITY_END();
}
