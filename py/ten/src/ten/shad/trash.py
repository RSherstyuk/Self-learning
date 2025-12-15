def spiral(n: int) -> list[list[int]]:
    if n <= 0:

        return []

    ls = [[0] * n for _ in range(n)]

    top, bottom = 0, n - 1
    left, right = 0, n - 1
    current_num = 1

    while current_num <= n * n:
        for c in range(left, right + 1):
            ls[top][c] = current_num
            current_num += 1
        top += 1
        if top > bottom:
            break

        for r in range(top, bottom + 1):
            ls[r][right] = current_num
            current_num += 1
        right -= 1
        if left > right:
            break

        for c in range(right, left - 1, -1):
            ls[bottom][c] = current_num
            current_num += 1
        bottom -= 1
        if top > bottom:
            break

        for r in range(bottom, top - 1, -1):
            ls[r][left] = current_num
            current_num += 1
        left += 1
        if left > right:
            break

    return ls

