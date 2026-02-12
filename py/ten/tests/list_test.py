from ten.hash_table.my_hash_map import LinkedList


class TestLinkedList:
    def test_get_op(self):
        ls = LinkedList()
        ls.add(12, 21)
        assert ls.get(12) == 21

    def test_remove_op(self):
        ls = LinkedList()
        ls.add(12, 21)
        ls.remove(12)
        print(ls.get(12))
        assert ls.get(12) == -1

    def test_add_op(self):
        ls = LinkedList()
        ls.add(12, 21)
        assert ls.get(12) == 21
