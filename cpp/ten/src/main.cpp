#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> nums1, int m, vector<int> nums2, int n) {
  int p1 = 0;

  int p2 = 0;

  vector<int> res;

  while (p1 < m && p2 < n) {
    if (nums1[p1] < nums2[p2]) {
      res.push_back(nums1[p1]);
      p1++;
    } else {
      res.push_back(nums2[p2]);
      p2++;
    }
  }

  for (int k = p1; k < m; ++k) {
    res.push_back(nums1[k]);
  }

  for (int k = p2; k < n; ++k) {

    res.push_back(nums2[k]);
  }

  for (int i = 0; i < res.size(); ++i) {
    nums1[i] = res[i];
  }
}

int main() {
  std::vector<int> vv{1, 2, 3, 4, 3, 2, 1};
  std::vector<int> v{1, 23, 4, 5, 6, 2, 1};

  auto add_vectors = [&]() -> std::vector<int> {
    if (v.size() != vv.size()) {
      return {};
    }
    std::vector<int> res(v.size());

    for (size_t i = 0; i < v.size(); ++i) {
      res[i] = v[i] + vv[i];
    }

    return res;
  };

  auto print_vec = [](const std::vector<int> &vec) {
    std::cout << "{";
    for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << vec[i];
      if (i < vec.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  };

  add_vectors();
}
