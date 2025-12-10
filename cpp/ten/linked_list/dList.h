struct Node {
  Node *next;
  Node *prev;
  int data;

  Node(const int data) : data(data), prev(nullptr), next(nullptr) {}
};

class dList {
private:
  Node *tail;
  Node *head;
  int size;

public:
  dList() : head(nullptr), tail(nullptr), size(0) {}

  ~dList() {
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }

  void push_front(int val);
  void push_back(int val);

  void pop_front();
  void pop_back();
};
