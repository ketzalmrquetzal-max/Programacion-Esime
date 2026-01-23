"""
Programa: Merge Indirecto
Demuestra merge sort sin modificar el arreglo original
"""
#Clase Principal
from core.ordenador import OrdenadorIndirectoMerge
def main ():
    numeros = [64, 34, 25, 12, 22, 11, 90]#Lista de numeros a ordenar

    ordenador = OrdenadorIndirectoMerge(numeros)

    print(f"Original: {ordenador.mostrar_original()}")
    ordenador.ordenar()
    print(f"Ordenado (mediante índices): {ordenador.mostrar_ordenado()}")
    print(f"Original (sin cambios): {ordenador.mostrar_original()}")

#Punto de Entrada

if __name__ == "__main__":
    main ()