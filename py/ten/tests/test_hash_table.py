from ten.hash_table.my_hash_map import HashTable
import pytest


class TestHashTable:
    def test_put_none_key(self):
        ht = HashTable()
        with pytest.raises(ValueError):
            ht.put(None, 21)

    def test_put_op(self):
        ht = HashTable()
        ht.put(12, 21)
        assert ht.get(12) == 21

    def test_delete_op(self):
        ht = HashTable()
        ht.put(12, 21)
        ht.delete(12)
        assert ht.get(12) == -1
