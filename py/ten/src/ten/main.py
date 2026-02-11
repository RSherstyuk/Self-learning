from typing import Any
import numpy as np


def exper(n: int):
    ls = [[0] * n for _ in range(n)]

    for i in range(0, n):
        for j in range(0, n):
            print(ls[i][j], end=" ")
        print()


def get_rank(matrix: list[list[Any]]):
    m = [row[:] for row in matrix]

    rows = len(m)
    cols = len(m[0])
    rank = 0
    selected_rows = [False] * rows

    for i in range(cols):
        pivot = -1
        for j in range(rows):
            if not selected_rows[j] and abs(m[j][i]) > 0:
                pivot = j
                break

        if pivot != -1:
            rank += 1
            selected_rows[pivot] = True
            for j in range(rows):
                if j != pivot:
                    factor = m[j][i] / m[pivot][i]
                    for k in range(i, cols):
                        m[j][k] -= factor * m[pivot][k]
    return rank


def get_matrix_rank(matrix):
    m = [row[:] for row in matrix]

    rows = len(m)
    if rows == 0:
        return 0
    cols = len(m[0])

    rank = 0
    EPSILON = 1e-10

    for col in range(cols):
        if rank == rows:
            break

        pivot_row = -1
        for i in range(rank, rows):
            if abs(m[i][col]) > EPSILON:
                pivot_row = i
                break

        if pivot_row == -1:
            continue

        m[rank], m[pivot_row] = m[pivot_row], m[rank]

        for i in range(rank + 1, rows):
            if abs(m[i][col]) > EPSILON:
                factor = m[i][col] / m[rank][col]
                for j in range(col, cols):
                    m[i][j] -= factor * m[rank][j]

        rank += 1

    return rank


def missing_number(nums: list[int]) -> int:
    mis = len(nums)

    for i in range(len(nums)):
        mis ^= i ^ nums[i]

    return mis


def main():
    mat = [[1, 2, 4], [2, 4, 1], [2, 3, 5]]
    print(np.linalg.matrix_rank(mat))
    print(get_rank(mat))


if __name__ == "__main__":
    main()
