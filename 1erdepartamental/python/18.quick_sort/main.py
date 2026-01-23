"""
Programa: Quick Sort
Demuestra algoritmo de ordenamiento quick sort
"""

from core.ordenador import OrdenadorQuick

if __name__ == "__main__":
    numeros = [64, 34, 25, 12, 22, 11, 90]

    print(f"Array original: {numeros}")

    ordenador = OrdenadorQuick()
    ordenador.ordenar(numeros)

    print(f"Array ordenado: {numeros}")
    print(f"Particiones: {ordenador.particiones}")
