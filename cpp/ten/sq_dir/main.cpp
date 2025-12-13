#include "queue.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

  Queue q;

  q.push_back(12);
  q.push_back(1244);
  q.push_back(112);
  q.push_back(1);
  std::cout << q.peak() << std::endl;
  q.pop_front();
  std::cout << q.peak() << std::endl;
  q.pop_front();
  std::cout << q.peak() << std::endl;
  q.pop_front();
  std::cout << q.peak() << std::endl;
  q.pop_front();
  std::cout << q.peak() << std::endl;
}
