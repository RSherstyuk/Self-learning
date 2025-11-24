#include <gtest/gtest.h>
#include <algo.h>

TEST(TestFindUniqEl, testUniq) {
  Algo sol;

  std::vector<int> v{1, 2, 3, 3, 2, 1, 4};

  int result = sol.fineUnPairEl(v);
  double expected = 4;

  ASSERT_EQ(result, expected);
}
