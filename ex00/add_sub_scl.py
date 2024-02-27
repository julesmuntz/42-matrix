import numpy as np


class Vector:
    def add(self, other) -> np.array:
        return Vector(*(self.v + other.v))

    def sub(self, other) -> np.array:
        return Vector(*(self.v - other.v))

    def scl(self, other) -> np.array:
        return Vector(*(self.v * other))

    def __repr__(self) -> str:
        return f"{self.v}"

    def __init__(self, v1, v2):
        self.v = np.array([v1, v2], dtype=float)


class Matrix:
    def add(self, other) -> np.array:
        return Matrix(self.m + other.m)

    def sub(self, other) -> np.array:
        return Matrix(self.m - other.m)

    def scl(self, other) -> np.array:
        return Matrix(self.m * other)

    def __repr__(self) -> str:
        return f"{self.m}"

    def __init__(self, m):
        self.m = np.array(m, dtype=float)


def main():
    u = Vector(2.0, 3.0)
    v = Vector(5.0, 7.0)
    print(f"Addition of 2 vectors:\n{u.add(v)}", end="\n\n")

    u = Vector(2.0, 3.0)
    v = Vector(5.0, 7.0)
    print(f"Subtraction of 2 vectors:\n{u.sub(v)}", end="\n\n")

    u = Vector(2.0, 3.0)
    print(f"Scaling of a vector:\n{u.scl(2.0)}", end="\n\n")

    u = Matrix([[1.0, 2.0], [3.0, 4.0]])
    v = Matrix([[7.0, 4.0], [-2.0, 2.0]])
    print(f"Addition of 2 matrices:\n{u.add(v)}", end="\n\n")

    u = Matrix([[1.0, 2.0], [3.0, 4.0]])
    v = Matrix([[7.0, 4.0], [-2.0, 2.0]])
    print(f"Subtraction of 2 matrices:\n{u.sub(v)}", end="\n\n")

    u = Matrix([[1.0, 2.0], [3.0, 4.0]])
    print(f"Scaling of a matrix:\n{u.scl(2.0)}", end="\n\n")
    return


if __name__ == "__main__":
    main()
