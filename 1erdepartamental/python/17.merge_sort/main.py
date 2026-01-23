"""
Programa: Merge Sort
Demuestra algoritmo de ordenamiento merge sort
"""
#Importe de las clases 
from core.ordenador import OrdenadorMerge
#Punto de entrada 
if __name__ == "__main__":
    numeros = [64, 34, 25, 12, 22, 11, 90]# Arreglo original de números

    print(f"Array original: {numeros}")

    ordenador = OrdenadorMerge()
    ordenador.ordenar(numeros)

    print(f"Array ordenado: {numeros}")
    print(f"Fusiones: {ordenador.fusiones}")
