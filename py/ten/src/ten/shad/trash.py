import numpy as np


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
