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

TEST_F(ListTest, InitializerListConstructor) {
  List l({1, 2, 3});
  ASSERT_EQ(l.size(), 3);
  ASSERT_EQ(l.get(0), 1);
  ASSERT_EQ(l.get(1), 2);
  ASSERT_EQ(l.get(2), 3);
}

TEST_F(ListTest, InitializerListConstructor_Empty) {
  List l({});
  ASSERT_EQ(l.size(), 0);
}

TEST_F(ListTest, PushAddsElementsCorrectly) {
  list.push(1);
  list.push(2);
  list.push(3);
  CheckListContent({1, 2, 3});
}

TEST_F(ListTest, PushToEmptyList) {
  list.push(5);
  CheckListContent({5});
}

TEST_F(ListTest, PushFrontAddsElementToFront) {
  list.push_front(10);
  list.push_front(20);
  CheckListContent({20, 10});
}

TEST_F(ListTest, PushFrontToEmptyList) {
  list.push_front(5);
  CheckListContent({5});
}

TEST_F(ListTest, RemoveLast_FromMultiElementList) {
  list.push(1);
  list.push(2);
  list.push(3);
  list.remove_last();
  CheckListContent({1, 2});
  list.remove_last();
  CheckListContent({1});
}

TEST_F(ListTest, InsertAt_AtTheBeginning) {
  list.push(10);
  list.push(20);
  list.insert_at(0, 5);
  CheckListContent({5, 10, 20});
}

TEST_F(ListTest, InsertAt_InTheMiddle) {
  list.push(10);
  list.push(30);
  list.insert_at(1, 20);
  CheckListContent({10, 20, 30});
}

TEST_F(ListTest, RemoveAt_AtTheBeginning) {
  list.push(1);
  list.push(2);
  list.push(3);
  list.remove_at(0);
  CheckListContent({2, 3});
}

TEST_F(ListTest, RemoveAt_InTheMiddle) {
  list.push(1);
  list.push(2);
  list.push(3);
  list.push(4);
  list.remove_at(1);
  CheckListContent({1, 3, 4});
}

TEST_F(ListTest, RemoveAt_AtTheEnd) {
  list.push(1);
  list.push(2);
  list.push(3);
  list.remove_at(2);
  CheckListContent({1, 2});
}

TEST_F(ListTest, RemoveAt_SingleElementList) {
  list.push(1);
  list.remove_at(0);
  CheckListContent({});
}

TEST_F(ListTest, RemoveAt_OutOfBoundsThrowsException) {
  list.push(10);
  list.push(20);
  ASSERT_THROW(list.remove_at(-1), std::out_of_range);
  ASSERT_THROW(list.remove_at(2), std::out_of_range);
}

TEST_F(ListTest, Get_OutOfBoundsThrowsException) {
  list.push(10);
  list.push(20);
  ASSERT_THROW(list.get(-1), std::out_of_range);
  ASSERT_THROW(list.get(2), std::out_of_range);
}

TEST_F(ListTest, Get_EmptyListThrowsException) {
  ASSERT_THROW(list.get(0), std::out_of_range);
}

TEST_F(ListTest, SquareUp_AppliesSquareToListElements) {
  list.push(1);
  list.push(2);
  list.push(3);
  list.suqareUp();
  CheckListContent({1, 4, 9});
}

TEST_F(ListTest, SquareUp_EmptyListDoesNothing) {
  list.suqareUp();
  CheckListContent({});
}

TEST_F(ListTest, SquareUp_NegativeNumbers) {
  list.push(-1);
  list.push(-2);
  list.suqareUp();
  CheckListContent({1, 4});
}

TEST_F(ListTest, Add_TwoListsOfSameSize) {
  list.push(1);
  list.push(2);
  list.push(3);

  List other_list({10, 20, 30});

  List result_list = list.add(other_list);
  
  ASSERT_EQ(result_list.size(), 3);
  ASSERT_EQ(result_list.get(0), 11);
  ASSERT_EQ(result_list.get(1), 22);
  ASSERT_EQ(result_list.get(2), 33);
}

TEST_F(ListTest, Add_FirstListShorter) {
  list.push(1);
  list.push(2);

  List other_list({10, 20, 30});

  List result_list = list.add(other_list);
  
  ASSERT_EQ(result_list.size(), 2);
  ASSERT_EQ(result_list.get(0), 11);
  ASSERT_EQ(result_list.get(1), 22);
}

TEST_F(ListTest, Add_SecondListShorter) {
  list.push(1);
  list.push(2);
  list.push(3);

  List other_list({10, 20});

  List result_list = list.add(other_list);
  
  ASSERT_EQ(result_list.size(), 2);
  ASSERT_EQ(result_list.get(0), 11);
  ASSERT_EQ(result_list.get(1), 22);
}

TEST_F(ListTest, Add_OneEmptyList) {
  List empty_list;
  
  list.push(1);
  list.push(2);

  List result_list_empty_other = list.add(empty_list);
  ASSERT_EQ(result_list_empty_other.size(), 0);

  List result_list_empty_this = empty_list.add(list);
  ASSERT_EQ(result_list_empty_this.size(), 0);
}

TEST_F(ListTest, Add_BothEmptyLists) {
  List empty_list1;
  List empty_list2;

  List result_list = empty_list1.add(empty_list2);
  ASSERT_EQ(result_list.size(), 0);
}
