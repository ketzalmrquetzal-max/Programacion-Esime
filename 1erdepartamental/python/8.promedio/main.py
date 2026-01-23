"""
Programa: Promedio
Demuestra estadísticas con parámetros fijos
"""

from core.estadisticas import Estadisticas

if __name__ == "__main__":
    e = Estadisticas(10, 25, 5, 30, 15)

    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}")
