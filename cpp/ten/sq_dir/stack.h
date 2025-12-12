#pragma once

#include <string>
#include <unordered_map>
#include <stack>


struct ListNode {
  int val;
  ListNode *next;

  ListNode(int val) : val(val), next(nullptr) {}
};

class Stack {
private:
  ListNode *topNode;
  int cap;

public:
  Stack() : topNode(nullptr), cap(0) {}

  ~Stack() {
    while (topNode != nullptr) {
      ListNode *tmp = topNode;
      topNode = topNode->next;
      delete tmp;
    }
  }

  void push(int val);
  void pop();
  void printStack() const;
  static bool isValid(std::string &s) {
    std::unordered_map<char, char> pair{
        {'(', ')'},
        {'{', '}'},
        {'[', ']'},
    };

    std::stack<char> st;

    for (char c : s) {
      if (pair.count(c)) {
        st.push(c);

      } else if (!st.empty() && pair[st.top()] == c) {
        st.pop();
      } else {
        return false;
      }
    }

    return true;
  }
};
