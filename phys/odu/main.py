import numpy as np
import matplotlib.pyplot as plt

def euler_method(f, t0, y0, t_end, N):
    """
    Реализация метода Эйлера.
    
    Параметры:
    f      : функция f(t, y) (правая часть ОДУ)
    t0, y0 : начальные условия
    t_end  : конечное время
    N      : количество шагов
    """
    h = (t_end - t0) / N  # шаг сетки
    t = np.linspace(t0, t_end, N+1)  # массив времени
    y = np.zeros(N+1)  # массив для решений
    y[0] = y0  # начальное значение
    
    for i in range(N):
        y[i+1] = y[i] + h * f(t[i], y[i])
    
    return t, y

# Пример ОДУ: y' = y
def f(t, y):
    return y

# Параметры решения
t0, y0 = 0, 1
t_end = 1.0
N = 10

# Решение методом Эйлера
t, y_euler = euler_method(f, t0, y0, t_end, N)

# Точное решение для сравнения
y_exact = np.exp(t)

# Визуализация
plt.plot(t, y_euler, 'bo-', label='Метод Эйлера')
plt.plot(t, y_exact, 'r-', label='Точное решение')
plt.title(f"Метод Эйлера (N={N})")
plt.xlabel('t'); plt.ylabel('y')
plt.legend(); plt.grid(True)
plt.show()

# Оценка погрешности
error = np.abs(y_euler - y_exact)
print("Максимальная погрешность:", np.max(error))