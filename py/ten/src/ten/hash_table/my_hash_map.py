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

        return None

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
        cur = self.head
        prev = None

        while cur:
            if cur.key == key:
                if prev is None:
                    self.head = cur.next
                else:
                    prev.next = cur.next
                return

            prev = cur
            cur = cur.next


class HashTable:
    def __init__(self, cap=10) -> None:
        self.cap = cap
        self.buckets = [LinkedList() for _ in range(self.cap)]

    def hash_f(self):
        pass

    def put(self, key: Any, val: Any) -> None:
        if key is None:
            raise ValueError("key can not be None")
        pass

    def get(self, key) -> Any:
        pass

    def delete(self, key) -> None:
        pass
