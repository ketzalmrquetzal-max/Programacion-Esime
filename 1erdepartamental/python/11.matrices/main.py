"""
Programa: Matrices
Demuestra operaciones matriciales con operator overloading
"""

from core.matriz import Matriz

if __name__ == "__main__":
    m1 = Matriz(2, 2)
    m1.set(0, 0, 1)
    m1.set(0, 1, 2)
    m1.set(1, 0, 3)
    m1.set(1, 1, 4)

    print("Matriz original:")
    print(m1)

    print("\nMultiplicación escalar (x2):")
    print(m1 * 2)

    print("\nMultiplicación matricial:")
    print(m1 * m1)
