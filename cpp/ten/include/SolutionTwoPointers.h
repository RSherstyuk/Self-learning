#ifndef SOLUTIONTWOPOINTERS_H
#define SOLUTIONTWOPOINTERS_H

#include <vector>
#include <string>

class SolutionTwoPointers {
private:
  void customSwap(char &a, char &b);

public:
  void reverseString(std::string &s);

  bool isPalindrome(std::string &s);

  std::vector<int> twoSum(std::vector<int> &arr, int n);
  
  std::vector<int> sortedSquares(std::vector<int> &nums);

  virtual std::vector<std::vector<int>> threeSum(std::vector<int> &nums); 

  std::vector<std::vector<int>> fSum(std::vector<int> &nums, int target);

  int maxArea(std::vector<int> &nums);

  int removeDuplicates(std::vector<int> &nums); //26

  void moveZeroes(std::vector<int> &nums);

  bool isSubseq(std::string &s, std::string &t);
};

#endif
