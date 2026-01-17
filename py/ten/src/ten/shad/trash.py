import numpy as np


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


def find_der(func: list) -> list:
    res = [0] * len(func)

    for i in range(len(func)):
        res[i] = func[i] * i

    return res


def product_rule_derivative(f_coeffs: list, g_coeffs: list) -> list:
    der_f = find_der(f_coeffs)
    der_g = find_der(g_coeffs)

    res = np.polymul(der_f, g_coeffs) + np.polymul(f_coeffs, der_g)

    return list(res)


def test():
    print(product_rule_derivative([2], [3, 4]))


test()
