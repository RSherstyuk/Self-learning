#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode *prev;

  ListNode(int val) : val(val) {}
};

class Queue {
private:
  ListNode *front;
  ListNode *rear;
  int size;

public:
  Queue() : front(nullptr), rear(nullptr), size(0) {}

  ~Queue() {
    while (front != nullptr) {
      ListNode *tmp = front;
      front = front->next;
      delete tmp;
      size--;
    }
  }

  void push_back(const int val);
  void pop_front();
  int peak() const;
};
