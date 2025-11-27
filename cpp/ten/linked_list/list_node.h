#include <initializer_list>
#include <vector>
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

  Node *deleteMid(Node *head) {
    if (!head->next || !head)
      return nullptr;

    Node *prev = nullptr;
    Node *fast = head;
    Node *slow = head;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (prev)
      prev->next = slow->next;

    delete slow;

    return head;
  }

  Node *reverseList(Node *head) {
    Node *curr = nullptr;
    Node *prev = head;

    while (curr != nullptr) {
      Node *tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return prev;
  }

  bool isPolList(Node *head) {
    std::vector<int> vec;

    while (head != nullptr) {
      vec.push_back(head->val);
      head = head->next;
    }

    int left = 0;
    int right = vec.size() - 1;

    while (left < right) {
      if (vec[left] > vec[right]) {
        return false;
      }

      left++;
      right++;
    }

    return true;
  }
};
