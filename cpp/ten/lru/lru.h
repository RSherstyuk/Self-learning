#include <unordered_map>

struct Node {
  int value;
  Node *next;
  Node *prev;
  int key;

  Node(int k, int val) : key(k), value(val), next(nullptr) {}
};

class lruCache {
private:
  int cap;
  std::unordered_map<int, Node *> cacheMap;

  Node *head;
  Node *tail;

  void addNode(Node *node) {
    node->prev = head;
    node->next = head->next;

    head->next->prev = node;
    head->next = node;
  }

  void removeNode(Node *node) {
    Node *prevNode = node->prev;
    Node *nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  void moveToHead(Node *node) {
    removeNode(node);
    addNode(node);
  }

  Node *popTail() {
    Node *res = tail->prev;
    removeNode(res);
    return res;
  }

public:
  lruCache(int cap) : cap(cap) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    head->prev = head;
  }

  ~lruCache() {
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }

  int get(int key) {
    if (cacheMap.find(key) == cacheMap.end()) {
      return -1; 
    }

    Node *node = cacheMap[key];
    moveToHead(node);

    return node->value;
  }

  void put(int key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
      Node *node = cacheMap[key];
      node->value = value;
      moveToHead(node);
    } else {
      Node *newNode = new Node(key, value);
      cacheMap[key] = newNode;
      addNode(newNode);

      if (cacheMap.size() > cap) {
        Node *lru = popTail();

        cacheMap.erase(lru->key);

        delete lru;
      }
    }
  }
};
