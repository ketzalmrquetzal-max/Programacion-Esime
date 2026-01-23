"""
Programa: Hola Mundo con POO
Demuestra clase básica con encapsulación
"""

from core.saludo import Saludo

if __name__ == "__main__":
    s = Saludo()
    s.mostrar()
    print(s.saludar_persona("Hugo"))
