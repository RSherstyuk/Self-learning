import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from scipy.integrate import solve_ivp
from const import *


class KeplerProblem:
    def __init__(self, a, e, total_time=10):
        self.a = a * AU
        self.e = e
        self.total_time = total_time * 365.25 * 24 * 3600
        self.r0 = self.a * (1 - e)  
        self.v0 = np.sqrt(G * M * (1 + e) / (self.a * (1 - e)))  
        self.y0 = np.array([self.r0, 0, 0, self.v0])
        
    def equations_of_motion(self, t, y):
        x, y_pos, vx, vy = y
        r = np.sqrt(x**2 + y_pos**2)

        dxdt = vx
        dydt = vy
        dvxdt = -G * M * x / r**3
        dvydt = -G * M * y_pos / r**3
        
        return np.array([dxdt, dydt, dvxdt, dvydt])
    
    def solve(self, method='RK45'):
        t_span = (0, self.total_time)
        solution = solve_ivp(self.equations_of_motion, t_span, self.y0, 
                            method=method, rtol=1e-8, atol=1e-10)
        return solution
    
    def plot_solution(self, solution):
        x = solution.y[0] / AU  
        y = solution.y[1] / AU
        
        plt.figure(figsize=(10, 10))
        plt.plot(x, y, 'b', label='Орбита')
        plt.plot(0, 0, 'yo', markersize=15, label='Центральное тело')
        plt.plot(x[0], y[0], 'ro', label='Начальное положение')
        
        plt.xlabel('x (AU)')
        plt.ylabel('y (AU)')
        plt.title(f'Задача Кеплера: a={self.a/AU} AU, e={self.e}')
        plt.axis('equal')
        plt.legend()
        plt.grid()
        plt.show()
    

    
    