# hash collision view
import numpy as np
import matplotlib.pyplot as plt
from numpy.typing import NDArray


def der_ost(num: NDArray, bucket_num: int) -> NDArray:
    return num % bucket_num


def create_plot() -> None:
    x1 = np.linspace(0, 9, 10)
    y1 = der_ost(x1, 2)
    y2 = der_ost(x1, 10)
    plt.scatter(x1, y1, label="2 bucket_num", color="red")
    plt.scatter(x1, y2, label="10 bucket_num", color="green")
    plt.legend()
    plt.show()


def main() -> None:
    create_plot()


if __name__ == "__main__":
    main()
