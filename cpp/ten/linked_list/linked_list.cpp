#include "linked_list.h"

void List::push(int val) {
  Node *new_node = new Node(val);

  new_node->next = head;

  head = new_node;
  count++;
}

List::~List() {
  Node *current = head;
  Node *next_node = nullptr;

  while (current != nullptr) {
    next_node = current->next;
    delete current;
    current = next_node;
  }
  head = nullptr;
  count = 0;
}

void List::print() {
  Node *current = head;
  std::cout << "List: ";
  while (current != nullptr) {
    std::cout << current->value << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

void List::remove_last() {
  if (head == nullptr) {
    std::cout << "Err" << "\n";
    return;
  }

  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }

  Node *current = head;
  Node *prev = nullptr;

  while (current->next != nullptr) {
    prev = current;
    current = current->next;
  }

  prev->next = nullptr;

  delete current;
}

void List::insert_at(int index, int val) {
  if (index < 0 || index > count) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    push(val);
    return;
  }

  Node *new_node = new Node(val);
  Node *current = head;

  for (int i = 0; i < index - 1; ++i) {
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
  count++;
}

void List::remove_at(int index) {
  if (index < 0 || index > count) {
    throw std::out_of_range("Nothih thindex");
  }

  if (index == 0) {
    remove_last();
    return;
  }

  Node *current = head;
  Node *prev = nullptr;

  while (current->next != nullptr) {
    prev = current;
    current = current->next;
  }

  prev->next = nullptr;
  delete current;
  count--;
}

void List::pop_front() {
  if (head == nullptr) {
    std::cout << "Error" << "\n";
    return;
  }

  Node *tmp = head;
  head = head->next;

  delete tmp;
  count--;
}