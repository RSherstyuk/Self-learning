from typing import Any, Optional


class Node:
    def __init__(self, key, val) -> None:
        self.key = key
        self.val = val
        self.next: Node | None = None


class LinkedList:
    head: Optional[Node]

    def __init__(self) -> None:
        self.head: Node | None = None

    def get(self, key) -> int | None:
        cur = self.head

        while cur:
            if cur.key == key:
                return cur.val
            cur = cur.next

        return -1

    def add(self, key, val) -> None:
        if not self.head:
            self.head = Node(key, val)

        cur = self.head
        while cur != None:
            if cur.key == key:
                cur.val = cur.val
            if cur.next is None:
                break
            cur = cur.next

    def remove(self, key) -> None:
        if self.head == None:
            return

        if self.head.key == key:
            self.head = self.head.next
            return

        cur = self.head
        while cur != None:
            if cur.next is not None and cur.next.key == key:
                cur.next = cur.next.next
            cur = cur.next



class HashTable:
    def __init__(self, cap=991) -> None:
        self.cap = cap
        self.buckets = [LinkedList() for _ in range(self.cap)]

    def hash_f(self, key) -> int:
        return key % self.cap

    def put(self, key: Any, val: Any) -> None:
        if key is None:
            raise ValueError("key can not be None")

        n = self.hash_f(key)
        self.buckets[n].add(key, val)

    def get(self, key):
        n = self.hash_f(key)
        return self.buckets[n].get(key)

    def delete(self, key) -> None:
        n = self.hash_f(key)
        self.buckets[n].remove(key)
