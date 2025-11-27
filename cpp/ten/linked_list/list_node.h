#include <initializer_list>
#include <iostream>

struct Node {
  Node *next;
  int val;

  Node(int val) : val(val), next(nullptr) {}
};

struct ListNode {
  Node *head;

  ListNode() : head(nullptr) {}

  void push(int val) {
    Node *new_node = new Node(val);

    if (head == nullptr) {
      head = new_node;
      return;
    }
    
    Node *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }

    curr->next = new_node;
  }

  ListNode(std::initializer_list<int> init_list) : head(nullptr) {
    for (const int &val : init_list) {
      this->push(val);
    }
  }

  Node *findMid(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
