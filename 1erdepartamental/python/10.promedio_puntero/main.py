"""
Programa: Promedio con Puntero
Demuestra simulación de punteros con iterador encapsulado
"""

from core.estadisticas import EstadisticasPuntero

if __name__ == "__main__":
    e = EstadisticasPuntero([10, 25, 5, 30, 15])

    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}")
