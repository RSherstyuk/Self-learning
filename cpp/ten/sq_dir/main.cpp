#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

  Stack sq;

  string s = "abbacd";

  std::cout << Stack::removeDuplicatesFast(s);
}
