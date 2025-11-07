#ifndef SOLUTIONTWOPOINTERS_H
#define SOLUTIONTWOPOINTERS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SolutionTwoPointers {
private:
  void customSwap(char &a, char &b);

public:
  void reverseString(std::string &s);

  bool isPalindrome(std::string s);

  std::vector<int> twoSum(std::vector<int> arr, int n);

  std::vector<std::vector<int>> threeSum(std::vector<int> arr); 
};

#endif
