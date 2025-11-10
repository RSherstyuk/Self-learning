#include "Date.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(DateGetMontTeset, initialization) {
  Date d(12,2,2026);

  int day = d.GetMonth();
  std::cout << day << "\n";

  EXPECT_EQ(day, 2);
}

TEST(DateGetDayTest, initialization) {
  Date d(12,2,2026);

  int day = d.GetDay();
  std::cout << day << "\n";

  EXPECT_EQ(day, 12);
}

TEST(DateGetYearTest, initialization) {
  Date d(12,2,2026);

  int day = d.GetYear();
  std::cout << day << "\n";

  EXPECT_EQ(day, 2026);
}

