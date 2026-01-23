"""
Programa: Burbuja Indirecto
Demuestra ordenamiento sin modificar el arreglo original
"""

from core.ordenador import OrdenadorIndirectoBurbuja

if __name__ == "__main__":
    numeros = [64, 34, 25, 12, 22, 11, 90]

    ordenador = OrdenadorIndirectoBurbuja(numeros)

    print(f"Original: {ordenador.mostrar_original()}")
    ordenador.ordenar()
    print(f"Ordenado (mediante índices): {ordenador.mostrar_ordenado()}")
    print(f"Original (sin cambios): {ordenador.mostrar_original()}")
