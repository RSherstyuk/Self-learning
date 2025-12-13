#include "queue.h"
#include <iostream>

void Queue::push_back(const int val) {
  ListNode *new_node = new ListNode(val);

  if (front == nullptr) {
    front = new_node;
    rear = new_node;
  } else {
    rear->next = new_node;
    rear = new_node;
  }

  size++;
}

void Queue::pop_front() {
  if (front == nullptr) {
    return;
  }

  ListNode *tmp = front;
  front = front->next;

  if (front == nullptr) {
    rear = nullptr;
  }

  delete tmp;
  size--;
}

int Queue::peak() const {
  if (front == nullptr) {
    throw std::out_of_range("queue is empty");
  } else {
    return front->val;
  }
}
