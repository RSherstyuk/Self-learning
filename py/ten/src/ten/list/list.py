from __future__ import annotations
from typing import Optional, Any


class Node:
    def __init__(self, data: Any):
        self.data: Any = data
        self.next: Node | None = None


class LinkedList:
    head: Optional[Node]

    def __init__(self):
        self.head: Node | None = None

    def is_empty(self):
        return self.head is None

    def insert_at_beginning(self, data: Any) -> None:
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_end(self, data: Any):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        curr: Node = self.head

        while curr.next is not None:
            curr = curr.next

        curr.next = new_node

    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        print(" -> ".join(map(str, elements)))


def main():
    list = LinkedList()
    list.insert_at_beginning(12)
    list.insert_at_beginning(12)
    list.insert_at_beginning(12)
    list.insert_at_beginning(12)
    list.display()


main()
