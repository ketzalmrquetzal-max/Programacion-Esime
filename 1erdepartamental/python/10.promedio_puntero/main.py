"""
Programa: Promedio con Puntero
Demuestra simulación de punteros con iterador encapsulado
"""
#Clase Principal
from core.estadisticas import EstadisticasPuntero
#Funcion Principal
def main ():
    e = EstadisticasPuntero([95, 25, 5, 100, 5])

    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}")

#Punto de Entrada
if __name__ == "__main__":
    main()