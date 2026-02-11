from ten.hash_table.my_hash_map import LinkedList


class TestTwoPointTasks:
    def test_get_op(self):
        ls = LinkedList()
        ls.add(12, 21)
        assert ls.get(12) == 21

    def test_remove_op(self):
        ls = LinkedList()
        ls.add(12, 21)
        ls.remove(12)
        assert ls.get(12) == None

    def test_add_op(self):
        ls = LinkedList()
        ls.add(12, 21)
        assert ls.get(12) == 21
