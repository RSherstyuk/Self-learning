#include "../include/SolutionTwoPointers.h"

void SolutionTwoPointers::customSwap(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

void SolutionTwoPointers::reverseString(std::string &s) {
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    customSwap(s[left], s[right]);
    left++;
    right--;
  }
}

bool SolutionTwoPointers::isPalindrome(std::string s) {
  std::string original_s = s;
  reverseString(s);
  return (s == original_s);
}

std::vector<int> SolutionTwoPointers::twoSum(std::vector<int> &arr, int n) {
  std::sort(arr.begin(), arr.end());

  int l = 0;
  int r = arr.size() - 1;

  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum < n) {
      l++;
    } else if (sum > n) {
      r--;
    } else {
      return {arr[l], arr[r]};
    }
  }

  return {-1, -1};
}

std::vector<std::vector<int>> SolutionTwoPointers::threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  int n = nums.size();

  // 1. Сортировка массива
  std::sort(nums.begin(), nums.end());

  // 2. Основной цикл для первого элемента 'a'
  for (int i = 0; i < n - 2; ++i) {

    // Пропуск дубликатов для 'a'
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    // Оптимизация: если 'a' > 0, сумма не может быть 0
    if (nums[i] > 0) {
      break;
    }

    // 3. Установка двух указателей и цели
    int j = i + 1;            // Левый указатель (b)
    int k = n - 1;            // Правый указатель (c)
    int target = 0 - nums[i]; // Целевая сумма для b + c

    // 4. Поиск пары (b, c)
    while (j < k) {
      int current_sum = nums[j] + nums[k];

      if (current_sum == target) {
        // Найдена тройка
        result.push_back({nums[i], nums[j], nums[k]});

        // Пропуск дубликатов для 'b' и 'c'
        while (j < k && nums[j] == nums[j + 1]) {
          j++;
        }
        while (j < k && nums[k] == nums[k - 1]) {
          k--;
        }

        // Переход к следующей уникальной паре
        j++;
        k--;
      } else if (current_sum < target) {
        // Нужно увеличить сумму, сдвигаем левый указатель
        j++;
      } else { // current_sum > target
        // Нужно уменьшить сумму, сдвигаем правый указатель
        k--;
      }
    }
  }

  return result;
}
