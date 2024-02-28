from matrix.matrix import Vector


def linear_combination(u: list[Vector], coefs: list[float]) -> Vector:
    for i in range(len(u)):
        u[i] = u[i].scl(coefs[i])
    result = u[0]
    for i in range(1, len(u)):
        result = result.add(u[i])
    return result


def main():
    e = [Vector(1.0, 0.0, 0.0), Vector(0.0, 1.0, 0.0), Vector(0.0, 0.0, 1.0)]
    v = [Vector(1.0, 2.0, 3.0), Vector(0.0, 10.0, -100.0)]
    coef = [10.0, -2.0, 0.5]
    print(
        f"Linear combination of 2 vectors:\n{linear_combination(e, coef)}",
        end="\n\n",
    )
    print(
        f"Linear combination of 2 vectors:\n{linear_combination(v, coef)}",
        end="\n\n",
    )
    return


if __name__ == "__main__":
    main()
