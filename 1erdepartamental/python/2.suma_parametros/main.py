"""
Programa: Suma con Parámetros
Demuestra parámetros por defecto y operator overloading
"""

from core.sumador import Sumador

if __name__ == "__main__":
    s1 = Sumador(10, 20)
    print(f"s1: {s1}")
    print(f"Suma: {s1.sumar()}\n")

    s2 = Sumador(5, 15)
    s3 = s1 + s2
    print(f"s1 + s2 = {s3}")
