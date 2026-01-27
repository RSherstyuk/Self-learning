import copy

class mat:
    def __init__(self, mat: list[list[float]]) -> None:
        self.mat = mat

    def get_rank(self) -> int:
        m = copy.deepcopy(self.mat)
        rows = len(m)
        cols = len(m[0])

        rank = cols

        for row in range(rank):
            if m[row][row] != 0:
                for col in range(rows):
                    if col != row:
                        factor = m[col][row] / m[row][row]
                        for i in range(rank):
                            m[col][i] -= factor * m[row][i]
            else:
                reduce = True
                for i in range(row + 1, rows):
                    if m[i][row] != 0:
                        m[row], m[i] = m[i], m[row]
                        reduce = False
                        break
                if reduce:
                    rank -= 1
                    for i in range(rows):
                        m[i][row] = m[i][rank]
                row -= 1

        return rank

    def __repr__(self) -> str:
       return self.__str__()

    def __str__(self) -> str:
        return f'{self.mat}'

def main():
    m = mat([[1, 2], [2, 4]])
    repr(m.get_rank())
    print(m)


if __name__ == "__main__":
    main()
