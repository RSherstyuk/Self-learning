#include "linked_list.h"
#include <gtest/gtest.h>

TEST(ListTest, test) {
  List ls;

  ls.push(12);
  ls.push(2);
  ls.push(123);
  ls.push(1244);

  ls.print();

  ls.remove_last();

  ls.print();

  ls.insert_at(2, 88);

  ls.print();

  ls.remove_at(2);

  ls.print();

  ls.pop_front();

  ls.print();
}