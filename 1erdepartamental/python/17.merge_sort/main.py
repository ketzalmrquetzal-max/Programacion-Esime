"""
Programa: Merge Sort
Demuestra algoritmo de ordenamiento merge sort
"""

from core.ordenador import OrdenadorMerge

if __name__ == "__main__":
    numeros = [64, 34, 25, 12, 22, 11, 90]

    print(f"Array original: {numeros}")

    ordenador = OrdenadorMerge()
    ordenador.ordenar(numeros)

    print(f"Array ordenado: {numeros}")
    print(f"Fusiones: {ordenador.fusiones}")
