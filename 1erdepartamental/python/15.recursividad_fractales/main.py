"""
Programa: Recursividad Fractales
Demuestra generación recursiva de fractales
"""

from core.fractales import FractalesRecursivos

if __name__ == "__main__":
    fractales = FractalesRecursivos()

    fractales.sierpinski(1, 8)
    print()

    print("Conjunto de Cantor (nivel 1):")
    fractales.cantor(1, 27)
