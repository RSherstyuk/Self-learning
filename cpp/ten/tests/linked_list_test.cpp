#include <gtest/gtest.h>
#include "linked_list.h"

TEST(ListTest, test) {
  List ls;

  ls.push(12);
  ls.push(2);
  ls.push(123);
  ls.push(1244);

  ls.print();

  ls.delete_back();

  ls.print();

  ls.insert_at(2,88);

  ls.print();

}