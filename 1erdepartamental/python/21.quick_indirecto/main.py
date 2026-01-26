"""
Programa: Quick Indirecto
Demuestra quick sort sin modificar el arreglo original
"""
# Importa la clase 
from core.ordenador import OrdenadorIndirectoQuick
#Punto de entrada 
if __name__ == "__main__":
    numeros = [64, 14, 25, 43, 22, 11, 90]

    ordenador = OrdenadorIndirectoQuick(numeros)

    print(f"Original: {ordenador.mostrar_original()}")
    ordenador.ordenar()
    print(f"Ordenado (mediante índices): {ordenador.mostrar_ordenado()}")
    print(f"Original (sin cambios): {ordenador.mostrar_original()}")
