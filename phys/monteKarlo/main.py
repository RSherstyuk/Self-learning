import random

def estimate_pi(num_points):
    points_inside = 0
    for _ in range(num_points):
        x = random.uniform(-1, 1)  # Случайная координата x от -1 до 1
        y = random.uniform(-1, 1)  # Случайная координата y от -1 до 1
        distance = x**2 + y**2     # Квадрат расстояния до центра (0,0)
        if distance <= 1:           # Если точка внутри круга (радиус 1)
            points_inside += 1
    pi_estimate = 4 * points_inside / num_points
    return pi_estimate

# Пример использования:
print(estimate_pi(1000000))  # Напечатает оценку π, например 3.1412