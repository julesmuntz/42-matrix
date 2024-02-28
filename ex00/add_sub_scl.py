from matrix.matrix import Matrix, Vector


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
