"""
Programa: Promedio con Arreglo
Demuestra estadísticas con arreglo dinámico
"""
#Importa la clase 
from core.estadisticas import EstadisticasArreglo
#Punto de entrada del programa
if __name__ == "__main__":
    e = EstadisticasArreglo([10, 25, 5, 30, 15])

    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}\n")

    e.agregar(50)
    print(f"Después de agregar 50:")
    print(f"Promedio: {e.promedio()}")
