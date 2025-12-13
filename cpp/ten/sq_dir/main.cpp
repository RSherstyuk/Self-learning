#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

  Stack sq;

  string s = "abb*acd";

  std::cout << Stack::removeStarts(s);
}
