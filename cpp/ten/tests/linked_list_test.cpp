#include "linked_list.h"
#include <gtest/gtest.h>

class ListTest : public ::testing::Test {
protected:
  List list;

  void SetUp() override {}

  void CheckListContent(const std::initializer_list<int> &expected_list) {
    ASSERT_EQ(list.size(), expected_list.size());
    int i = 0;
    for (int expected : expected_list) {
      ASSERT_EQ(list.get(i), expected) << "Missing index " << i;
      i++;
    }
  }
};

TEST_F(ListTest, InsertAt_AtTheEnd) {
  list.push(10);
  list.insert_at(1, 20);

  CheckListContent({10, 20});
}

TEST_F(ListTest, InsertAt_OutOfBoundsThrowsException) {
  list.push(10);

  ASSERT_THROW(list.insert_at(2, 5), std::out_of_range);
}

TEST_F(ListTest, PopFront_RemovesHeadAndDecrementsSize) {
  list.push_front(1);
  list.push_front(2);

  list.pop_front();

  ASSERT_EQ(list.size(), 1);
  CheckListContent({1});

  list.pop_front();
  ASSERT_EQ(list.size(), 0);
}

TEST_F(ListTest, PopFront_EmptyListDoesNothing) {
  list.pop_front();
  ASSERT_EQ(list.size(), 0);
}

TEST_F(ListTest, RemoveLast_FromSingleElementList) {
  list.push(10);
  list.remove_last();
  ASSERT_EQ(list.size(), 1);
}

TEST_F(ListTest, RemoveLast_EmptyListDoesNothing) {
  list.remove_last();
  ASSERT_EQ(list.size(), 0);
}