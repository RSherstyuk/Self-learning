def Euler(n, h, x, y):
    for i in range(n):
        y += h * fun(x, y)
        x += h
    return x, y
def fun(x, y):
    return x**2 + 2 * x + y**2 


print(Euler(10, 0.01, 1, 1))