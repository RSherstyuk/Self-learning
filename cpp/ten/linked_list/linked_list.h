#pragma once

#include <initializer_list>

class Node {
public:
  Node *next;
  int value;

  Node(int val) : next(nullptr), value(val) {}
};

class List {
private:
  Node *head;
  int count;

public:
  List() : head(nullptr), count(0) {}

  List(std::initializer_list<int> init_list);

  ~List();

  void push(int val);

  void print() const;

  void push_front(int val);

  void remove_last();

  void insert_at(int index, int val);

  void remove_at(int index);

  void pop_front();

  int get(int index);

  void suqareUp();

  List add(const List &other) const;

  int size() const { return count; }

};
