"""
Programa: Burbuja
Demuestra algoritmo de ordenamiento burbuja con estadísticas
"""

from core.ordenador import OrdenadorBurbuja

if __name__ == "__main__":
    numeros = [64, 34, 25, 12, 22, 11, 90]

    print(f"Array original: {numeros}")

    ordenador = OrdenadorBurbuja()
    ordenador.ordenar(numeros)

    print(f"Array ordenado: {numeros}")
    print(f"Comparaciones: {ordenador.comparaciones}")
    print(f"Intercambios: {ordenador.intercambios}")
