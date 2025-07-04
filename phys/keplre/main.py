from kepler import KeplerProblem

def main():
    eq = KeplerProblem(a=1.0, e=0.0167, total_time=1)

    sol = eq.solve()
    eq.plot_solution(sol)

if __name__ == "__main__":
    main() 