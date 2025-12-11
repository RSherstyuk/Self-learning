#include "stack.h"
#include <iostream>
#include <unordered_map>

void Stack::push(int val) {
  ListNode *newNode = new ListNode(val);

  newNode->next = topNode;

  topNode = newNode;

  cap++;
}

void Stack::pop() {
if (topNode == nullptr) {
        std::cerr << "Ошибка: Стек пуст, pop невозможен." << std::endl;
        return; 
    }
    
    ListNode *tmp = topNode;
    
    topNode = topNode->next;     
    delete tmp;
    
    cap--;}

void Stack::printStack() const {
  ListNode *current = topNode;

  std::cout << "Содержимое стека (сверху вниз):" << std::endl;

  if (current == nullptr) {
    std::cout << "Стек пуст." << std::endl;
    return;
  }

  while (current != nullptr) {
    std::cout << "| " << current->val << " |";

    if (current == topNode) {
      std::cout << " <== TOP";
    }
    std::cout << std::endl;

    current = current->next;

    if (current != nullptr) {
      std::cout << "|---| " << std::endl;
    }
  }

  std::cout << "-------" << std::endl; // Основание стека
}

bool Stack::isVald(std::string s) {

  std::unordered_map<char, char> pair {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'},
  };

  for (char c : s) {
  }
}
