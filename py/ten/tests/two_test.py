from ten.two_point.two_point import *


class TestTwoPointTasks:
    def test_two_point(self):
        assert two_point([2, 7, 11, 15], 9) == [2, 7]

    def test_reverse_string(self):
        s = "gfdsa"
        reverse_string(s)
        assert s == "gfdsa"

    def test_is_poll(self):
        assert isPoll("asddsa") == True

    def test_three_sum(self):
        assert three_sum([-1, 0, 1, 2, -1, 4]) == [[-1, -1, 2], [-1, 0, 1]]

    def test_sorted_squares(self):
        assert sorted_squares([-4, -1, 0, 3, 10]) == [0, 1, 9, 16, 100]

    def test_max_area(self):
        assert max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
