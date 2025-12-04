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

  void push(int val) {
    ListNode *newNode = new ListNode(val);

    newNode->next = topNode;

    topNode = newNode;

    cap++;
  }

  int pop() {
    int popedVal = topNode->val;

    ListNode *tmp = topNode;

    topNode = topNode->next;

    delete tmp;

    cap--;
    return popedVal;
  }
};
