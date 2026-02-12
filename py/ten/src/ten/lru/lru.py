from __future__ import annotations
from typing import Optional, Dict



class Node:
    def __init__(self, key: int = 0, val: int = 0) -> None:
        self.key: int = key
        self.val: int = val
        self.prev: Optional[Node] = None
        self.next: Optional[Node] = None


class LRUCache:

    def __init__(self, cap: int) -> None:
        self.cap: int = cap
        self.data: Dict[int, Node] = {}

        self.head: Node = Node()
        self.tail: Node = Node()

        self.head.next = self.tail
        self.tail.prev = self.head

    def _add_to_head(self, node: Node) -> None:
        first = self.head.next
        assert first is not None

        node.prev = self.head
        node.next = first
        first.prev = node
        self.head.next = node

    def _remove(self, node: Node) -> None:
        prev = node.prev
        next = node.next
        assert prev is not None and next is not None

        prev.next = next

        next.prev = prev

    def get(self, key: int) -> int:
        if key not in self.data:
            return -1


        node = self.data[key]

        self._remove(node)

        self._add_to_head(node)
        return node.val

    def put(self, key: int, val: int) -> None:
        if key in self.data:
            node = self.data[key]

            node.val = val
            self._remove(node)
            self._add_to_head(node)
            return

        if len(self.data) == self.cap:

            lru = self.tail.prev
            assert lru is not None and lru is not self.head
            self._remove(lru)
            del self.data[lru.key]

        node = Node(key, val)

        self._add_to_head(node)
        self.data[key] = node
