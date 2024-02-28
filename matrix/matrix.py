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

    def __init__(self, *values):
        self.v = np.array(values, dtype=float)


class Matrix:
    def add(self, other) -> np.array:
        return Matrix(self.m + other.m)

    def sub(self, other) -> np.array:
        return Matrix(self.m - other.m)

    def scl(self, other) -> np.array:
        return Matrix(self.m * other)

    def __repr__(self) -> str:
        return f"{self.m}"

    def __init__(self, *values):
        self.m = np.array(values, dtype=float)
