#include "dList.h"

void dList::push_back(int val) {
  Node *new_node = new Node(val);
  if (tail == nullptr) {
    head = new_node;
    tail = new_node;
  } else {
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
  }
  size++;
}

void dList::push_front(int val) {
  Node *new_node = new Node(val);
  if (head == nullptr) {
    head = new_node;
    tail = new_node;
  } else {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
  size++;
}

void dList::pop_back() {
  if (tail == nullptr) {
    return;
  }
  Node *tmp = tail;
  tail = tail->prev;

  if (tail != nullptr) {
    tail->next = nullptr;
  } else {
    head = nullptr;
  }

  delete tmp;
  size--;
}

void dList::pop_front() {
  if (head == nullptr) {
    return;
  }

  Node *tmp = head;
  head = head->next;

  if (head != nullptr) {
    head->prev = nullptr;
  }
  else {
    tail = nullptr;
  }

  size--;
}
