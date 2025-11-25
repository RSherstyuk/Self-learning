#include <iostream>

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

  ~List();

  void push(int val);

  void print();

  void delete_back();

  void insert_at(int index, int val);
};
