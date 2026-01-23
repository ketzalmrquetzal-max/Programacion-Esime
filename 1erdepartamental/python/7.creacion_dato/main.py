"""
Programa: Creación de Datos
Demuestra tipos de datos personalizados con __str__
"""
#Importe de clases 
from core.tipos import Persona, Auto
#Punto de Entrada
if __name__ == "__main__":
    p = Persona("Hugo", "Dominguez", 19)
    print(p)

    a = Auto("Honda", "Civic", 350000)
    print(a)
