#include "stack.h"

void Stack::push(int val) {
  ListNode *newNode = new ListNode(val);

  newNode->next = topNode;

  newNode = topNode;

  cap++;
}

void Stack::pop() {
  int popedVal = topNode->val;

  ListNode *tmp = topNode;

  topNode->next = topNode;

  delete tmp;
  cap--;
}
