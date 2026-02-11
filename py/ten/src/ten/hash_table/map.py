# hash collision view
import numpy as np
import matplotlib.pyplot as plt
from numpy.typing import NDArray


def der_ost(num: NDArray) -> NDArray:
    return num % 10


def create_plot() -> None:
    x = np.linspace(0, 50, 51)
    y = der_ost(x)
    plt.scatter(x, y)
    plt.show()


def main() -> None:
    create_plot()


if __name__ == "__main__":
    main()
