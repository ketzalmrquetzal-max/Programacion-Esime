"""
Programa: Promedio
Demuestra estadísticas con parámetros fijos
"""
#clase principal
from core.estadisticas import Estadisticas

#funcion principal 
def main ():
    e = Estadisticas(10, 25, 5, 30, 15)

    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}")
 
#Funcion que inicia todo el codigo
if __name__ == "__main__":
    main ()
