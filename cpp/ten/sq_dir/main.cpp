#include "stack.h"
#include <iostream>
#include <unordered_map>

int main() {
  Stack *st = new Stack();
  st->push(12);
  st->push(123);
  st->printStack();

  std::unordered_map<char, char> pair{
      {'(', ')'},
      {'{', '}'},
      {'[', ']'},
  };

  std::unordered_map<int, char> map{
      {1, ')'},
      {2, '}'},
      {3, ']'},
  };
  std::cout << map[1];

  try {
    std::cout << map[1];
  } catch (int codeErr) {

  }
  

  return 0;
}
