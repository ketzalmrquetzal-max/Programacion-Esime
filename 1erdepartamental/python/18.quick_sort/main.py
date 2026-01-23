"""
Programa: Quick Sort
Demuestra algoritmo de ordenamiento quick sort
"""
#Clase principal
from core.ordenador import OrdenadorQuick

#Funcion Principal
def main ():
    numeros = [64, 34, 25, 12, 22, 11, 90] #Lista de numeros a acomodar

    print(f"Array original: {numeros}")

    ordenador = OrdenadorQuick()
    ordenador.ordenar(numeros)

    print(f"Array ordenado: {numeros}")
    print(f"Particiones: {ordenador.particiones}")

#Punto de Entrada
if __name__ == "__main__":
    main()