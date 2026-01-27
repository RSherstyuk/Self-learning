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


# Deep ml tasks
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


def calculate_covariance_matrix(features: list[list[float]]) -> list[list[float]]:
    n = len(features)
    d = len(features[0])

    means = [sum(f) / d for f in features]

    cov = [[0.0 for _ in range(d)] for _ in range(d)]

    for i in range(n):
        for j in range(n):
            s = sum((features[i][k] - means[i]) * (features[j][k] - means[j]) for k in range(d))
            cov[i][j] = s / (d - 1) if d > 1 else 0.0

    return cov

def mat_dot_vec(a: list[list[float]]) -> list[float]:
    return []

def test():
    m = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]
    print(np.cov(m))
    print(calculate_covariance_matrix(m))


test()
